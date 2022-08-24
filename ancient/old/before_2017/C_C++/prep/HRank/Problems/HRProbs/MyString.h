#pragma once
class MyString
{
public:
	explicit MyString(char *src);
	MyString(const MyString &rhs);
	MyString &operator=(const MyString &rhs);
	~MyString();
	int length();
	bool compare(MyString &rhs);
	bool compare(const char *);
	static bool compare(MyString &, MyString &);

private:
	char *mString;
	int mLength;
};
