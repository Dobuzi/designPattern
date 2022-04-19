#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

struct Stream
{
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& buff) 
	{
		std::cout << "write " << buff << std::endl;
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream;
	
	public:
		EncryptDecorator(Stream* stream) : stream(stream) {}

		void Write(const std::string& data)
		{
			auto s = "[" + data + "] encrypted";

			stream->Write(s);
		}
};

class ZipDecorator : public Stream
{
	Stream* stream;
	
	public:
		ZipDecorator(Stream* stream) : stream(stream) {}

		void Write(const std::string& data)
		{
			auto s = "[" + data + "] compressed";

			stream->Write(s);
		}
};

int main()
{
	// FILE* f = fopen("a.txt", "wt");
	// fclose(f);

	FileStream fs("a.txt");
	fs.Write("hello");

	EncryptDecorator ed(&fs);
	ed.Write("eello");

	ZipDecorator zd(&ed);
	zd.Write("zello");
}