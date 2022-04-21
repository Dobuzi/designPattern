#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"

ICalc* ReloadProxy()
{
    void* addr = ec_load_module("CalcProxy.dll");

    typedef ICalc* (*F)();
    F f = (F)ec_get_function_address(addr, "CreateInstance");

    return f();
}

int main()
{
    ICalc* pCalc = ReloadProxy();

    std::cout << pCalc->Add(10, 20) << std::endl;
    std::cout << pCalc->Sub(10, 20) << std::endl;
}