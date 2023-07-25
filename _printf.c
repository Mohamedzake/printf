#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 *
 * Return: On success, the number of characters written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints a character
 * @args: The va_list that contains the character to print
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return 1;
}

/**
 * print_string - Prints a string
 * @args: The va_list that contains the string to print
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}

	return count;
}

/**
 * print_percent - Prints a percent character
 * @args: The va_list (unused)
 *
 * Return: Always 1 (as only one character is printed)
 */
int print_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return 1;
}

/**
 * print_integer - Prints an integer
 * @args: The va_list that contains the integer to print
 *
 * Return: The number of characters printed.
 */
int print_integer(va_list args)
{
    int n = va_arg(args, int);
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }

    if (n / 10 != 0)
    {
        count += print_integer(args);
    }

    count += _putchar('0' + n % 10);

    return count;
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;

			if (*format == '\0')
				break;

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
			case 'i':
			case 'd':
				count += print_integer(args);
				break;
			default:
				_putchar('%');
				_putchar(*format);
				count += 2;
				break;
			}
		}

		format++;
	}

	va_end(args);
	return count;
}

