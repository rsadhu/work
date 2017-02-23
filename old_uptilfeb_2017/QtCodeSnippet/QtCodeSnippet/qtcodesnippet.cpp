#include "qtcodesnippet.h"

QtCodeSnippet::QtCodeSnippet()
	
{
	ResourceInterface *iface = mFactory.getInstance("txt");
	if (iface)
	{
		iface->showResource();
	}
}

QtCodeSnippet::~QtCodeSnippet()
{

}
