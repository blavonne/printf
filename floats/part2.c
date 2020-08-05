#include "elephant.h"

void			set_power(t_power *tmp, int exp, int base)
{
	int		overflow_power;

	overflow_power = 62;
	if (base == 10 || base == 5)
		overflow_power = (base == 10) ? 18 : 27;
	tmp->full = 0;
	tmp->rest = 0;
	tmp->rest = exp % overflow_power;
	exp -= tmp->rest;
	if (exp >= overflow_power)
		tmp->full = exp / overflow_power;
}

void			normalize(t_bigint *elephant)
{
	int			i;

	i = 0;
	elephant->length = set_len_big(elephant);
	while (i < elephant->length)
	{
		if (elephant->bigint[i] >= BASE && i < SIZE - 2)
		{
			while (elephant->bigint[i] >= BASE)
			{
				elephant->bigint[i] -= BASE;
				elephant->bigint[i + 1]++;
			}
		}
		else if (elephant->bigint[i] < 0 && i < SIZE - 2)
		{
			while (elephant->bigint[i] < 0 && elephant->bigint[i + 1])
			{
				elephant->bigint[i] += BASE;
				elephant->bigint[i + 1]--;
			}
		}
		i++;
		elephant->length = set_len_big(elephant);
	}
}

t_bigint		initialize_big(t_bigint *elephant)
{
	int		i;

	i = 0;
	while (i < SIZE)
	{
		elephant->bigint[i] = 0;
		i++;
	}
	return (*elephant);
}

int				only_zero(t_bigint *one)
{
	int		i;

	i = 0;
	while (i < SIZE)
	{
		if (one->bigint[i])
			break ;
		i++;
	}
	if (i == SIZE)
		return (1);
	return (0);
}

void			simple_multiply(t_bigint *res, t_bigint *one, t_bigint *two)
{
	int		i;
	int		j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE - i)
		{
			res->bigint[i + j] += one->bigint[i] * two->bigint[j];
			while (res->bigint[i + j] >= BASE && i + j < SIZE)
			{
				res->bigint[i + j + 1]++;
				res->bigint[i + j] -= BASE;
			}
			j++;
		}
		i++;
	}
	normalize(res);
	res->length = set_len_big(res);
}
