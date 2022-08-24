#include "stdafx.h"
#include "ObserverPattern.h"

void Subject::attach(ObserverPattern *obj)
{
	mlist.push_back(obj);
}

void Subject::detach(ObserverPattern *obj)
{
	// mlist.erase(obj);
}

void Subject::updateAll()
{
	list<ObserverPattern *>::iterator it;
	/*	for (it = mlist.begin(); it != mlist.end(); it++)
		{
		ObserverPattern *o = static_cast<ObserverPattern *>(it);
		o->notify();
		}*/
	for (int i = 0; i < mlist.size(); i++)
	{
		mlist[i]->notify();
	}
}