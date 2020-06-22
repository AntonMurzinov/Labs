#include <iostream>
#include "String.h"


int main()
{
	system("color 0A");
	String ExampleStringFirst("I have a bitrhday");
	String ExampleStringSecond("Congratulations!");
	String sum = ExampleStringFirst + ExampleStringSecond;
	std::cout << "First string: " << ExampleStringFirst << "Second string: " << ExampleStringSecond << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Enter some string :\n";
	String Entry;
	std::cin >> Entry;
	if (Entry == sum)
		std::cout << "Same string" << std::endl;
	else if (Entry < sum)
		std::cout << "Your's new string < sum\n" << std::endl;
	else if (Entry > sum)
		std::cout << "Your's string > sum\n" << std::endl;
	std::cout << "Which symbol to take? ";
	int Number;
	std::cin >> Number;
	std::cout << std::endl << Entry[Number] << std::endl;
	std::cout << "How many times to repeat?\n" << std::endl;
	int RepeatNum;
	std::cin >> RepeatNum;
	String repeat;
	Entry = repeat.StringRepeat(Entry, RepeatNum);
	std::cout << Entry << std::endl;
	char Separator;
	std::cout << "Enter separator" << std::endl;
	std::cin >> Separator;
	String* array = nullptr;
	array = Entry.part(Separator);
	int n;
	if (Entry.length() - 2 != Entry.LastSearch(Separator))
		n = Entry.SearchSumbolOnTheString(Separator) + 1;
	else
		n = Entry.SearchSumbolOnTheString(Separator);
	for (int i = 0; i < n; i++)
	{
		String copy = array[i];
		std::cout << copy << std::endl;
	}
}