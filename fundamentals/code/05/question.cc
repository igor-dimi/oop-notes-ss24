#include "question.hh"
#include <iostream>

Question::Question() {}
void Question::set_question(std::string _question)
{
    question = _question;
}
void Question::set_answer(std::string _answer) {answer = _answer;}
bool Question::check_response(std::string response) const
{
    return response == answer;
}
void Question::display() const
{
    std::cout << question << std::endl;
}

