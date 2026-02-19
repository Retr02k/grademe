#include <unistd.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return 1;
	return 0;
}
int is_letter(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	return 0;
}

char put_lowercase(char c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

char put_uppercase(char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

int main(int ac, char **av)
{
	int i = 1;
	int j = 0;
	char c;
	
	if (ac > 1)
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (is_letter(av[i][j]))
				{
					if (is_space(av[i][j + 1]) || av[i][j + 1] == '\0')
						c = put_uppercase(av[i][j]);
					else
						c = put_lowercase(av[i][j]);
				}
				else
					c = av[i][j];
				write(1, &c, 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}