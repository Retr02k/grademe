#include <unistd.h>

int main(int argc, char **argv)
{
	int	i = 0;
	int	j = argc - 1;

	if (argc > 1)
	{
		while (argv[j][i])
		{
			write(1, &argv[j][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
