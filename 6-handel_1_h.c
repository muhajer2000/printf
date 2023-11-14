#include "main.h"

/**
 * writ_number - handel string line to print number
 *
 * @index: characters items.
 * @size: Size  of  specifier string
 * @flags:  int to add and return to string
 * @width: minimum field width
 * @buffer: array of spaces to handle printf file
 * @precision: Precision specification to caluc the real number
 * @is_negative: colect of list of arguments
 *
 * Return: int of number return to chars.
*/
int writ_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char ptr = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		ptr = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (writ_num(index, buffer, flags, width, precision,
		length, ptr, extra_char));
}
