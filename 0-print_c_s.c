#include "main.h"
#include <limits.h>
/*0-print_c_s.c*/
/******************************************************************
 * printf_char- function that to  print a character.
 * @item :collect of item requir to print.
 * @size: Size  of  specifier string.
 * @flags:  int to add and return to string.
 * @width: minimum field width.
 * @buffer: array of spaces to handle printf file.
 * @precision: Precision specification to caluc the real number.
 * Return: int characters to print it.
 ******************************************************************/
int printf_char(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{

	char c = va_arg(item, int);

	return (handle_write_char(c, flags, precision, width,  buffer,  size));
}
/*******************************************************
 * print_str - function print srting and handel it.
 * @item: collect of item requir to print.
 * @size: Size  of  specifier string.
 * @flags:  int to add and return to string.
 * @width: minimum field width.
 * @buffer: array of spaces to handle printf file.
 * @precision: Precision specification to caluc the real number.
 * Return: int of string characters to print.
 *************************************************************/
int printf_str(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, a;
	char *st = va_arg(item, char *);

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	if (st == NULL)
	{
		st = "(null)";
		if (precision >= 6)
			st = "      ";
	}

	while (st[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &st[0], len);
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &st[0], len);
			return (width);
		}
	}


	return (write(1, st, len));
}

/**********************************************************
 * printf_percent - Printf a percent sign character.
 *@item: collect of item requir to print.
 * @size: Size  of  specifier string.
 * @flags:  int to add and return to string.
 * @width: minimum field width.
 * @buffer: array of spaces to handle printf file.
 * @precision: Precision specification to caluc the real number.
 * Return: an intger of charcter to print %.
 ************************************************************/
int printf_percent(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(item);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
