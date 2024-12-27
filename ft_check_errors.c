#include "push_swap.h"

int ft_check_for_non_integers(const char *s)
{
	int	i;

	i = 0;
    while (s[i])
    {
		if (s[i] == '-' && i == 0)
			i++;
        else if (s[i] < 48 || s[i] > 57)
            return (0);
		else
        	i++;
    }
    return (1);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (sign * result);
}