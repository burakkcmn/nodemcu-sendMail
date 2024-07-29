#include "EmailMessage.h"

EmailMessage::EmailMessage()
{
    message.enable.chunking = true;
    message.html.charSet = "utf-8";
    message.html.transfer_encoding = Content_Transfer_Encoding::enc_qp;
    message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_normal;
    message.response.notify = esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;
}

void EmailMessage::setSender(const char *name, const char *email)
{
    message.sender.name = name;
    message.sender.email = email;
}

void EmailMessage::setRecipient(const char *name, const char *email)
{
    message.addRecipient(name, email);
}

void EmailMessage::setSubject(const char *subject)
{
    message.subject = subject;
}

void EmailMessage::setBody(const char *body)
{
    message.html.content = body;
}

void EmailMessage::addAttachment(const char *fileName, const char *path, const char *mime, esp_mail_file_storage_type storageType)
{
    SMTP_Attachment att;
    att.descr.filename = fileName;
    att.descr.mime = mime;
    char buffer[sizeof(fileName) + sizeof(path)];
    strncpy(buffer, path, sizeof(buffer));
    strncat(buffer, fileName, sizeof(buffer));
    att.file.path = buffer;
    att.file.storage_type = storageType;
    att.descr.transfer_encoding = Content_Transfer_Encoding::enc_base64;
    message.addAttachment(att);
}

SMTP_Message &EmailMessage::getSMTPMessage()
{
    return message;
}
