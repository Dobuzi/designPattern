#pragma once

struct IRefCount
{
    virtual void AddRef() = 0;
    virtual void Release() = 0;

    virtual ~IRefCount() {}
}

struct ICalc : public IRefCount
{
    virtual int Add(int a, int b) = 0;
    virtual int Sub(int a, int b) = 0;

    virtual ~ICalc() {}
};
