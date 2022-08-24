#ifndef __DM__
#define __DM__
#include <curl.h>
typedef void (*dmComplete)(bool);
class DM
{
public:
	void start();
	void stop();

private:
	dmComplete m_callback;
};
#endif //__DM__