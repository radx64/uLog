#include <iostream>
#include <fstream>

#include "Buffer.hpp"
#include "Flusher.hpp"

// class FileBuffer : public IBuffer
// {
// public:
// 	explicit FileBuffer(std::string fileName)
// 	{
// 		file_.open(fileName, std::fstream::out);
// 	}

// 	IBuffer& operator<<(const std::string& in) override
// 	{
// 		file_ << in;
// 		return *this;		
// 	}

// 	~FileBuffer() override
// 	{
// 		file_.close();
// 	};

// private:
// 	std::fstream file_;
// };

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

// class FileLogger
// {
// public:
// 	Flusher debug(void);
// 	Flusher info(void);
// 	Flusher warn(void);
// 	Flusher error(void);
// private:
// 	static FileBuffer buff_;
// };