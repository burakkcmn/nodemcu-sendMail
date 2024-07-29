#ifndef WIFIHANDLER_H
#define WIFIHANDLER_H

#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

class WiFiHandler {
public:
    static void connectToWiFi(const char* ssid, const char* password);
};

#endif // WIFIHANDLER_H
