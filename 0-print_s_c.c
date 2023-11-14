#include "main.h"
#include <limits.h>

/**
 * printf_char- function that to  print a character
 *
 * @item: collect of item requir to print
 * @size: Size  of  specifier string
 * @flags:  int to add and return to string
 * @width: minimum field width
 * @buffer: array of spaces to handle printf file
 * @precision: Precision specification to caluc the real number
 *
 * Return: int characters to print it
*/
int printf_char(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(item, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * printf_str - function print srting and handel it
 *
 * @item: collect of item requir to print
 * @size: Size  of  specifier string
 * @flags:  int to add and return to string
 * @width: minimum field width
 * @buffer: array of spaces to handle printf file
 * @precision: Precision specification to caluc the real number
 *
 * Return: int of string characters to print
*/
int printf_str(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, a;
	char *s = va_arg(item, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], len);
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (width);
		}
	}

	return (write(1, s, len));
}
/**
 * printf_percent - Printf a percent sign character
 *
 *@item: collect of item requir to print
 * @size: Size  of  specifier string
 * @flags:  int to add and return to string
 * @width: minimum field width
 * @buffer: array of spaces to handle printf file
 * @precision: Precision specification to caluc the real number
 *
 * Return: an intger of charcter to print %
*/
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
