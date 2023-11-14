#include <stdio.h>
#include "main.h"
#include <limits.h>

/**
 * printf_binry - print unsigned int number
 *	to binary number
 * @item: List collect of arguments
 * @flags: variable to control flow
 * @buffer: array of character to handel
 * @width: minimum space provid fo output
 * @precision: that correct the real number
 * @size: specifier size
 *
 * Return: Numbers of binary character.
 */
int printf_binry(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{

	unsigned int bits[32];
	unsigned int x, y, j, sum;
	int c;
	char digit;

	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);

	x = va_arg(item, unsigned int);
	y = INT_MAX;
	bits[0] = x / y;
	for (j = 1; j < 32; j++)
	{
		y /= 2;
		bits[j] = (x / y) % 2;

	}
	for (j = 0, sum = 0, c = 0; j < 32; j++)
	{
		sum += bits[j];
		if (sum || j == 31)
		{
			digit = '0' + bits[j];
			write(1, &digit, 1);
			c++;
		}
	}
	return (c);
}
