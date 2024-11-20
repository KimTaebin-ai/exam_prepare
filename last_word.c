#include "unistd.h"

int	is_space(char c)
{
	int	flag;

	flag = 0;
	if (c == '\t' || c == ' ')
		flag = 1;
	return (flag);
}

void	ft_last_word(char *str)
{
	int		i;
	int		start;
	char	*word;
	int		word_len;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0')
		{
			word_len = i - start;
		}
		if (is_space(str[i]))
			start = i + 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}