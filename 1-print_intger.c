#include "main.h"

/* 1-print_intger.c*/
/********************************************
 *
 * print_int - Print int.
 * @types: Lista of arguments.
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of chars printed.
 *
 ********************************************/
int printf_intger(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int N = va_arg(item, long int);
	unsigned long int number;

	N = convert_size_number(N, size);

	if (N == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)N;

	if (N < 0)
	{
		number = (unsigned long int)((-1) * N);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[a--] = (number % 10) + '0';
		number /= 10;
	}

	a++;

	return (writ_number(is_negative, a, buffer, flags, width, precision, size));
}
