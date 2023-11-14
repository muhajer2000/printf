#include "main.h"
#include <limits.h>

/**
 * print_non_printable - Print non print_able chars ascii to hexa
 *
 * @item: collect of item requir to print
 * @size: Size  of  specifier string
 * @flags:  int to add and return to string
 * @width: minimum field width
 * @buffer: array of spaces to handle printf file
 * @precision: Precision specification to caluc the real number
 *
 * Return: number of hexa chars to print
 */
int print_non_printable(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0, off_set = 0;
	char *s = va_arg(item, char *);

	UNUSED(size);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(flags);
	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[a] != '\0')
	{
		if (is_printable(s[a]))
			buffer[a + off_set] = s[a];
		else
			off_set += append_hexa_code(s[a], buffer, a + off_set);
		a++;
	}
	buffer[a + off_set] = '\0';
	int a = write(1, buffer, a + off_set);

	return (a);
}
