#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Writes a character to the standard output (file descriptor 1)
 * @c: The character to write
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
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
					_putchar(va_arg(args, int));
					count++;
					break;

				case 's':
				{
					char *str = va_arg(args, char*);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						_putchar(*str);
						str++;
						count++;
					}
					break;
				}

				case '%':
					_putchar('%');
					count++;
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

