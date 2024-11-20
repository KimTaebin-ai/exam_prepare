#include "stdlib.h"
#include "unistd.h"

void	ft_camel(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			c = str[i] + 32;
			write(1, "_", 1);
			write(1, &c, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_camel(argv[1]);
	write(1, "\n", 1);
	return (0);
}