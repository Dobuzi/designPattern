// The rule to make the pointer variables. = One simple rule

void foo (int a)
{

}

int main()
{
    int n = 10;

    // p1 is pointing n : variable pointer
    int *p1 = &n;

    // p2 is pointing foo function : function pointer
    void (*p2) (int) = &foo;

    int x[10];
    int (*p3)[10] = &x;
}