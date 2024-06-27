#include "string.h"
#include <vector>
#include <string>
#include <utility>


void foo(std::string&& rv)
{
    rv = "no way";
    return ;
}
std::string bar(void)
{
    return "hello";
}

void f(int& a)
{
    a = 5;
}

void g(std::string str) {;}



int main(int argc, char const *argv[])
{
    String s1("Ann");
    String s2("Fred");
    s1 = s2;
    String s3 = s1;
    String s4 = s1.substr(1,10);


    std::cout << s1 << std::endl;
    std::cout << s4 << std::endl;

    String s5 = std::move(s1);
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    
    int x{23};
    int y = std::move(x);
    
    std::cout << "y: " << y << std::endl;
    std::cout << "x: " << x << std::endl;

    int z = y;
    std::cout << "z: " << z << std::endl;


    {
        std::vector<String> vec;
        String s{"hey"};
        vec.push_back(std::move(s));
        for (auto el : vec) std::cout << el << " ";
        std::cout << std::endl;
        std::cout << "s: " << s << std::endl;

    }

    {
        const String s("hello world!");
        String s2 = std::move(s);
        std::cout << "s2: " << s2 << std::endl;
        std::cout << "s: " << s << std::endl;
    

    }
    {
        String s("good-bye world!");
        String s2 = std::move(s);
        std::cout << "s2: " << s2 << std::endl;
        std::cout << "s: " << s << std::endl;
    }

    {

        using namespace std;
        cout << endl << "block 1" << endl;
        String s{"hello"};
        cout << "s: " << s << endl;
        String&& r1{move(s)};
        cout << "s: " << s << endl;
        cout << "r1: " << r1 << endl;
        String s2{move(s)};
        cout << "s: " << s << endl;
        cout << "s2: " << s2 << endl;
        String&& r2{move(s2)};
        String s3(r2);
        cout << "s2: " << s2 << endl;
        cout << "s3: " << s3 << endl;
    }

    {
        using namespace std;
        {
           cout << endl << "block 2" << endl; 

           string s1{"hello"};
           cout << s1 << endl;

           string&& r1{move(s1)};
           string s2{r1};
           cout << "s1: " << s1 << endl;
           cout << "s2: " << s2 << endl;

           string s3{move(s1)};
           cout << "s1: " << s1 << endl;
           cout << "s2: " << s2 << endl;


        } // namespace std;
    }

    {
        using namespace std;
        {
           cout << endl << "block 3" << endl; 

           string s{"hello"};
           string&& r1 = move(s);
           string s2(move(s));
           cout << "s2: " << s2 << endl;
           cout << "s: " << s << endl;
           r1 = "good";
           cout << "s: " << s << endl;
        } // namespace std:
    }

    {
        using namespace std;
        cout << endl << "block 4" << endl; 

        foo("hello");
        string s{"hello"};
        string&& ref = move(s);
        // foo(s);
        foo(move(s));
        foo(bar());
        // foo(ref); this also doesn't work for some reason

        cout << s << endl;

    }

    {
        using namespace std;
        cout << endl << "block 5" << endl;
        int a = 3;
        f(a);
        cout << "a: " << a << endl;
        string s = "there";
        g("hey");
        g(s);
        g(move(s));
        cout << "s: " << s << endl;        
        g(bar());
        string&& ref = move(s);
        string&& ref2 = "there";
        string&& r3 = bar();



    }



    return 0;
}
