#include "main.h"


/**
 * pr_buffer - Print  character and numbers  After contant to Buffer
 *
 * @buffer: array of characters
 * @int_buffer: represent length of characters to take in index.
 * Return: buffer
*/
void pr_buffer(char buffer[], int *int_buffer)
{
	if (*int_buffer > 0)
		write(1, &buffer[0], *int_buffer);
	*int_buffer = 0;
}
/**
 * _printf - custom printf if function
 *
 * @format: Array of characters index it is take many arguments.
 *
 * Return: print characters and string.
 *
*/
int _printf(const char *format, ...)
{
	int flags, width, precision, size, int_buffer = 0;
	int a, print = 0, add = 0;
	va_list item_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(item_list, format);

	for (a = 0; *format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[int_buffer++] = format[a];
			if (int_buffer == BUFF_SIZE)
				pr_buffer(buffer, &int_buffer);
			add++;
		}
		else
		{
			pr_buffer(buffer, &int_buffer);
			flags = get_flags(format, &a);
			width = get_width(format, &a, item_list);
			precision = get_precision(format, &a, item_list);
			size = get_size(format, &a);
			++a;
			print = handle_printf(format, &a, item_list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			add += print;
		}
	}
	pr_buffer(buffer, &int_buffer);
	va_end(item_list);

	return (add);
}
