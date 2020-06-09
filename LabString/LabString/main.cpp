#include "String.h"

int main()
{
	String str;
	String str2("Happy");
	String str3(str2);
	cout << str2.GetString() << endl;
	cout << str3.GetString() << endl;
	str3.SetStringLength("Birthday");
	cout << str3 << endl;
	String result;
	result = str2 + str3;
	bool equal = str2 == str3;
	cout << "+ : " << result << endl;
	cout << "== : " << equal << endl;
	cout << str2.GetLength() << endl;
	cout << str3.GetLength() << endl;
	cout << result.GetLength() << endl;
	String str4("Funny sunday");
	String str5("Funny sunday");
	bool equal2 = str4 == str5;
	cout << "== : " << equal2 << endl;
	str5.SetStringLength("sunday");
	bool res = str4 < str5;
	cout << "< : " << res << endl;
	bool res2 = str4 > str5;
	cout << "> : " << res2 << endl;
	cout << "[] : " << str4[0] << endl;
	cout << str4.Find("F") << endl;
	cout << str4.FirstFind("u") << endl;
	str4.Getline(" ");
	cout << str4.Dubl(3) << endl;
	cout << str4.AllFind("nn") << endl;

	return 0;

}