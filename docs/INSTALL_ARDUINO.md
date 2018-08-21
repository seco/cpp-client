

# Arduino Builds


### requirements:

**Arduino IDE:**  
Download and install the Arduino IDE (>=1.8.5) from the following link:  
```https://www.arduino.cc/en/Main/Software```

#

### dependencies:

Using the Arduino IDE's built in Library Manager,  
install the following Libraries  
- ArduinoJson
- micro-ecc
- AUnit

#

### Using with the Arduino IDE
> include the following header in your Arduino Sketch:  
```cpp
#include <arkClient.h>
```

#

### Arduino Example using the Adafruit Feather ESP8266

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