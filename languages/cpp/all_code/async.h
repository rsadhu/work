#include <iostream>
#include <future>

int process(std::future<int> &fut_para)
{
	int n = fut_para.get();

	std::this_thread::sleep_for(10ms);

	return n * 2;

}


void  parallel_async_process(void)
{

	std::future<int> f;
	std::promise<int> p;
	f = p.get_future();
	std::future<int> res = std::async(std::launch::async, process, std::ref(f));

	std::cout << "hello we are done \n";

	p.set_value(10);

	std::this_thread::sleep_for(20ms);


	std::cout << "result is " << res.get() << "\n";
}

void parallel_thread_process(void)
{
	std::future<int> f;
	std::promise<int> p,q;
	f = p.get_future();

	std::thread th([&]() 
	{
		auto x = f.get() * 10;
		q.set_value(x);
	});
	
	p.set_value(50);

	std::cout << q.get_future().get() << "\n";

	th.join();
}
