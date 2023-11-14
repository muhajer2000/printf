#include "main.h"

/**
 * print_reve- function print number in revers.
 *
 * @item: characters items.
 * @size: Size  of  specifier string
 * @flags:  int to add and return to string
 * @width: minimum field width
 * @buffer: array of spaces to handle printf file
 * @precision: Precision specification to caluc the real number
 *
 * Return: int nu print chars in reverse
*/
int print_rev(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	char *s;
	int j, num = 0, i;
	char a;

	UNUSED(width);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(flags);


	s = va_arg(item, char *);

	if (s == NULL)
	{
		s = "(Null)";
		UNUSED(precision);
	}
	for (i = 0; s[i]; i++)

		;

	for (j = (i - 1); j >= 0; j--)
	{
		 a = s[j];
		write(1, &a, 1);
		num++;
	}
	return (num);
}
