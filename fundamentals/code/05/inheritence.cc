#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct Foo {
    int f;
    Foo() : f(0) {};
    Foo(int _f) : f(_f) {};
    
};

struct Bar {
    int b;
    Bar() : b(0) {};
    Bar(int _b) : b(_b) {};
};

struct FooBar : Foo, Bar {
    int fb;
    FooBar(int a, int b, int c) : Foo(a), Bar(b), fb(c) {
        std::cout << "f: " << Foo::f << std::endl;;
        std::cout << "b: " << b << std::endl;;
    }
};

struct Base {
    virtual void foo() const {std::cout << "Base" << std::endl;}
};

struct Derived : public Base 
{
    void foo() const override {Base::foo(); std::cout << "Derived" << std::endl;} ;
    void bar() const {std::cout << "Derived bar " << std::endl;}
    static void zim() {std::cout << "Derived zim" << std::endl;}
};


class Question
{
    public :
        Question() {};
        void set_question(std::string _question){question = _question;}
        void set_answer(std::string _answer) {answer = _answer;}
        bool check(std::string response) const {return response == answer;}
        virtual void display() const;
    private :
        std::string question;
        std::string answer;
};

void Question::display() const
{
    std::cout << question << std::endl;
}

class ChoiceQuestion : public Question
{
    public:
        // ChoiceQuestion();
        void add_choice(std::string, bool correct);
        virtual void display() const override;
    private:
        std::vector<std::string> choices;        

};

void ChoiceQuestion::add_choice(std::string choice, bool correct) 
{
    choices.push_back(choice);
    if(correct) {
        std::string num_str = std::to_string(choices.size());
        set_answer(num_str);
    }
}

void ChoiceQuestion::display() const
{
    Question::display();
    for (int i = 0; i < choices.size(); i++) 
        std::cout << i + 1 << ": " << choices[i] << std::endl;
}


// Abstract base classes
struct ABC {
    virtual void foo() = 0; // pure virtual: no definition provided

    virtual ~ABC() = default; // virtual destructor
};

struct FooImplementation : public ABC {
    void foo() override {std::cout << "implementation" << std::endl;}
};

int main(int argc, char const *argv[])
{
    Foo x;
    std::cout << x.f << std::endl;
    FooBar fb(1, 2, 3);

    std::string response;
    std::cout << std::boolalpha;

    Question q1;
    q1.set_question("capital of DE?");
    q1.set_answer("Berlin");

    q1.display();
    // std::cout << "Your answer: ";
    // getline(std::cin, response);
    // std::cout << q1.check(response) << std::endl;

    ChoiceQuestion cq1;
    cq1.set_question("capital of DE?");
    cq1.add_choice("Moscow", false);
    cq1.add_choice("Berlin", true);
    cq1.add_choice("Sydney", false);

    cq1.display();
    // std::cout << "answer: ";
    // getline(std::cin, response);
    // std::cout << cq1.check(response) << std::endl;
    
    Question quiz[2];
    quiz[0] = q1;
    quiz[1] = cq1;

    for (int i = 0; i < 2; i++){
        quiz[i].display();
    }

    Question* quiz2[2];
    Question* qp1 = &q1;
    Question* qp2 = &cq1;
    quiz2[0] = qp1;
    quiz2[1] = qp2;

    std::cout << std::endl << "with pointers: " << std::endl;

    for (int i = 0; i < 2; i++){
        quiz2[i]->display();
    }

    Question q3 = cq1;
    q3.display();
    ChoiceQuestion cq2(cq1);
    cq2.display();

    Base b1;
    b1.foo();
    Derived d1;
    d1.foo();

    Base& br = d1;

    std::cout << "base reference: " << std::endl;
    br.foo();


    std::cout << "slicing: " << std::endl;
    Base b2 = d1;
    b2.foo();

    std::cout << "with pointers no slicing: " << std::endl;
    Base* bp = &d1;
    bp->foo();

    std::cout << "Base().foo(): " << std::endl;
    Base().foo();

    Base& br2 = d1;
    d1.bar();
    // br2.bar();
    Derived::zim();

    br2.foo();

    Derived d3 = d1;

    FooImplementation fmp;
    fmp.foo();

    




    return 0;
}


