#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0;
	char ptr = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		ptr = '0';

	buffer[a++] = c;
	buffer[a] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)

			buffer[BUFF_SIZE - a - 2] = ptr;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/*hamdel number*/
/*write to call buffer*/
/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int writ_num(int index, char buffer[], int flags, int width, int pre,
	int length, char ptr, char extra_a)
{
	int j, ptr_start = 1;

	if (pre == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
			return (0); /* printf(".0d", 0)  no char is printed */
	if (pre == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = ptr = ' '; /* width is displayed with padding ' ' */
	if (pre > 0 && pre < length)
		ptr = ' ';
	while (pre > length)
		buffer[--index] = '0', length++;
	if (extra_a != 0)
		length++;
	if (width > length)
	{
		for (j = 1; j < width - length + 1; j++)
			buffer[j] = ptr;
		buffer[j] = '\0';
		if (flags & F_MINUS && ptr == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_a)
				buffer[--index] = extra_a;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], j - 1));
		}
		else if (!(flags & F_MINUS) && ptr == ' ')/* extra char to left of buff */
		{
			if (extra_a)
				buffer[--index] = extra_a;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && ptr == '0')/* extra char to left of padd */
		{
			if (extra_a)
				buffer[--ptr_start] = extra_a;
			return (write(1, &buffer[ptr_start], j - ptr_start) +
					write(1, &buffer[index], length - (1 - ptr_start)));
		}
	}
	if (extra_a)
		buffer[--index] = extra_a;
	return (write(1, &buffer[index], length));
}
/*hendl negtive*/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int writ_unsgned(int is_negative, int index,
	char buffer[], int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1, a = 0;
	char pa = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < len)
		pa = ' ';

	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pa = '0';

	if (width > len)
	{
		for (a = 0; a < width - len; a++)
			buffer[a] = pa;
		buffer[a] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], a));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[index], len));
		}
	}
	return (write(1, &buffer[index], len));
}
/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
*/
int writ_pointer(char buffer[], int index, int length,
	int width, int flags, char ptr, char extra_p, int ptr_start)
{
	int a;

	if (width > length)
	{
		for (a = 3; a < width - length + 3; a++)
				buffer[a] = ptr;
			buffer[a] = '\0';
		if (flags & F_MINUS && ptr == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_p)
				buffer[--index] = extra_p;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & F_MINUS) && ptr == ' ')/* extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_p)
				buffer[--index] = extra_p;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && ptr == '0')/* extra char to left of padd */
		{
			if (extra_p)
				buffer[--ptr_start] = extra_p;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[ptr_start], a - ptr_start) +
		
		}		write(1, &buffer[index], length - (1 - ptr_start) - 2);
		
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_p)
		buffer[--index] = extra_p;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
	}

