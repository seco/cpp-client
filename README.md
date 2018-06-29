# ARK Cpp - Client

<p align="center">
  <img src="https://github.com/sleepdefic1t/cpp-client/blob/master/ark_cpp_client.png"/>
</p>

> A simple Cpp/C++ API client for the ARK Blockchain.

v0.5

#### Arduino Example using the Adafruit Feather ESP8266

```cpp

#include <arkClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "your_network";
const char* password = "your_password";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.print("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());

 ARK::Client arkClient(DEVNET);

  Serial.println(arkClient.blocks().c_str());
  Serial.println();
  
  Serial.println(arkClient.delegates().c_str());
  Serial.println();
  
  Serial.println(arkClient.delegatesCount().c_str());
  Serial.println();
  
  Serial.println(arkClient.peers().c_str());
  Serial.println();
  
  Serial.println(arkClient.transactions().c_str());
  Serial.println();

}

void loop() {}

```
