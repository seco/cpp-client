Import("env")
import os
import shutil

if os.listdir('/include/ArduinoJson') :
shutil.rmtree('/include/ArduinoJson')
