#include "question.hh"
#include <string>
#include <iostream>

Question::Question() {}
Question::Question(std::string _question) {question = _question;}
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


ChoiceQuestion::ChoiceQuestion() {};
ChoiceQuestion::ChoiceQuestion(std::string question) : 
    Question(question) {};

void ChoiceQuestion::add_choice(
    std::string choice,
    bool correct)
{
    choices.push_back(choice);
    if(correct)
    {
        // Convert choices.size() to string
        std::string num_str = std::to_string(choices.size());
        // Set num_str as the answer
        set_answer(num_str);
    }
}

void ChoiceQuestion::display() const
{
    // Display the question text
    Question::display();
    // Display the answer choices
    for (int i = 0; i < choices.size(); i++) {
        std::cout << i + 1 << ": " << choices[i] << std::endl;
    }
}