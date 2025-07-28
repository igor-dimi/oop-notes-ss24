#ifndef STR_H
#define STR_H
#include <iostream>

class String
{
    public :
        String(); //default constructor
        String (char const s[]); //construction from character array
        String(String const&); //copy constructor
        ~String();
        String& operator=(String const&);
        String substr(int, int) const;
        String(String&& other);
        String& operator=(String&& other);
        void print(std::ostream& out) const;

    private : 
        char* buffer;
        int len;
};

std::ostream& operator<<(std::ostream& out, String const& str);

#endif // !STR_H