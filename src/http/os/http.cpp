

#include "utils/helpers.h"
#include "http/http.h"

#ifndef USE_IOT

#include <curl/curl.h>
#include <cstring>
#include <sstream>
#include <iostream>

namespace Ark {
namespace Utilities {
namespace Network {
namespace {

class PlatformHTTP : public AbstractHTTP
{
    public: 
        PlatformHTTP() = default;

        std::string get(
                const char *const	peer,
                int port,
                const char *const	endpoint
        ) override {
            std::ostringstream ss;
            ss << peer << ":" << port << endpoint;

            CURL *curl;
            CURLcode res;
            std::string readBuffer;

            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, ss.str().c_str());
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
            }
            return readBuffer;
        }

        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
        {
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }

        std::string getHTTPS(
                const char *const peer,
                const int port,
                const char *const fingerprint,
                const char *const endpoint
        ) override {	
            std::ostringstream ss;
            ss << "https://" << peer << ":" << port << endpoint;

            // https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html

            CURL *curl;
            CURLcode res;
            std::string readBuffer;

            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, ss.str().c_str());
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
            }
            return readBuffer;
        } // needs HTTPS thumbprint/cert verification

        std::string post(
                const char *const peer,
                int port,
                const char *const endpoint,
                const char *bodyParameters
        ) override {
            std::ostringstream ss;
            ss << "https://" << peer << ":" << port << endpoint;

            // https://curl.haxx.se/libcurl/c/http-post.html

            CURL *curl;
            CURLcode res;
            std::string readBuffer;

            curl_global_init(CURL_GLOBAL_ALL);
            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, ss.str().c_str()); // Set the URL that is about to receive our POST
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodyParameters); // Now specify the POST data ex: "username=baldninja"
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
                res = curl_easy_perform(curl); // Perform the request, res will get the return code 
                if(res != CURLE_OK) { // Check for errors
                    fprintf(
                        stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res)
                    );
                }
                curl_easy_cleanup(curl); /* always cleanup */ 
            }
            curl_global_cleanup();
            return readBuffer;
        };
        
        std::string postHTTPS(
                const char *const peer,
                int port,
                const char *const endpoint,
                const char *const fingerprint,
                const char *bodyParameters
        ) override {
            return post(peer, port, endpoint, bodyParameters);
        };
};

}

// HTTP object factory
std::unique_ptr<AbstractHTTP> makeHTTP() {
    return std::unique_ptr<AbstractHTTP>(new PlatformHTTP());
}

}
}
}

#endif

