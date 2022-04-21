// helper.h
#pragma once

#define MAKE_SINGLETON(classname)			\
private:									\
	classname() {}							\
public:										\
	static classname& getInstance()			\
	{										\
	static classname instance;				\
		return instance;					\
	}										\
public:										\
	classname(classname&) = delete;			\
	void operator=(classname&) = delete;	\

#define DECLARE_SHAPE(classname)                    \
static Shape* Create() { return new classname; }	\
static AutoRegister ar;								\

