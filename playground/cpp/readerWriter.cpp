#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>

std::mutex g_mu;
std::condition_variable g_cond;
std::vector < int > g_data;

bool done = true;

int n = 0;

void readerThread ()
{
  while (done || !g_data.empty())
  {
    std::unique_lock<std::mutex> lock(g_mu);
    g_cond.wait(lock,[]()
    {
        return !g_data.empty();
    }
    );
    std::cout<< "\n data is "<< g_data.back();
    g_data.pop_back();
    lock.unlock();
  }
}


void writerThread ()
{
  do
    {
      std::this_thread::sleep_for (std::chrono::seconds (1));
      std::unique_lock < std::mutex > lock(g_mu);
      g_data.push_back (n);
      std::cout<<" writing data"<<n<<"\n";
      lock.unlock ();
      g_cond.notify_all();
    n--;
  } while (n > 0);
  done = false;
}


int main (int argc, char *argv[])
{
  if(argc==2)
      n = std::stoi(std::string(argv[1]));
  else
      n = 20;
  std::thread t1 (readerThread), t2 (writerThread);
  t1.join ();
  t2.join ();
  return 0;
}
