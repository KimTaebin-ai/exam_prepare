#include "stdio.h"
#include "stdlib.h"

void	ft_pgcd(char *num1, char *num2)
{
	int	n1;
	int	n2;
	int	temp;

	n1 = atoi(num1);
	n2 = atoi(num2);
	while (n2 != 0)
	{
		temp = n1 % n2;
		n1 = n2;
		n2 = temp;
	}
	printf("%d", n1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_pgcd(argv[1], argv[2]);
	printf("\n");
	return (0);
}