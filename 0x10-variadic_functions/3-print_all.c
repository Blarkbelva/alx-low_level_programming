#include <stdio.h>
#include <stdbool.h>
#include "variadic_functions.h"

/**
 * print_all - main entry
 *
 * @format: take in the format to print
 */

void print_all(const char * const format, ...)
{
	va_list vl;

	char *string;
	int i;

	i = 0;
	va_start(vl, format);
	while (format != NULL && format[i] != '\0')
	{
	switch (format[i])
	{
		case 'i':
			printf("%i", va_arg(vl, int));
			break;
		case 'f':
			printf("%f", va_arg(vl, double));
			break;
		case 'c':
			printf("%c", (char) va_arg(vl, int));
			break;
		case 's':
			string = va_arg(vl, char *);
			if (string == NULL)
			{
				printf("(nil)");
				break;
			}
				printf("%s", string);
				break;
	}
	if ((format[i] == 'c' || format[i] == 'i' || format[i] == 'f' ||
	     format[i] == 's') && format[(i + 1)] != '\0')
		printf(", ");
	i++;
}
printf("\n");
va_end(vl);
}
