#ifndef STR2_H
#define STR2_H

#include <iostream>

class String
{
    public:
        String (); // Default constructor
        String(const char s[]); // Construction from a character array
        ~String();
        String& operator=(const String& other); // assignment operator
        String(const String& other); //copy constructor
        String(String&& other); // move copy constructor
        String& operator=(String&& other); // move assignment operator
        String substr(int start, int length) const;
        void display() const;
        // ... 
    private:
        char* buffer;
        int len;
        
};

std::ostream& operator<<(std::ostream&, String s);
void repeat(const String& s, int count);

#endif