#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <fstream>

namespace  threading
{

	std::condition_variable cond;
	std::mutex mu;
	std::ofstream fw("test.txt", std::ifstream::app);
	std::ifstream fr("test.txt", std::ifstream::app);
	std::atomic_bool exit_(false);



	void write_to_file()
	{
		while (true)
		{
			std::unique_lock<std::mutex> locker(mu);
			std::string str;
			std::getline(std::cin, str);
			if (str == "exit") {
				exit_ = true;
				cond.notify_all();
				break;
			}
			fw << str;
			cond.notify_all();
		}
	}


	void read_from_file()
	{
		while (!exit_)
		{
			std::unique_lock<std::mutex> locker(mu);
			cond.wait(locker);
			std::string str;
			fr >> str;
			std::cout << str << "\n";
		}
	}



	void main_motor_code()
	{
		if (!fr.is_open() && !fw.is_open())
		{
			std::cout << " file is not opened\n";
			return;
		}

		std::thread th1, th2;
		th1 = std::thread(read_from_file);
		th2 = std::thread(write_to_file);
		th1.join();
		th2.join();

		fr.close();
		fw.close();
	}

}