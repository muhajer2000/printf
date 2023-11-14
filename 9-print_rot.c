#include "main.h"

/*task 14*/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *s;
	unsigned int a, b;
	int add = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
		s = "(error)";
	for (a = 0; s[a]; a++)
	{
		for (b = 0; input[b]; b++)
		{
			if (input[b] == s[a])
			{
				x = output[b];
				write(1, &x, 1);
				add++;
				break;
			}
		}
		if (!input[b])
		{
			x = s[a];
			write(1, &x, 1);
			add++;
		}
	}
	return (add);
}
