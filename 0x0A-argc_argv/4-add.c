#include "main.h"

/**
 * pnum - print num
 * @n : int
 */
void pnum(int n)
{
	if (n < 0)
	{
		n = -n;
		_putchar('-');
	}
	if (n >= 10)
		pnum(n / 10);
	_putchar('0' + n % 10);
}
/**
 * _pow - power of an integer
 * @n: int
 * @e: exp
 *
 * Return: pow of int
 */
int _pow(int n, int e)
{
	if (e == 0)
		return (1);
	return (n * _pow(n, e - 1));
}

/**
 * len - length of a str
 * @s: str
 *
 * Return: int
 */
int len(char *s)
{
	if (*s == 0)
		return (0);
	return (1 + len(s + 1));
}
/**
 * _atoi - ret int
 * @s: str
 *
 * Return: int
 */
int _atoi(char *s)
{
	int r = 1;

	if (*s == 0)
		return (0);

	if (*s == '-')
	{
		++s;
		r = -1;
	}

	r *= (*s - '0') * _pow(10, len(s) - 1) + _atoi(s + 1);

	return (r);
}

/**
 * main - display
 * @argc: agr count
 * @argv: arg values
 *
 * Return: 0;
 */
int main(int argc, char *argv[])
{
	int i = 1;
	int r = 0;

	while (i < argc)
	{
		char *ptr = argv[i];
		int valide = 1;

		while (*ptr != 0)
			if (*ptr < '0' || *ptr > '9')
				valide = 0;

		if (!valide)
		{
			char *str = "Error";

			while (*str != 0)
			{
				_putchar(*str);
				++str;
			}
			_putchar('\n');
			return (1);
		}

		r += _atoi(argv[i]);
		++i;
	}
	pnum(r);
	_putchar('\n');
	return (0);
}