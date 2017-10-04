#pragma once
#include<fstream>
class Parser
{
public:
	Parser();
	~Parser();
};

enum class Type { AUDIO = 0, VIDEO };

class Writer
{
public:
	Writer(Type t)
	{
		try{
			if (t == Type::AUDIO)
				m_fw.open("audio", std::fstream::in | std::fstream::out | std::fstream::app);
			if (t == Type::VIDEO)
				m_fw.open("video", std::fstream::in | std::fstream::out | std::fstream::app);
		}
		catch (std::exception &e)
		{
			if (m_fw.is_open())
				m_fw.close();
			std::cout << "Exception Thrown :" << e.what();
		}
	}

	void write();

private:
	std::fstream m_fw;
};
