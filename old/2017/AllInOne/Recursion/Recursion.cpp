// Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<iostream>

std::string changeword(std::string word,const std::string &from,const std::string to)
{
	if (word.length() < from.length())
	{
		return word;
	}
	else
	{		
		int i = 0;
		while(word[i] == from[i] && i< from.length())
		{
			word[i] = to[i];			
			i++;
		}
		word =  word + changeword(word.substr(i+1), from, to);		 
	}	
//	return word;
}


int _tmain(int argc, _TCHAR* argv[])
{
	std::string text;
	if (argc > 2)
	{
		text.append((char *)argv[1]);
	}
	else
		text = "This is My Default String. where which whose and whence";

	text = changeword(text, "wh", "ab");
	std::cout << " string is :: " << text << std::endl;

	return 0;
}

