

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

class HTTP : public HTTPInterface
{
    public: 
        HTTP() = default;

        std::string get(
                const char *const	peer,
                int port,
                const char *const	request
        ) override {
            std::ostringstream ss;
            ss << peer << ":" << port << request;

            CURL *curl;
            CURLcode res;
            std::string readBuffer;

            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

                curl_easy_setopt(curl, CURLOPT_URL, ss.str().c_str());
                
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
            }

            return readBuffer;
        }

        //https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
        {
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        }

        std::string getHTTPS(
                const char *const peer,
                const int port,
                const char *const fingerprint,
                const char *const request
        ) override {	
            std::ostringstream ss;
            ss << "https://" << peer << ":" << port << request;

            CURL *curl;
            CURLcode res;
            std::string readBuffer;

            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

                curl_easy_setopt(curl, CURLOPT_URL, ss.str().c_str());
                // curl_easy_setopt(curl, CURLOPT_SSLKEY, fingerprint);
                
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
            }
            return readBuffer;
        } // needs real HTTPS (fingerprint/cert-checking) implemented
};

}

// HTTP object factory
std::unique_ptr<HTTPInterface> makeHTTP() {
    return std::unique_ptr<HTTPInterface>(new HTTP());
}

}
}
}

#endif

