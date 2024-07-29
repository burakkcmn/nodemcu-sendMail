# ESP32/ESP8266 Email Sending Project

This project demonstrates how to send emails using an ESP32 or ESP8266 with the ESP-Mail-Client library. It allows sending emails with attachments and custom SMTP settings. The project is built using PlatformIO.

## Project Structure
```
├── data
│ ├── image.png
│ ├── test_file.txt
├── include
│ ├── WiFiHandler.h
│ ├── EmailMessage.h
│ └── SMTPClientManager.h
├── src
│ ├── WiFiHandler.cpp
│ ├── EmailMessage.cpp
│ ├── SMTPClientManager.cpp
│ └── main.cpp
├── platformio.ini
└── README.md
```

## Prerequisites
- Platformio with ESP8266 board support.
- Libraries:
    - ESP Mail Client
    - ESP8266WiFi

## Installation

1. Clone the repository:
```sh
git clone https://github.com/yourusername/ESP8266-DC-Motor-Control.git
cd ESP8266-DC-Motor-Control
```
2. Open the project in Platformio.
3. Install required libraries:
    - ESPAsyncWebServer
    - LittleFS
4. Upload the code to your ESP8266:
    - Ensure the correct board and port are selected in the Platformio.
    - Upload the code to the ESP8266.


## Configuration

Configure the WiFi credentials and email settings in the `main.cpp` file.

```cpp
#define WIFI_SSID "REPLACE_WITH_YOUR_SSID"
#define WIFI_PASSWORD "REPLACE_WITH_YOUR_PASSWORD"

#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "YOUR_EMAIL@XXXX.com"
#define AUTHOR_PASSWORD "YOUR_EMAIL_APP_PASS"
#define RECIPIENT_EMAIL "RECIPIENT_EMAIL@XXXX.com"
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project is based on tutorials by Rui Santos & Sara Santos - [Random Nerd Tutorials](https://RandomNerdTutorials.com/)