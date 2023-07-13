#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * _rev - rev a string
 * @s: str
 */
void _rev(char *s)
{
	int size = strlen(s);
	int i = 0;

	while (i < size / 2)
	{
		char tmp = s[i];

		s[i] = s[size - 1 - i];
		s[size - 1 - i] = tmp;
		++i;
	}
}
/**
 * array - array of chars init
 * @size: size
 *
 * Return: ptr
 */
char *array(int size)
{
	char *ptr = 0;
	int i = 0;

	ptr = malloc(size + 1);
	ptr[size] = 0;

	while (i < size)
	{
		ptr[i] = '0';
		++i;
	}
	return (ptr);
}
/**
 * _add - addition
 * @n1: num 1
 * @n2: num 2
 *
 * Return: ptr
 */
char *_add(char *n1, char *n2)
{
	unsigned long size = 0;
	char *ptr = 0;
	unsigned long i = 0;
	int carry = 0;

	size = strlen(n1) > strlen(n2) ? strlen(n1) : strlen(n2);
	ptr = array(size);

	while (i < size || carry)
	{
		int r = 0;

		if (i < strlen(n1))
			r += n1[i] - '0';
		if (i < strlen(n2))
			r += n2[i] - '0';
		if (carry)
			r += carry;
		if (i >= size)
		{
			ptr = realloc(ptr, size + 2);
			ptr[size + 1] = 0;
			ptr[size] = '0';
		}

		carry = r / 10;
		ptr[i] =  r % 10 + '0';
		++i;
	}
	return (ptr);
}
/**
 * _swap - swap add
 * @ptr1: ptr 1
 * @ptr2: ptr 2
 */
void _swap(void *ptr1, void *ptr2)
{
	void *tmp = 0;

	tmp = ptr2;
	ptr2 = ptr1;
	ptr1 = tmp;
}
/**
 * _mul - funny mul
 * @n1: num 1
 * @n2: num 2
 *
 * Return: ptr
 */
char * _mul(char *n1, char *n2)
{
	int size = 0;
	char *ptr = 0;
	char *mul = 0;
	unsigned long i = 0;
	unsigned long j = 0;
	int carry = 0;

	if (strlen(n1) < strlen(n2))
		_swap(n1, n2);
	size = strlen(n1) > strlen(n2) ? strlen(n1) : strlen(n2);
	ptr = array(size);
	while (i < strlen(n2))
	{
		j = 0;
		mul = array(size + i);
		while (j < strlen(n1) || carry)
		{
			int r = 0;

			if (j < strlen(n1))
				r += (n1[j] - '0') * (n2[i] - '0');
			if (carry)
				r += carry;
			if (j >= strlen(n1))
			{
				mul = realloc(mul, size + i + 2);
				mul[size + i + 1] = 0;
				mul[size + i] = '0';
			}
			carry = r / 10;
			mul[j + i] =  r % 10 + '0';
			++j;
		}
		ptr = _add(ptr, mul);
		free(mul);
		++i;
	}
	return (ptr);
}

/**
 * main - main program
 * @argc: args count
 * @argv: agrv
 *
 * Return: status
 */
int main(int argc, char *argv[])
{
	int i = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	i = 1;
	while (i < 3)
	{
		if (strlen(argv[i]) != strspn(argv[i], "0123456789"))
		{
			printf("Error\n");
			exit(98);
		}
		++i;
	}

	_rev(argv[1]);
	_rev(argv[2]);
	printf("%s\n", _mul(argv[i], argv[2]));

	return (0);

}