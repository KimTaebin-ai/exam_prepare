#include "stdlib.h"

int	*ft_range(int start, int end)
{
	int	i;
	int	*data;
	int	size;

	i = 0;
	if (start <= end)
	{
		size = (end - start) + 1;
	}
	else
		size = (start - end) + 1;
	data = (int *)malloc(sizeof(int) * size);
	if (start <= end)
	{
		while (start <= end)
			data[i++] = start++;
	}
	else
	{
		while (start >= end)
			data[i++] = start--;
	}
	return (data);
}
