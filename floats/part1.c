#include "integral.h"
#include "printf.h"

char				*add_zeros(char *s)
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

t_integral		get_integral(int exp, char *mantissa)
{
	t_integral	result;
	t_integral	temp;
	int			i;

	i = 0;
	initialize_integral(&temp);
	initialize_integral(&result);
	if (exp >= 0)
	{
		temp = create_integral(2, exp - i);
		exp = get_length(mantissa);
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
	result.length = set_len_integral(&result);
	return (result);
}

int				get_length(char *str)
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
