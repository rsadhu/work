#include<iostream>
#include<stdio.h>
#include<string.h>


using namespace std;


class Logger
{
    public:
	Logger()
	{
	cout<<"\n Logger :: Logger \n";
	    fp = fopen("log.txt","w+");
	}


	~Logger()
	{
		cout<<"\n Logger :: ~Logger \n";
	 fclose(fp);
	}
	
	void log(const char * txt)
	{
		cout<<"log \n";
		if(fp)
		{
			int l = strlen(txt);
			int n  = fwrite(txt,1, l,fp);
			cout<<"\nthe number of data written  :: "<<n<<endl;

		}
	}

    private:
	FILE *fp;
};


//#define LOG(x) Logger::log(x)
