#include <iostream>

bool isValid(int n)
{
	return n >= 0;
}

bool isSuffix(unsigned int n, unsigned int k)
{
	while (k != 0)
	{
		unsigned int lastDigitOfK = k % 10;
		unsigned int lastDigitOnN = n % 10;

		if (lastDigitOfK != lastDigitOnN)
		{
			return false;
		}

		n /= 10;
		k /= 10;
	}

	return true;
}

bool isPrefix(unsigned int n, unsigned k)
{
	while (n >= k)
	{
		if (n == k)
		{
			return true;
		}

		n /= 10;
	}

	return false;
}

bool isInfix(unsigned int n, unsigned int k)
{
	while (n >= k)
	{
		if (isSuffix(n, k))
		{
			return true;
		}

		n /= 10;
	}

	return false;
}

bool isPossibleConcatenation(unsigned int n, unsigned int k)
{
	if (!isValid(n) || !isValid(k))
	{
		std::cout << "Invalid input!" << std::endl;
		return false;
	}

	while (n >= k)
	{
		if (isInfix(n, k) && !isSuffix(n, k) && !isPrefix(n, k))
		{
			return true;
		}

		n /= 10;
	}

	return false;
}

int main()
{
	unsigned int n = 0, k = 0;

	{
		std::cin >> n >> k;
		std::cout << (isPossibleConcatenation(n, k) ? "True" : "False") << std::endl;
	}
	{
		std::cin >> n >> k;
		std::cout << (isPossibleConcatenation(n, k) ? "True" : "False") << std::endl;
	}
	{
		std::cin >> n >> k;
		std::cout << (isPossibleConcatenation(n, k) ? "True" : "False") << std::endl;
	}

	return 0;
}