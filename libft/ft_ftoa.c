#include "../includes/printf.h"

char	*ft_ftoa(long double real, int precision)
{
	char	*res;
	long	temp;
	int		len;
	int		sign;
	int 	after_point;

	after_point = 0;
	res = NULL;
	len = 1;
	sign = (real < 0 ? -1 : 1);
	real *= sign;
	temp = (long int)real;
	while ((temp = temp / 10))
		len++;
	while (after_point < precision)
	{
		len++;
		real = real * 10;
		after_point++;
	}
	if (!(res = ft_strnew(len)))
		put_errmsg_and_exit('m');
	while (len--)
	{
		res[len] = (int)((long int)real % 10) + 48;
		real /= 10;
		if (sign == -1)
		{
			res[0] = '-';
			break ;
		}
	}
	res[0] = sign < 0 ? '-' : res[0];
	return (res);
}
