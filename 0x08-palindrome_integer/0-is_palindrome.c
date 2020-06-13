#include "palindrome.h"

/**
 * is_palindrome - Function to check if a number is a palindrome
 * @n: unsigned long number to be checked
 *
 * Return: 1 if the number is palindrome, 0 if not.
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = reverse(n, 0);
	if (n == rev)
		return (1);
	return (0);
}

/**
 * reverse - Function to reverse a number
 * @n: unsigned long number to be checked
 * @rev: reversed number by recursive function
 *
 * Return: reverse function until n equals to 0.
 */
unsigned long reverse(unsigned long n, unsigned long rev)
{
	if (n == 0)
		return rev;
	rev = (rev * 10) + (n % 10);
	return (reverse(n / 10, rev));
}
