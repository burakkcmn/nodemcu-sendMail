#include <Arduino.h>
#include "WiFiHandler.h"
#include "SMTPClientManager.h"
#include "EmailMessage.h"

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFiHandler::connectToWiFi("REPLACE_WITH_YOUR_SSID", "REPLACE_WITH_YOUR_PASSWORD");

  SMTPClientManager smtpClient;
  smtpClient.setCredentials("smtp.gmail.com", 465, "YOUR_EMAIL@XXXX.com", "YOUR_EMAIL_APP_PASS");

  EmailMessage message;
    message.setSender("ESP Mail", "YOUR_EMAIL@XXXX.com");
    message.setRecipient("Burak", "RECIPIENT_EMAIL@XXXX.com");
  message.setSubject("Test sending Email with attachments and inline images from Flash");
  message.setBody("This message contains attachments: image and text file.");

  message.addAttachment("image.png", "/", "image/png", esp_mail_file_storage_type_flash);
  message.addAttachment("text_file.txt", "/", "text/plain", esp_mail_file_storage_type_flash);

  smtpClient.sendEmail(message);
}

void loop()
{
  // Nothing to do here
}
