

#include "platform/platform.h"
#include <string>
#include <memory>
#include <vector>

// #if (defined ESP32 || defined ESP8266)
// #if (defined USE_IOT)
#include "utils/http.h"
#include <memory>

#ifdef ESP8266

#include <ESP8266HTTPClient.h>

#else

#include <HTTPClient.h>

#endif

namespace ARK
{
namespace Utilities
{
namespace Network
{
namespace
{
/*************************************************
*
**************************************************/
class HTTP :
		public HTTPInterface
{
	public:
		/*************************************************
		*
		**************************************************/
		HTTP() = default;
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		void printConnection(
				const char *const peer,
				const int port,
				const char *const request
		) {
			Serial.print("\nOpening HTTP connection to:\n");
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
			{	// error
				Serial.println("\nBad HTTP begin..");
			}
			int code = client.GET();	
			int count = 0;
			while (code != HTTP_CODE_OK)
			{	//error
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
			{	// error
				return http.errorToString(-code).c_str(); // <- note `-` symbol.
			}			
			return http.getString().c_str();
		}
		/*************************************************/
};

}

/*************************************************
*		HTTP object factory
**************************************************/
std::unique_ptr<HTTPInterface> makeHTTP() {
	return std::unique_ptr<HTTPInterface>(new HTTP());
}
/*************************************************/

}
}
}

// #endif
