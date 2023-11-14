#include "main.h"

/**
 * is_printable - function check if a character is printable
 *
 * @a: Character value to check.
 *
 * Return: if a 1 is printable otherwise is 0
 */
int is_printable(char a)
{
	if (a >= 32 && a < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - function to append hexadecimal numbers and write it to buffer
 *
 * @buffer: array of spaces to handle printf file
 * @a: number to append.
 * @ascii_code: stantnder code to be valued
 *
 * Return:  intger number 3
 */
int append_hexa_code(char ascii_code, char buffer[], int a)
{
	char map_too[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[a++] = '\\';
	buffer[a++] = 'x';

	buffer[a++] = map_too[ascii_code / 16];
	buffer[a] = map_too[ascii_code % 16];

	return (3);
}

/**
 * is_digit - function make char know is a digit
 *
 * @ch: Character evaluated
 *
 * Return: 0 if not digit , otherwise digit
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - function specify size in cast
 *
 * @size: intger to indecat to size of number.
 * @number: Number to convert it by.
 *
 *
 * Return: char cast to number
 */
long int convert_size_number(long int number, int size)
{

	if (size == S_SHORT)
		return ((short)number);

	else if (size == S_LONG)
		return (number);

	return ((int)number);
}

/**
 * convert_size_unsignd - specific size to cast number
 *
 * @number: intger to be cast
 * @size: intger to indecat to size of number.
 *
 * Return: char cast to number
 */
long int convert_size_unsignd(unsigned long int number, int size)
{
	unsigned int a;

	a = ((unsigned int)number);

	if (size == S_SHORT)
		return ((unsigned short)number);
	else if (size == S_LONG)
		return (number);

	return (a);
}
