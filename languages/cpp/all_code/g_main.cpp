#include "threads.h"
#include "async.h"
#include "parallel_file_read_write.h"
#include "heaps.h"
#include "matrices.h"


int main(void)
{
	//writer_reader_function();
	//std::vector<int> res;
	//longestConsecutiveSequence({ 100,4,200,1,3,2}, res);

	//parallel_async_process();
	//parallel_thread_process();

	//threading::main_motor_code();


	//std::vector<int> data = {5,1,-6, 0, 7, 4, 8};
	//createMaxHeap(data);



	std::vector<int>d{ 1,2,3,4,5,6,7,8,9 };
	Matrix m1(d, 3, 3);

	std::cout << m1;

	Matrix m2(d, 3, 3);

	m1 = m2 * m1;

	std::cout << m1;

	m1 = m1 - m2;

	std::cout << m1;

	m1 = m1 + m2;
	std::cout << m1;

	return 0;
}