#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <iostream>

std::queue<int> queue_g;
std::mutex mu;
std::condition_variable cond;
using namespace std::chrono_literals;

void writer(void)
{
	int i = 0, k = 10;
	while (true)
	{
		//RERUN:
		std::unique_lock<std::mutex> locker(mu);
		try
		{
			queue_g.push(i++);
			throw std::invalid_argument("received negative value");
		}
		catch(std::exception &e)
		{
			//locker.unlock();
			std::cout << "\n catch \n";
			//goto RERUN;
			continue;
		}
		locker.unlock();
		cond.notify_one();
		std::this_thread::sleep_for(1s);		
	}
}

void writer_reader_function()
{
	std::cout << " main starts\n";

	std::thread writer_thread(writer);


	while (true)
	{
		std::unique_lock<std::mutex> locker(mu);
		cond.wait(locker, []() {return !queue_g.empty(); });
		std::cout << queue_g.front();
		queue_g.pop();
		locker.unlock();
	}

	writer_thread.join();
}  