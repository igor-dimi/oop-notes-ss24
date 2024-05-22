#include "question.hh"
#include <iostream>
#include <memory>

int main(int argc, const char** argv) {
    const int N = 2;
    std::string response;
    std::cout << std::boolalpha; // show boolean values as true, false

    Question* quiz[N];
    quiz[0] = new Question;
    quiz[0]->set_question("Inventor of C++?");
    quiz[0]->set_answer("Bjarne Stroustrup");

    ChoiceQuestion* cq1 = new ChoiceQuestion("Where was the inventor of C++ born?");
    cq1->add_choice("Australia", false);
    cq1->add_choice("Denmark", true);
    cq1->add_choice("Russia", false);

    quiz[1] = cq1; //slicing will occur

    for (int i = 0; i < N; i++){
        quiz[i]->display();
        std::cout << "Your answer: ";
        std::getline(std::cin, response);
        std::cout << quiz[i]->check_response(response) << std::endl;
    }
    // Question q1;
    // q1.set_question("Inventor of C++?");
    // q1.set_answer("Bjarne Stroustrup");

    // q1.display();
    // std::cout << "Your answer: ";
    // std::getline(std::cin, response);
    // std::cout << q1.check_response(response) << std::endl;


    // ChoiceQuestion q2;
    // q2.set_question("In which country was the inventor of C++ born?");
    // q2.add_choice("Australia", false);
    // q2.add_choice("Denmark", true);
    // q2.add_choice("Korea", false);
    // q2.add_choice("United States", false);

    // q2.display();
    // std::cout << "Your answer: ";
    // std::getline(std::cin, response);
    // std::cout << q2.check_response(response) << std::endl;

    std::shared_ptr<Question> q1(new Question);
    q1->set_question("Inventor of C++?");
    q1->set_answer("Bjarne Stroustrup");
    q1->display();

    return 0;
}