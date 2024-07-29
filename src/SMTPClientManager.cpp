#include "SMTPClientManager.h"
#include "EmailMessage.h"

SMTPClientManager::SMTPClientManager()
{
    smtp.debug(1);
    smtp.callback(SMTPClientManager::smtpCallback);
    ESP_MAIL_DEFAULT_FLASH_FS.begin();
}

void SMTPClientManager::setCredentials(const char *host, int port, const char *email, const char *password)
{
    config.server.host_name = host;
    config.server.port = port;
    config.login.email = email;
    config.login.password = password;
    config.login.user_domain = "client domain or public ip";
    config.time.ntp_server = F("pool.ntp.org,time.nist.gov");
    config.time.gmt_offset = 3;
    config.time.day_light_offset = 0;
}

bool SMTPClientManager::sendEmail(EmailMessage &message)
{
    if (!smtp.connect(&config))
    {
        Serial.printf("Connection error, Status Code: %d, Error Code: %d, Reason: %s", smtp.statusCode(), smtp.errorCode(), smtp.errorReason().c_str());
        return false;
    }

    if (!smtp.isLoggedIn())
    {
        Serial.println("\nNot yet logged in.");
        return false;
    }

    if (smtp.isAuthenticated())
    {
        Serial.println("\nSuccessfully logged in.");
    }
    else
    {
        Serial.println("\nConnected with no Auth.");
        return false;
    }

    if (!MailClient.sendMail(&smtp, &message.getSMTPMessage(), true))
    {
        Serial.println("Error sending Email, " + smtp.errorReason());
        return false;
    }

    sendingResult();
    return true;
}

void SMTPClientManager::smtpCallback(SMTP_Status status)
{
    Serial.println(status.info());

    if (status.success())
    {
        Serial.println("----------------");
        ESP_MAIL_PRINTF("Message sent success: %d\n", status.completedCount());
        ESP_MAIL_PRINTF("Message sent failed: %d\n", status.failedCount());
        Serial.println("----------------\n");
    }
}

void SMTPClientManager::sendingResult()
{
    Serial.println("----------------");

    for (size_t i = 0; i < smtp.sendingResult.size(); i++)
    {
        SMTP_Result result = smtp.sendingResult.getItem(i);

        ESP_MAIL_PRINTF("Message No: %d\n", i + 1);
        ESP_MAIL_PRINTF("Status: %s\n", result.completed ? "success" : "failed");
        ESP_MAIL_PRINTF("Date/Time: %s\n", MailClient.Time.getDateTimeString(result.timestamp, "%B %d, %Y %H:%M:%S").c_str());
        ESP_MAIL_PRINTF("Recipient: %s\n", result.recipients.c_str());
        ESP_MAIL_PRINTF("Subject: %s\n", result.subject.c_str());
    }
    Serial.println("----------------\n");

    smtp.sendingResult.clear();
}