#include <iostream>
#include <string>
#include <vector>
// #include <conio.h> 
#include <stdio.h>

class MenuItem
{
    std::string title;
    int id;

    public:
        MenuItem(const std::string& title, int id) : title(title), id(id) {}
        std::string get_title() { return title; }
        void command()
        {
            std::cout << get_title() << " menu is selected." << std::endl;
            getchar();
        }
};

int main()
{
    MenuItem m1("Roll", 11);
    MenuItem m2("Ramen", 12);

    m1.command();

}




