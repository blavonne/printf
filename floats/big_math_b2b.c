#include "elephant.h"

t_bigint		multiply(t_bigint *one, t_bigint *two)
{
	t_bigint	res;
	int			i;
	int			j;

	i = 0;
	res = initialize_big(&res);
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE - i)
		{
			res.bigint[i + j] += one->bigint[i] * two->bigint[j];
			normalize(&res);
			j++;
		}
		i++;
	}
	normalize(&res);
	res.length = set_len_big(&res);
	return (res);
}

t_bigint		addition(t_bigint *one, t_bigint *two)
{
	t_bigint	left;
	t_bigint	right;
	int			i;

	i = 0;
	one->length = set_len_big(one);
	two->length = set_len_big(two);
	initialize_big(&left);
	left = (one->length > two->length) ? *one : *two;
	right = (one->length <= two->length) ? *one : *two;
	while (i < right.length)
	{
		left.bigint[i] += right.bigint[i];
		i++;
	}
	normalize(&left);
	return (left);
}

t_bigint		substraction(t_bigint *one, t_bigint *two)
{
	t_bigint	left;
	t_bigint	right;
	int			i;

	i = 0;
	initialize_big(&left);
	left = (one->length > two->length) ? *one : *two;
	right = (one->length < two->length) ? *one : *two;
	while (i < right.length)
	{
		left.bigint[i] -= right.bigint[i];
		i++;
	}
	normalize(&left);
	return (left);
}
