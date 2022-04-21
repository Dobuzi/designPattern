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
    AutoPtr(T* P = nullptr) : obj(p)
    {
        if (obj != nullptr) obj->AddRef();
    }
    AutoPtr(const AutoPtr& ap) : obj(ap.obj)
    {
        if (obj) obj->AddRef();
    }
    ~AutoPtr() { if (obj) obj->Release(); }

    T* operator->() { return obj; }
    T& operator()   { return *obj; }
};

int main()
{
    AutoPtr<ICalc> p1 = ReloadProxy();
    AutoPtr<ICalc> p2 = p1;
    std::cout << "-----------" << std::endl;
}