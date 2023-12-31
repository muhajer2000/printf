#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1
/**
 * struct f_list - Struct list of forma.
 * @f_list: The struct of format list.
 * @func: The function pointer associated.
*/
struct fmt
{
	char fmt;
	 int (*fu)(va_list, char[], int, int, int, int);
};

/**
 *  * typedef struct f_list fm_item - Struct op
 *   *
 *    * @fmt: The format.
 *     * @fm_t: The function associated.
 *      */
typedef struct fmt fm_item; /*list*/

int _printf(const char *format, ...);
int handle_printf(const char *fmt, int *i,
va_list fm_item, char buffer[], int flags, int width, int precision, int size);
/* Funtions to print chars and strings */
int printf_char(va_list item, char buffer[],
	int flags, int width, int precision, int size);            /*type : print char*/
	int printf_str(va_list item, char buffer[],
	int flags, int width, int precision, int size);             /*printf string*/
	int printf_percent(va_list item, char buffer[],
	int flags, int width, int precision, int size);
/* Functions to print numbers */
	int printf_intger(va_list item, char buffer[],
	int flags, int width, int precision, int size);                /*print_int*/
int printf_binry(va_list item, char buffer[],
	int flags, int width, int precision, int size);              /*print binary*/
int printf_unsigned(va_list item, char buffer[],
	int flags, int width, int precision, int size);                     /*print_unsiinged*/
int printf_octal(va_list item, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexadecimal(va_list item, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexa_upper(va_list item, char buffer[],
	int flags, int width, int precision, int size);

	int printf_hexa(va_list item, char map_to[],
    char buffer[], int flags, char flag_ch, int width, int precision, int size);   /*lower*/
/* Function to print non printable characters */
int print_non_printable(va_list item, char buffer[],
		int flags, int width, int precision, int size);

/* Funcion to print memory address */
int printf_pointer(va_list item, char buffer[],
	int flags, int width, int precision, int size);

	/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *a);
int get_width(const char *format, int *a, va_list fm_item);
int get_precision(const char *format, int *a, va_list fm_item);
int get_size(const char *format, int *a);

/*Function to print string in reverse*/
    /*print reverce*/
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

	/*Function to print a string in rot 13*/
	/*rot13string*/
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

	/* width handler */                                    /*done*/
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int writ_number(int is_positive, int index, char buffer[],
	int flags, int width, int precision, int size);                  /*write number*/
int writ_num(int index, char buffer[], int flags, int width, int precision,
	int length, char ptr, char extra_p);
int writ_pointer(char buffer[], int index, int length,
	int width, int flags, char ptr, char extra_p, int ptr_start);
    /*write*/
	int writ_unsgned(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size);
/****************** UTILS ******************/
int is_printable(char); /*is_print adble*/
int append_hexa_code(char, char[], int);
int is_digit(char);  /*is digit*/

long int convert_size_number(long int num, int size);                 /*convert size number*/
long int convert_size_unsignd(unsigned long int num, int size);      /*covert unsgnd*/

#endif
