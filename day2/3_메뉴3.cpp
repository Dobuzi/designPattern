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

class PopUpMenu
{
    std::string title;
    int id;
    std::vector<MenuItem*> v;

    public:
        PopUpMenu(const std::string& title, int id) : title(title), id(id) {}
        void add_menu(MenuItem* m) { v.push_back(m); }
        void command()
        {
            while(1)
            {
                system("clear");

                int sz = v.size();

                for (int i = 0; i < sz; i++)
                {
                    std::cout << i + 1 << ": " << v[i]->get_title() << std::endl;
                }

                std::cout << sz + 1 << ": Exit" << std::endl;

                std::cout << "Select the menu" << std::endl;
                int cmd;
                std::cin >> cmd;

                if (cmd < 1 || cmd > sz + 1) continue;
                if (cmd == sz + 1) break;
                v[cmd-1]->command();
            }
        }
};

int main()
{
    MenuItem m1("Roll", 11);
    MenuItem m2("Ramen", 12);

    // m1.command();

    PopUpMenu pm1("Food", 1);
    pm1.add_menu(&m1);
    pm1.add_menu(&m2);
    pm1.command();
}