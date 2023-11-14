#include "main.h"

/**
 * printf_binry - function covert number to binary
 *
 * @item: collect of arguments
 * @buffer: array of memorey to handle printf
 * @flags:  int to add and return to string
 * @width: minimum field width
 * @precision: Precision specification to caluc the real number
 * @size: Size  of  specifier string
 *
 * Return: an intger of charcter to print
*/
int printf_binry(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{

	unsigned int bits[32];
	unsigned int x, y, j, sum;
	int c;
	char digit;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(item, unsigned int);
	y = 2147483648;

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
