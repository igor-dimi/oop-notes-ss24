#include "string.hh"
#include <string.h>

String::String(const char s[])
{
    len = strlen(s);
    if (len > 0) {
        buffer = new char[len];
        for (int i = 0; i < len; i++) buffer[i] = s[i];
    }
    else buffer = nullptr;
}

String::String()
{
    buffer = nullptr;
    len = 0;
}

String::~String()
{
    delete[] buffer;
}

String& String::operator=(const String& other)
{
    if (this != &other) {
        delete[] buffer;
        len = other.len;
        if(len > 0) {
            buffer = new char[len];
            for (int i = 0; i < len; i++) buffer[i] = other.buffer[i];
        }
        else buffer = nullptr;
    }
    return *this;
}
