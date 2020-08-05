#include "elephant.h"

t_bigint 			add_nbr(t_bigint *elephant, long long fly)
{
	elephant->bigint[0] += fly;
	normalize(elephant);
	return (*elephant);
}

t_bigint			multiply_by_nbr(t_bigint *elephant, long long fly)
{
	int		i;

	i = 0;
	elephant->length = set_len_big(elephant);
	while (i < elephant->length)
	{
		elephant->bigint[i] *= fly;
		normalize(elephant);
		i++;
	}
	return (*elephant);
}

t_bigint 			division_by_nbr(t_bigint *res, int divider)
{
	int		i;

	i = res->length - 1;
	while (i >= 0)
	{
		if (i)
			res->bigint[i - 1] += (res->bigint[i] % divider) * BASE;
		res->bigint[i] /= divider;
		i--;
	}
	normalize(res);
	return (*res);
}
