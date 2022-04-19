#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const char* buff) 
	{
		printf("%s ¾²±â\n", buff);
	}
};

int main()
{
	FILE* f = fopen("a.txt", "wt");
	fclose(f);
}