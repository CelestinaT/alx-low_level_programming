#include"main.h"

/** puts_half - print the second half of the string
 * @str: string to work on
 */
void puts_half(char *str)
{
	int i, l;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	l = i + 1;
	if (l % 2 == 0)
	{
		for (i = l / 2; i < l - 1; i++)
		{
			_putchar(str[i]);
		}
	} else
	{
		for (i = (l - 1) / 2; i < l - 1; i++)
		{
			_putchar(str[i]);
		}
	}
	_putchar('\n');
}
