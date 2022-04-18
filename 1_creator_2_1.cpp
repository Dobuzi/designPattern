#include <string>
#include <iostream>

class People
{
    std::string name;
    int age;

    public:
        People(const std::string& name, int age) : name(name), age(age) {};
        ~People() {};
};

class Student : public People
{
    int id;
    public:
        Student(const std::string& name, int age, int id) : People(name, age), id(id) {
            std::cout << name << std::endl;
        };
        ~Student() {};
};

int main()
{
    People p1("kim", 20);
    Student s1("kjw", 20, 34);
    return 0;
}
