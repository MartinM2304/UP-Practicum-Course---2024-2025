#include <iostream>

int charToDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}

	return -1;
}

void concat(unsigned int& num, unsigned int digit)
{
	(num *= 10) += digit;
}

unsigned int stringToNumberWrapper(const char* str)
{
	if (!str) return 0;

	unsigned int result = 0;

	while (*str)
	{
		int digit = charToDigit(*str);

		if (digit == -1) return 0;

		concat(result, digit);
		str++;
	}

	return result;
}

int stringToNumber(const char* str)
{
	if (!str) return 0;

	return (*str == '-') ?
		(-1) * stringToNumberWrapper(str + 1) :
		stringToNumberWrapper(str);
}

int main()
{
	{
		unsigned int num = stringToNumber("12321");
		std::cout << num << std::endl;
	}
	{
		unsigned int num = stringToNumber("-24683579");
		std::cout << num << std::endl;
	}

	return 0;
}