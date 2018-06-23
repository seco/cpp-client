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
  

  ARK::API::Manager manager(ARK::Constants::Networks::Model::Devnet);


  Serial.println(manager.blocks().c_str()); Serial.println();
  
  Serial.println(manager.delegates().c_str()); Serial.println();
  
  Serial.println(manager.delegatesCount().c_str()); Serial.println();
  
  Serial.println(manager.peers().c_str()); Serial.println();
  
  Serial.println(manager.transactions().c_str());
}

void loop() {}

```