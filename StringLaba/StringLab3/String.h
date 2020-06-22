#include <iostream>
class String
{
	int size;
	char* data;
private:
	void SetSize(int n);
public:
	String();
	String(const char* s);
	String(const char c);
	String(const String& s);
	String(const String& s, int begin, int end);
	~String();
	int length() const;
	char& operator[] (int number)const;
	String operator+(const String& s)const;
	String operator+(const char c)const;
	bool operator==(const String& s) const;
	bool operator!=(const String& s)const;
	String& operator=(const String& s);
	String& operator=(const char c);
	bool operator<(const String& s)const;
	bool operator>(const String& s)const;
	friend std::ostream& operator<< (std::ostream& out, const String& s);
	friend std::istream& operator>> (std::istream& in, String& s);
	void copy(const String& s, int begin, int end);
	int FirstSearch(const char c);
	int LastSearch(const char c);
	int SubStringSearch(const char* s);
	int SearchSumbolOnTheString(const char c);
	String* part(char c);
	String StringRepeat(String& s, int n);
};
