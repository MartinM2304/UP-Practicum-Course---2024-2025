size_t myStrLen(const char* str)
{
	if (!str) return 0;

	size_t result = 0;
	while (*str++ && ++result);
	return result;
}

void myStrCpy(char* dest, const char* src)
{
	if (!dest || !src) return;

	while (*dest++ = *src++);
}

void myStrCat(char* first, const char* second)
{
	if (!first || !second) return;

	first += myStrLen(first);
	myStrCpy(first, second);
}

int myStrCmp(const char* first, const char* second)
{
	if (!first || !second) return 0;

	while (*first && *first++ == *second++);
	return *first - *second;
}
