#include <iostream>
#include <mutex>

// RAII (Resource Acquisition Is Initialization)
// Stack Unwinding : local variables are safely destroyed when catching the exception

template<typename T>
class Singleton
{
    protected:
    Singleton() {}                                    
    private:                                          
    Singleton(const Singleton& c) = delete;           
    Singleton& operator=(const Singleton& c) = delete;
    static T* pinstance;                      
    static std::mutex mtx;

    public:                                           
    static Singleton& getInstance()                   
    {                                                 
        std::lock_guard<std::mutex> g(mtx);           
        if (pinstance == nullptr)                     
            pinstance == new T;               
        return *pinstance;                            
    }                                                 

};
template<typename T> T*         Singleton<T>::pinstance = nullptr;
template<typename T> std::mutex Singleton<T>::mtx;

class Cursor : public Singleton<Cursor>
{
    
};