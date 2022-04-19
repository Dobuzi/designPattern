#include <iostream>
#include <string>
#include <vector>
// #include <conio.h> 
// #include <stdio.h>

struct NotImplemented : public std::exception {};

class BaseMenu
{
    std::string title;
    public:
        BaseMenu(const std::string& title) : title(title) {}
        virtual ~BaseMenu() {}
        std::string get_title() { return title; }
        virtual void command() = 0;
        virtual void add_menu(BaseMenu* m)  { throw NotImplemented(); }
        virtual BaseMenu* get_submenu(int idx)   { throw NotImplemented(); }
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
            std::cin.get();
            std::cin.get();
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

        BaseMenu* get_submenu(int idx) { return v[idx]; }
};

int main()
{
    PopUpMenu* root =   new PopUpMenu("ROOT", 1);
    PopUpMenu* pm1  =   new PopUpMenu("Definitions", 2);
    PopUpMenu* pm2  =   new PopUpMenu("Colors", 3);

    root->add_menu(pm1);
    root->add_menu(pm2);
    // pm1->add_menu(pm2);

    // pm1->add_menu(new MenuItem("HD",    11));
    // pm1->add_menu(new MenuItem("FHD",   12));
    // pm1->add_menu(new MenuItem("UHD",   13));

    // pm2->add_menu(new MenuItem("RED",   21));
    // pm2->add_menu(new MenuItem("GREEN", 22));
    // pm2->add_menu(new MenuItem("BLUE",  23));

    root->get_submenu(0)->add_menu(new MenuItem("HD",    11));

    root->command();

    std::cout << root->get_submenu(0) << std::endl;;
}