#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/* ... Other function implementations ... */

/**
 * print_unsigned - Prints an unsigned integer
 * @args: The va_list containing the integer to be printed
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;

	/* Print individual digits (recursively) */
	if (n / 10 != 0)
		count += print_unsigned_helper(n / 10);

	_putchar('0' + n % 10);
	count++;

	return count;
}

/**
 * print_unsigned_helper - Helper function to print an unsigned integer
 * @n: The integer to be printed
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int print_unsigned_helper(unsigned int n)
{
	int count = 0;

	if (n / 10 != 0)
		count += print_unsigned_helper(n / 10);

	_putchar('0' + n % 10);
	count++;

	return count;
}

/**
 * print_octal - Prints an unsigned integer in octal format
 * @args: The va_list containing the integer to be printed
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char *octal_digits = "01234567";
	char octal_buffer[12]; /* Enough to hold the octal representation of UINT_MAX + 1 */

	int i = sizeof(octal_buffer) - 1;
	octal_buffer[i] = '\0';

	do {
		i--;
		octal_buffer[i] = octal_digits[n % 8];
		n /= 8;
	} while (n > 0);

	_putchar(octal_buffer + i);
	count += sizeof(octal_buffer) - 1 - i;

	return count;
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format (lowercase)
 * @args: The va_list containing the integer to be printed
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int print_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char *hex_digits = "0123456789abcdef";
	char hex_buffer[9]; /* Enough to hold the hexadecimal representation of UINT_MAX + 1 */

	int i = sizeof(hex_buffer) - 1;
	hex_buffer[i] = '\0';

	do {
		i--;
		hex_buffer[i] = hex_digits[n % 16];
		n /= 16;
	} while (n > 0);

	_putchar(hex_buffer + i);
	count += sizeof(hex_buffer) - 1 - i;

	return count;
}

/**
 * print_HEX - Prints an unsigned integer in hexadecimal format (uppercase)
 * @args: The va_list containing the integer to be printed
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int print_HEX(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char *hex_digits = "0123456789ABCDEF";
	char hex_buffer[9]; /* Enough to hold the hexadecimal representation of UINT_MAX + 1 */

	int i = sizeof(hex_buffer) - 1;
	hex_buffer[i] = '\0';

	do {
		i--;
		hex_buffer[i] = hex_digits[n % 16];
		n /= 16;
	} while (n > 0);

	_putchar(hex_buffer + i);
	count += sizeof(hex_buffer) - 1 - i;

	return count;
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++; /* Move past '%' */

			switch (*format)
			{
				case 'c':
					count += print_char(args);
					break;

				case 's':
					count += print_string(args);
					break;

				case '%':
					count += print_percent(args);
					break;

				case 'd': /* Fallthrough */
				case 'i':
					count += print_integer(args);
					break;

				case 'u':
					count += print_unsigned(args);
					break;

				case 'o':
					count += print_octal(args);
					break;

				case 'x':
					count += print_hex(args);
					break;

				case 'X':
					count += print_HEX(args);
					break;

				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
			}
		}

		format++;
	}

	va_end(args);
	return count;
}

