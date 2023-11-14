#include"main.h"

/*(7-width_per.c)*/
 /*flags percition width**/
/************************************************************
 *
 * get_flags - Calculates active flags.
 * @format: Formatted string in which to print the arguments.
 * @i: take a parameter.
 * Return: Flags
 *
 *************************************************************/
int get_flags(const char *format, int *a)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int i, curr_j;
	int flags = 0;
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};


	for (curr_j = *a + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[curr_j] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*a = curr_j - 1;

	return (flags);
}
/*get width*/

/**
 * get_width - Calculates the width for printing.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *a, va_list fm_item)
{

	int width = 0;
    int cur_j;

	for (cur_j = *a + 1; format[cur_j] != '\0'; cur_j++)
	{
		if (is_digit(format[cur_j]))
		{
			width *= 10;
			width += format[cur_j] - '0';
		}
		else if (format[cur_j] == '*')
		{
			cur_j++;
			width = va_arg(fm_item, int);
			break;
		}
		else
			break;
	}

	*a = cur_j - 1;

	return (width);
}
/*grt percs*/
/**
 * get_precision - Calculates the precision for printing.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *j, va_list fm_item)
{

	int prec = -1;
    int cur_j = *j + 1;

	if (format[cur_j] != '.')
		return (prec);

	prec = 0;

	for (cur_j += 1; format[cur_j] != '\0'; cur_j++)
	{
		if (is_digit(format[cur_j]))
		{
			prec *= 10;
			prec += format[cur_j] - '0';
		}
		else if (format[cur_j] == '*')
		{
			cur_j++;
			prec = va_arg(fm_item, int);
			break;
		}
		else
			break;
	}

	*j = cur_j - 1;

	return (prec);
}
/*get size*/
/**
 * get_size - Calculates the size to cast the argument.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *a)
{
	int curr_a = *a + 1;
	int size = 0;
/*handel h and I*/
	if (format[curr_a] == 'l')
		size = S_LONG;
	else if (format[curr_a] == 'h')
		size = S_SHORT;

	if (size == 0)
		*a = curr_a - 1;
	else
		*a = curr_a;

	return (size);
}
