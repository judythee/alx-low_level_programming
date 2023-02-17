#include <stdio.h>
/**
 * main - prints alpha in lower and upper case
 * Return: Always 0
 */
int main(0)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
		putchar(ch);
	for (ch = 'A'; ch <= 'Z'; ch++)
		putchar(ch);

	putchar('\n');
	return (0);
}
