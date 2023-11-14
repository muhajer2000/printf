#include "main.h"

/**
 * handle_print - function hendel printf file argument
 *
 * @fmt: Formatted string in which to print the arguments.
 *
 * @index: character number in represnt
 * @fm_list: characters items.
 * @size: Size  of  specifier string
 * @flags:  int to add and return to string
 * @width: minimum field width
 * @buffer: array of spaces to handle printf file
 * @precision: Precision specification to caluc the real number
 *
 * Return: 1 or 2;
 *
*/
int handle_printf(const char *fmt, int *index, va_list fm_list, char buffer[],

	int flags, int width, int precision, int size)

{

	int a, unknow_len = 0, printed_chars = -1;

	fm_item fu_item[] = {

		{'c', printf_char}, {'s', printf_str}, {'%', printf_percent},

		{'i', printf_intger}, {'d', printf_intger}, {'b', printf_binry},

		{'u', printf_unsigned}, {'o', printf_octal}, {'x', printf_hexadecimal},

		{'X', printf_hexa_upper}, {'p', printf_pointer}, {'S', print_non_printable},

		{'r', print_rev}, {'R', print_rot13}, {'\0', NULL}

	};

	for (a = 0; fu_item[a].fmt != '\0'; a++)

		if (fmt[*index] == fu_item[a].fmt)

			return (fu_item[a].fu(fm_list, buffer, flags, width, precision, size));


	if (fu_item[a].fmt == '\0')

	{
		if (fmt[*index] == '\0')

			return (-1);

		unknow_len += write(1, "%%", 1);

		if (fmt[*index - 1] == ' ')

			unknow_len += write(1, " ", 1);

		else if (width)
		{
			--(*index);

			while (fmt[*index] != ' ' && fmt[*index] != '%')

				--(*index);

			if (fmt[*index] == ' ')

				--(*index);

			return (1);

		}

		unknow_len += write(1, &fmt[*index], 1);
		return (unknow_len);
	}

	return (printed_chars);
}
