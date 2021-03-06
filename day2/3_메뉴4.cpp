#include <iostream>
#include <string>
#include <vector>
// #include <conio.h> 
#include <stdio.h>

class BaseMenu
{
    std::string title;
    public:
        BaseMenu(const std::string& title) : title(title) {}
        virtual ~BaseMenu() {}
        std::string get_title() { return title; }
        virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;

    public:
        MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}
        ~MenuItem() {}
        void command() override
        {
            std::cout << get_title() << " menu is selected." << std::endl;
            getchar();
        }
};

class PopUpMenu : public BaseMenu
{
    int id;
    std::vector<BaseMenu*> v;

    public:
        PopUpMenu(const std::string& title, int id) : BaseMenu(title), id(id) {}
        ~PopUpMenu() {}
        void add_menu(BaseMenu* m) { v.push_back(m); }
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
    MenuItem m1("Beef Roll", 11);
    MenuItem m2("Tuna Roll", 12);

    // m1.command();

    PopUpMenu pm1("Rolls", 1);
    pm1.add_menu(&m1);
    pm1.add_menu(&m2);

    MenuItem m3("Ramen", 13);
    
    PopUpMenu pm2("Today's menu", 2);
    pm2.add_menu(&pm1);
    pm2.add_menu(&m3);

    pm1.command();
}