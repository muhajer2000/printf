#include "main.h"

/*5-print_po.c(handel pointer)*/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int printf_pointer(va_list item, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_a = 0;
	char space = ' ';
	int index = BUFF_SIZE - 2, len = 2, pad_start = 1; /* length=2, for '0x' */
	unsigned long num_addrss;
	char map[] = "0123456789abcdef";
	void *ad = va_arg(item, void *);

	UNUSED(width);
	UNUSED(size);

	if (ad == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrss = (unsigned long)ad;

	while (num_addrss > 0)
	{
		buffer[index--] = map[num_addrss % 16];
		num_addrss /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		space = '0';
	if (flags & F_PLUS)
		extra_a = '+', len++;
	else if (flags & F_SPACE)
		extra_a = ' ', len++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (writ_pointer(buffer, index, len,
		width, flags, space, extra_a, pad_start));
}
