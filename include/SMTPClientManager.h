#ifndef SMTPCLIENTMANAGER_H
#define SMTPCLIENTMANAGER_H

#include <ESP_Mail_Client.h>
#include "EmailMessage.h"

class SMTPClientManager
{
public:
    SMTPClientManager();
    void setCredentials(const char *host, int port, const char *email, const char *password);
    static void smtpCallback(SMTP_Status status);
    bool sendEmail(EmailMessage &message);

private:
    SMTPSession smtp;
    Session_Config config;

    void sendingResult();
};

#endif // SMTPCLIENTMANAGER_H
