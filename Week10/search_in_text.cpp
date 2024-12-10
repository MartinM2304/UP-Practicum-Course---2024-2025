#include <iostream>

bool isPrefix(const char* pattern, const char* text)
{
	if (!text || !pattern) return false;

	while (*pattern)
	{
		if (*pattern != *text)
		{
			return false;
		}

		pattern++;
		text++;
	}

	return true;
}

bool searchInText(const char* pattern, const char* text)
{
	if (!text || !pattern) return false;

	while (*text)
	{
		if (isPrefix(pattern, text))
		{
			return true;
		}

		text++;
	}

	return false;
}

int main()
{
	std::cout << searchInText("Slavi", "My name is Slavi") << std::endl;
	std::cout << searchInText("slavi", "My name is Slavi") << std::endl;

	return 0;
}