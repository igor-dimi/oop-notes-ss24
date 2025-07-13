#include "string2.hh"
#include <cstring>
#include <iostream>

String::String(const char s[])
{
    len = std::strlen(s);
    if (len > 0) {
        buffer = new char[len];
        for (int i = 0; i < len; i++)
            buffer[i] = s[i];
    } 
    else buffer = nullptr;
}

String::String()
{
    len = 0;
    buffer = nullptr;
}

String::~String() {delete[] buffer;}


String& String::operator=(const String& other)
{
    if (this != &other) {
        delete [] buffer;
        buffer = nullptr;
        len = other.len;
        if (len > 0) { 
            buffer = new char[len];
            for (int i = 0; i < len; i++)
                buffer[i] = other.buffer[i];
        }
    }

    return *this;
}

String::String(const String& other)
{
    buffer = nullptr;
    len = other.len;
    if (len > 0) {
        buffer = new char[len];
        for (int i = 0; i < len; i++)
            buffer[i] = other.buffer[i];
    }
}

String::String(String&& other)
{
    len = other.len;
    buffer = other.buffer;
    other.buffer = nullptr;
}

String& String::operator=(String&& other)
{
    delete[] buffer;
    len = other.len;
    buffer = other.buffer;
    other.buffer = nullptr;
    return *this;
}

std::ostream& operator<<(std::ostream& out, String s)
{
    return out;
}

void String::display() const
{
    for (int i = 0; i < len; i++)
        std::cout << buffer[i];
};

void repeat(const String& s, int count)
{
    for (int i = 0; i < count - 1; i++) {
        s.display();
        std::cout << std::endl;
    }
    s.display();
}

String String::substr(int start, int length) const
{
    start %= len;
    String result;
    if (length > 0) {
        result.len = length;
        if (length > len - start) length = len - start;
        // result.len == max(length, len - start)
        result.buffer= new char[length];
        for (int i = 0; i < length; i++)
        {
            result.buffer[i] = buffer[start + i];
        }
    }
    return result;
}




