#ifndef EMAILMESSAGE_H
#define EMAILMESSAGE_H

#include <ESP_Mail_Client.h>

class EmailMessage
{
public:
    EmailMessage();
    void setSender(const char *name, const char *email);
    void setRecipient(const char *name, const char *email);
    void setSubject(const char *subject);
    void setBody(const char *body);
    void addAttachment(const char *fileName, const char *path, const char *mime, esp_mail_file_storage_type storageType);
    SMTP_Message &getSMTPMessage();

private:
    SMTP_Message message;
};

#endif // EMAILMESSAGE_H
