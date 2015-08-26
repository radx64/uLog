#include <iostream>
#include <fstream>
#include <sstream>

class IBuffer
{
public:
	virtual IBuffer& operator<<(const std::string& in) = 0;
	virtual ~IBuffer() {};
};

class Buffer : public IBuffer
{
public:
	explicit Buffer();

	// template <typename T>
	// IBuffer& operator<<(const T& in) override
	// {
	// 	std::cout << in;
	// 	return *this;
	// }	

	IBuffer& operator<<(const std::string& in) override
	{
		std::cout << in;
		return *this;		
	}

	~Buffer() override;
};

class FileBuffer : public IBuffer
{
public:
	explicit FileBuffer(std::string fileName)
	{
		file_.open(fileName, std::fstream::out);
	}

	IBuffer& operator<<(const std::string& in) override
	{
		file_ << in;
		return *this;		
	}

	~FileBuffer() override{};
private:
	std::fstream file_;

};


class Flusher
{
public:
	Flusher(std::string prefix, IBuffer* buff);

	Flusher(Flusher&& f);

	template <typename T>
	Flusher& operator<<(const T& in)
	{
	stream_ << in;
	return *this;
	}	

	~Flusher();

	std::stringstream stream_;
	std::string prefix_;
	IBuffer* buff_;
};


class Logger
{
public:
	Flusher debug(void);
	Flusher info(void);
	Flusher warn(void);
	Flusher error(void);
private:
	static Buffer buff_;
};

class FileLogger
{
public:
	Flusher debug(void);
	Flusher info(void);
	Flusher warn(void);
	Flusher error(void);
private:
	static FileBuffer buff_;
};