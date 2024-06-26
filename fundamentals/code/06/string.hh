#ifndef STR_H
#define STR_H

class String
{
    public:
        String(); //Default Constructor
        String(const char s[]); //construction from a character array
        ~String();
        String& operator=(const String& other);
        String(const String& other);
        String substring(int start, int length) const;
        String(String&& other);
        String& String::operator=(String&& other);
        // ...
    private:
        char* buffer;
        int len;
};

#endif // !STR_H