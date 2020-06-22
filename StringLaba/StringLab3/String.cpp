#include "String.h"
#include <iostream>
String::String()
{
	data = new char[1];
	data[0] = 0;
	size = 1;
}

String::String(const char* s)
{
	data = nullptr;
	size = strlen(s) + 1;
	data = new char[size + 1];
	if (data == nullptr)
		throw "error";
	for (int i = 0; i < size; i++)
	{
		data[i] = s[i];
	}
	data[size] = 0;
}

String::String(const char c)
{
	if (c != 0)
	{
		size = 2;
		data = new char[2];
		data[0] = c;
		data[1] = 0;
	}
	else
	{
		size = 1;
		data = new char[2];
		data[0] = 0;
	}
}

String::String(const String& s)
{
	data = nullptr;
	size = s.length();
	data = new char[size];
	if (data == nullptr)
		throw "error";
	for (int i = 0; i < size; i++)
		data[i] = s[i];
}
String::String(const String& s, int begin, int end)
{
	data = nullptr;
	size = end - begin + 2;
	data = new char[size];
	if (data == nullptr)
		throw "error";
	for (int i = 0; i < size; i++)
		data[i] = s[begin + i];
	data[size - 1] = 0;
}
String::~String()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	size = 0;
}

int String::length() const
{
	return size;
}

char& String::operator[](int number) const
{
	return data[number];
}

String String::operator+(const String& s) const
{
	String ReSize(*this);
	ReSize.SetSize(size + s.length() - 1);
	for (int i = size - 1; i < ReSize.length(); i++)
	{
		ReSize[i] = s[i - size + 1];
	}
	return ReSize;
}
String String::operator+(const char c)const
{
	String ReSize(*this);
	if (ReSize.size != 1)
		ReSize.SetSize(size + 1);
	else
		ReSize.SetSize(size + 2);
	int ressize = ReSize.length();
	ReSize[ressize - 2] = c;
	return ReSize;
}

bool String::operator==(const String& s) const
{
	if (size == s.length())
	{
		int i = 0;
		while (data[i] == s[i])
		{
			i++;
		}
		if (i == size - 1)
			return true;
	}
	return false;
}
bool String::operator!=(const String& s) const
{
	if (*this == s) return false;
	return true;
}
String& String::operator=(const String& s)
{
	if (*this == s) return *this;
	if (data != nullptr)
		delete[] data;
	size = s.length();
	data = nullptr;
	data = new char[size];
	if (data == nullptr)
		throw "error";
	for (int i = 0; i < size; i++)
		data[i] = s[i];
	return *this;
}

String& String::operator=(const char c)
{
	String temp(c);
	*this = temp;
	return *this;
}

bool String::operator<(const String& s) const
{
	for (int i = 0; i < (size < s.length() ? size : s.length()); i++)
	{
		if (data[i] < s[i]) return true;
		else if (data[i] > s[i]) return false;
	}
	return false;
}

bool String::operator>(const String& s) const
{
	for (int i = 0; i < (size < s.length() ? size : s.length()); i++)
	{
		if (data[i] > s[i]) return true;
		else if (data[i] < s[i]) return false;
	}
	return false;
}
void String::copy(const String& s, int begin, int end)
{
	String copy(s, begin, end);
	*this = copy;
}
int String::FirstSearch(const char c) // ����� ������� ��������� ������� � ������, ���������� ����� ����� �������
{
	for (int i = 0; i < size; i++)
		if (this->data[i] == c)
			return i;
	return 0;
}
int String::LastSearch(const char c)//����� ���������� ��������� ������� � ������ ���������� ����� ����� �������
{
	int last = 0;
	for (int i = 0; i < size; i++)
		if (data[i] == c)
			last = i;
	return last;
}
int String::SubStringSearch(const char* s) //����� ������� ��������� ��������� � ������
{
	int sizechar = strlen(s);
	int count = 0;
	int i;
	for (i = sizechar; i < size; i++)
	{
		if (data[i] == s[i])
			count++;
		else
			count = 0;
		if (count == sizechar)
			break;
	}
	if (count == sizechar)
		return i - count;
	return 0;
}
int String::SearchSumbolOnTheString(const char c) // ����� ���������� ��������� ������� � ������
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (data[i] == c)
			count++;
	return count;
}
String* String::part(char c) //   
{
	int count = this->SearchSumbolOnTheString(c);
	String* res = nullptr;
	int arraysize;
	if (size - 2 != this->LastSearch(c) || this->FirstSearch(c) != 0)
	{
		arraysize = count + 1;
		res = new String[arraysize];
	}
	else
	{
		arraysize = count;
		res = new String[arraysize];
	}
	res[0] = *this;
	for (int i = 1; i < arraysize; i++)
	{
		int begin = res[i - 1].FirstSearch(c);
		int end = res[i - 1].length() - 1;
		String copy(res[i - 1], begin + 1, end);
		res[i] = copy;
		res[i - 1].SetSize(begin + 1);
	}
	return res;
}
String String::StringRepeat(String& s, int n)
{
	if (s.length() == 0)
		throw "Length = 0";
	String res(s);
	for (int i = 0; i < n - 1; i++)
	{
		res = res + s;
	}
	return res;
}
void String::SetSize(int n)
{
	if (size != n)
	{
		int copysize = size;
		char* copy = data;
		size = n;
		data = nullptr;
		data = new char[size];
		if (data == nullptr)
			throw "error";
		if (n >= copysize)
		{
			for (int i = 0; i < copysize; i++)
				data[i] = copy[i];
			data[n - 1] = 0;
		}
		else
		{
			for (int i = 0; i < n; i++)
				data[i] = copy[i];
			data[n - 1] = 0;
		}
		delete[] copy;
	}
	else
		std::cout << "Same size" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.data << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, String& s)
{
	char get[256];
	in.getline(get, 256);
	String right(get);
	s = right;
	return in;
}