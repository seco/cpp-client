


#include "http/http.h"
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

/*************************************************
*
**************************************************/
class PlatformHTTP : public AbstractHTTP
{
    public:
        /*************************************************
        *
        **************************************************/
        PlatformHTTP() = default;
        /*************************************************/

        /*************************************************
        *
        **************************************************/
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
        /*************************************************/

        /*************************************************
        *
        **************************************************/
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
                if (count >=2)
                {	Serial.println("\nBad connection. Try another peer..\n");
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
        /*************************************************/

        /*************************************************
        *
        **************************************************/
        std::string get(
                const char *const peer,
                const int port,
                const char *const request
        ) {
            HTTPClient http;
            http.setReuse(true);
            http.setTimeout(3000);
            if (int code = tryConnection(http, peer, port, request) != 200)
            {   // error
                return http.errorToString(-code).c_str(); // <- note `-` symbol.
            }
            return http.getString().c_str();
        }
        /*************************************************/

        /**************************************************************************************************/

        /*************************************************
        *
        **************************************************/
        int tryHTTPSConnection(
                WiFiClientSecure &client,
                const char *const peer,
                int port,
                const char *const fingerprint,
                const char *const request
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
                + "User-Agent: cpp-client-v0.5\r\n"
                + "Connection: close\r\n\r\n"
            );

            while (client.connected())
            {
                if (client.readStringUntil('\n') == "\r") { break; }
            }
            if (client.peek() != '{') { client.readStringUntil('\n'); };
            return 200;
        };

        /*************************************************
        *
        **************************************************/
        std::string getHTTPS(
                const char *const peer,
                const int port,
                const char *const fingerprint,
                const char *const request
        ) {
            WiFiClientSecure client;
            std::make_shared<WiFiClientSecure>(client);
            if (tryHTTPSConnection(client, peer, port, fingerprint, request) != 200)
            {   // error
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
        }
        /*************************************************/
};

}

/*************************************************
*		HTTP object factory
**************************************************/
std::unique_ptr<AbstractHTTP> makeHTTP() {
    return std::unique_ptr<AbstractHTTP>(new PlatformHTTP());
}
/*************************************************/

}
}
}

// #endif
