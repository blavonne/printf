#include "elephant.h"
#include "printf.h"

char			*add_zeros(char *s)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	if (!(res = ft_strnew(9)))
		exit(-1);
	while (i < 9 - len)
	{
		res[i] = '0';
		i++;
	}
	while (i < 9)
		res[i++] = s[j++];
	free(s);
	return (res);
}



int					set_len_big(t_bigint *elephant)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < SIZE)
	{
		if (elephant->bigint[i])
			len = i + 1;
		i++;
	}
	return (len);
}

t_bigint			create_bigint(int base, int exp)//возвращает число в степени
// экспоненты
{
	t_power		power;
	t_bigint	one;
	t_bigint	two;
	long long	temp;

	set_power(&power, exp, base);
	initialize_big(&one);
	initialize_big(&two);
	temp = TWO_62_POWER;
	if (base == 10 || base == 5)
		temp = (base == 10) ? TEN_18_POWER : FIVE_27_POWER;
	if (power.full)
	{
		add_nbr(&one, temp);
		power.full--;
	}
	else if (!power.full && power.rest)
	{
		temp = pow(base, power.rest);
		add_nbr(&one, temp);
		set_len_big(&one);
		power.rest = 0;
	}
	while (power.full)
	{
		add_nbr(&two, temp);
		one = multiply(&one, &two);
		initialize_big(&two);
		power.full--;
	}
	if (power.rest)
	{
		temp = pow(base, power.rest);
		add_nbr(&two, temp);
		one = multiply(&one, &two);
		power.rest = 0;
	}
	if (!exp)
		one.bigint[0] = 1;
	return (one);
}

t_bigint		get_integral(int exp, char *mantissa)
{
	t_bigint	result;
	t_bigint	temp;
	int			i;

	i = 0;
	initialize_big(&temp);
	initialize_big(&result);
	if (exp >= 0)
	{
		temp = create_bigint(2, exp - i);
		exp = get_power(mantissa);
		while (i < exp)
		{
			if (mantissa[i] == '1')
				result = addition(&result, &temp);
			temp = division_by_nbr(&temp, 2);
			i++;
		}
		if (mantissa[i] == '1')
			result.bigint[0]++;
	}
	result.length = set_len_big(&result);
	return (result);
}

int		get_power(char *str)
{
	int			i;
	int			end;

	i = 0;
	end = 0;
	while (str && str[i])
	{
		if (str[i] == '1')
			end = i + 1;
		i++;
	}
	return (end);
}
