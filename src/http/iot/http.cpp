


#include "http/http.h"
#include "helpers/helpers.h"
#include <memory>
#include <vector>

#ifdef ESP8266
    #include <ESP8266HTTPClient.h>
#else
    #include <HTTPClient.h>
#endif

#if (defined ESP32 || defined ESP8266)
    #include <WiFiClientSecure.h>
#endif

namespace Ark {
namespace Utilities {
namespace Network {
namespace {

/**
*
**/
class PlatformHTTP : public AbstractHTTP
{
    public:
        PlatformHTTP() = default;

        /**/

        void printConnection(
                const char *const peer,
                const int port,
                const char *const request
        ) {
            Serial.print("\nOpening HTTP(S) connection to:\n");
            Serial.print(peer); Serial.print(":");
            Serial.print(port);
            Serial.println(request);
        };

        /**/

        int tryConnection(
                HTTPClient &client,
                const char *const peer,
                int port,
                const char *const request
        ) {
            printConnection(peer, port, request);
            if (!client.begin(peer, port, request))
            {   // error
                Serial.println("\nBad HTTP begin..");
            }
            int code = client.GET();
            int count = 0;
            while (code != HTTP_CODE_OK)
            {   //error
                client.end();
                if (count >=2) {
                    Serial.println("\nBad connection. Try another peer..\n");
                    return code;
                };
                Serial.println("\nBad HTTP GET.\nRetrying connection..");
                delay(1000);
                client.begin(peer, port, request);
                code = client.GET();
                count++;
            };
            return code;
        };

        /**/

        int tryHTTPSConnection(
                WiFiClientSecure &client,
                const char *const peer,
                int port,
                const char *const request,
                const char *const fingerprint
        ) {
            printConnection(peer, port, request);

            auto connected = client.connect(peer, port);
            size_t count = 0;
            while (!connected)
            { Serial.println("\nconnection failed...");
            if (count >=3) { return -1; };
                delay(500);
                Serial.println("\ntrying host again.");
                connected = client.connect(peer, port);
                count++;
            }

            if (!client.verify(fingerprint, peer)) { return -1; }

            client.print(
                String("GET ")
                + request
                + " HTTP/1.1\r\n"
                + "Host: " + peer + "\r\n"
                + "User-Agent: cpp-client-v0.9.5\r\n"
                + "Connection: close\r\n\r\n"
            );

            while (client.connected())
            {
                if (client.readStringUntil('\n') == "\r") { break; }
            }
            if (client.peek() != '{') { client.readStringUntil('\n'); };
            return 200;
        };

        /**/

        std::string get(
                const char *const peer,
                const int port,
                const char *const request,
                const char *const fingerprint
        ) override {
            if (fingerprint != nullptr) {

                /* HTTPS */
                WiFiClientSecure client;
                std::make_shared<WiFiClientSecure>(client);
                if (tryHTTPSConnection(client, peer, port, request, fingerprint) != 200) {
                    // error
                    return "-1";
                }

                std::string response;
                std::make_shared<std::string>(response);
                while (client.available())
                {
                    char c = client.read();
                    if (c != '\n') { response += c; };
                };
                client.stop();
                return response;

            } else {

                HTTPClient http;
                http.setReuse(false);
                http.setTimeout(3000);
                if (int code = tryConnection(http, peer, port, request) != 200) {
                    // error
                    return http.errorToString(-code).c_str(); // <- note `-` symbol.
                }
                return http.getString().c_str();

            };
        }

        /**/

        std::string post(
                const char *const peer,
                int port,
                const char *const endpoint,
                const char *bodyParameters,
                const char *const fingerprint
        ) override {
            printConnection(peer, port, endpoint);

            if (fingerprint != nullptr) {

                WiFiClientSecure client;
                if (client.connect(peer, port)) {
                    client.print("POST ");
                    client.print(endpoint);
                    client.println(" HTTP/1.1");
                    client.print("Host: ");
                    client.println(peer);
                    client.println("User-Agent: cpp-client-v0.9.5");
                    client.println("Connection: close");
                    client.println("Content-Type: application/x-www-form-urlencoded;");
                    client.print("Content-Length: ");
                    client.println(strlen(bodyParameters));
                    client.println();
                    client.println(bodyParameters);
                    String response = client.readString();
                    int bodypos =  response.indexOf("\r\n\r\n") + 4;
                    return response.substring(bodypos).c_str();
                } else {
                  return "ERROR";
                };

            } else {

                HTTPClient http;
                http.setReuse(true);
                http.setTimeout(3000);
                http.begin(peer, port, endpoint);

                http.addHeader("Content-Type", "application/x-www-form-urlencoded");
                http.POST(bodyParameters);
                return http.getString().c_str();

            };
        }
        /**/
};
/**/
}

/**
 * HTTP object factory
 **/
std::unique_ptr<AbstractHTTP> makeHTTP() {
    return std::unique_ptr<AbstractHTTP>(new PlatformHTTP());
}
/**/
};
};
};
