#include <iostream>
#include <string>
#include <vector>

/**
 * A menu that is displayed on a console
*/
class Menu
{
    public :
        /**
         * constructs empty menu
        */
        // Menu();

        /**
         * Adds an option to the end of this menu
         * @param option the option to add
        */
        void add_option(std::string option);

        /**
         * displays menu, prompts user for input until 
         * valid option supplied. 
         * @return option number user supplied. 
        */
        int get_input() const;
    private :
        std::vector<std::string> options;
        void display() const;
};

void Menu::add_option(std::string option) {options.push_back(option);}
int Menu::get_input() const
{
    int input = 0;
    do {
        display();
        std::cin >> input;
        if (input < 1 || input > options.size())
            std::cout << "error: invalid menu option!" << std::endl
                                                       << std::endl;
    } while (input < 1 || input > options.size());
    return input;
}

void Menu::display() const
{
    for (int i = 0; i < options.size(); i++)
        std::cout << i + 1 << ") " << options[i] << std::endl;
}

int main(int argc, char const *argv[])
{
    Menu main_menu;
    main_menu.add_option("Open new account");
    main_menu.add_option("Log into existing account");
    main_menu.add_option("Help");
    main_menu.add_option("Quit");
    int input = main_menu.get_input();
    std::cout << "Input: " << input << std::endl;
    return 0;
}
