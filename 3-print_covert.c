#include "main.h"

/*3-print_covert.c*/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int printf_unsigned(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(item, unsigned long int);

	number = convert_size_unsignd(number, size);

	if (number == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (writ_unsgned(0, a, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printf_octal(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(item, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = convert_size_unsignd(number, size);

	if (number == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[a--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (writ_unsgned(0, a, buffer, flags, width, precision, size));
}
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int printf_hexa(va_list item, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int number = va_arg(item, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = convert_size_unsignd(number, size);

	if (number == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[a--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;
    int c = writ_unsgned(0, a, buffer, flags, width, precision, size);
	return (c);

}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printf_hexadecimal(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = printf_hexa(item, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size);

	return (a);
}


/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printf_hexa_upper(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = printf_hexa(item, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size);
	return (a);
}
