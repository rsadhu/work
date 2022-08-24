#include "codesnippet.h"

CodeSnippet::CodeSnippet()
{

	ResourceInterface *iface = mFactory.getInstance("txt");
	if (iface)
	{
		iface->showResource();
	}
}

CodeSnippet::~CodeSnippet()
{
}
