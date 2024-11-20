#include "stdlib.h"
#include "unistd.h"

#define MAX_SIZE 100000

typedef struct s_stack
{
	int		top;
	int		size;
	char	*data[MAX_SIZE];
}			t_stack;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	int	flag;

	flag = 0;
	if (c == ' ' || c == '\t')
		flag = 1;
	return (flag);
}

void	init(t_stack *stack)
{
	stack->top = -1;
	stack->size = 0;
}

void	push(t_stack *stack, char *word)
{
	if (stack->size < MAX_SIZE)
	{
		stack->data[++stack->top] = word;
		stack->size++;
	}
}

void	ft_rev(char *str)
{
	t_stack	stack;
	int		i;
	int		start;
	char	*word;
	int		wordlen;
	int		j;

	start = 0;
	i = 0;
	init(&stack);
	while (str[i])
	{
		if (is_space(str[i]) || str[i + 1] == '\0')
		{
			if (str[i + 1] == '\0')
				wordlen = i - start + 1;
			else
				wordlen = i - start;
			word = malloc(wordlen + 1);
			if (!word)
				return ;
			j = 0;
			while (j < wordlen)
			{
				word[j] = str[start + j];
				j++;
			}
			word[wordlen] = '\0';
			push(&stack, word);
			start = i + 1;
		}
		i++;
	}
	while (stack.size > 0)
	{
		word = stack.data[stack.top--];
		write(1, word, ft_strlen(word));
		if (stack.size > 1)
			write(1, " ", 1);
		free(word);
		stack.size--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rev(argv[1]);
	write(1, "\n", 1);
	return (0);
}