#include "push_swap.h"
int	convert_to_int(const char *str, int i)
{
	int	result;

	result = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
			print_error();
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
			i++;
	res = convert_to_int(str, i);
	return (res * sign);
}