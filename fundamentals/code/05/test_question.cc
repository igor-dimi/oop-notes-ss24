#include "question.hh"
#include <iostream>

int main(int argc, const char** argv) {
    std::string response;
    std::cout << std::boolalpha; // show boolean values as true, false

    Question q1;
    q1.set_question("Inventor of C++?");
    q1.set_answer("Bjarne Stroustrup");
    q1.display();
    std::getline(std::cin, response);
    std::cout << q1.check_response(response) << std::endl;
    return 0;
}