#include <unistd.h>

void	ft_printnum(int num)
{
	char	n;

	if (num >= 10)
		ft_printnum(num / 10);
	n = num % 10 + '0';
	write(1, &n, 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0) // 3과 5의 공배수 조건 먼저 확인
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0) // 3의 배수
			write(1, "fizz", 4);
		else if (i % 5 == 0) // 5의 배수
			write(1, "buzz", 4);
		else
			ft_printnum(i); // 숫자 출력
		write(1, "\n", 1); // 줄바꿈
		i++;
	}
	return (0);
}
