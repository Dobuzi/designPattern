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

template<typename T>
class AutoPtr
{
    T* obj;
    public:
    AutoPtr(T* P = 0) : obj(p) {}

    T* operator->() { return obj; }
    T& operator()   { return *obj; }
};

int main()
{
    ICalc* pCalc = ReloadProxy();

    pCalc->AddRef();


    std::cout << pCalc->Add(10, 20) << std::endl;
    std::cout << pCalc->Sub(10, 20) << std::endl;

    ICalc* pCalc2 = pCalc;
    pCalc2->AddRef();

    pCalc2->Release();

    std::cout << "-----------" << std::endl;

    pCalc->Release();

    // delete pCalc;
}