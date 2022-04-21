#include <iostream>
// #include <stdio.h>

int main()
{
    char s1[] = "hello";
    char s2[] = "hello";

    const char* s3 = "hello"; // pointing constant memory
    const char* s4 = "hello";

    // *s3 = 'A';

    std::cout << &s3 << std::endl;
    std::cout << &s4 << std::endl;
}