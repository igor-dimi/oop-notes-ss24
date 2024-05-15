#include <string>
#include <vector>

class Question
{
    public:
        Question();
        void set_question(std::string question);
        void set_answer(std::string answer);
        bool check_response(std::string response) const;
        void display() const;
    private : 
        std::string question;
        std::string answer;
};

class ChoiceQuestion : public Question
{
    public :
        ChoiceQuestion();
        void add_choice(std::string choice, bool correct);
        void display() const;
    private :
        std::vector<std::string> choices;
};

