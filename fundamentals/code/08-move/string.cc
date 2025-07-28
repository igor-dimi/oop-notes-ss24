#include "string.h"
#include <cstring>

String::String()
{
    buffer = nullptr;
    len = 0;
}

String::String(char const s[])
{
    buffer = nullptr;
    len = std::strlen(s);
    if (len > 0) {
        buffer = new char[len];
        for (int i = 0 ; i < len; i++) buffer[i] = s[i];
    }
}

String& String::operator=(String const& other)
{
    if (&other != this) {
        delete[] buffer;
        buffer = nullptr;
        len = other.len;
        if (len > 0) {
            buffer = new char[len];
            for (int i = 0; i < len; i++) buffer[i] = other.buffer[i];
        }
    }
    return *this;
}

String::String(String const& other)
{
    buffer = nullptr;
    len = other.len;
    if (len > 0) {
        buffer = new char[len];
        for (int i = 0; i < len; i++) buffer[i] = other.buffer[i];
    }
}

String::~String() {delete[] buffer;}

String String::substr(int start, int length) const
{
    String res;
    if (length > 0) {
        if (length > len - start) length = len - start;
        res.len = length;
        res.buffer = new char[length];
        for (int i = 0; i < length; i++)
            res.buffer[i] = buffer[start + i];
    }
    return res;
}

String::String(String&& other) : len{other.len}, buffer{other.buffer}
{
    other.buffer = nullptr;
    other.len = 0;
}

String& String::operator=(String&& other)
{
    delete[] buffer;
    len = other.len;
    buffer = other.buffer;
    other.buffer = nullptr;
    return *this;
}

void String::print(std::ostream& out) const
{
    for (int i = 0; i < len; i++) out << buffer[i];
}

std::ostream& operator<<(std::ostream& out, String const& str)
{
    str.print(out);
    return out;
}