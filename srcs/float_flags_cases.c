#include "printf.h"

char			*check_inf_nan(t_format *info)
{
	char		*res;

	res = NULL;
	if (info->r.exponent == INF && get_power(info->r.mantissa) == 1)
	{
		if (!(res = ft_strnew(3)))
			put_errmsg_and_exit('m');
		res = ft_strcpy(res, "inf");
	}
	if (info->r.exponent == INF && get_power(info->r.mantissa) > 1)
	{
		if (!(res = ft_strnew(3)))
			put_errmsg_and_exit('m');
		res = ft_strcpy(res, "nan");
	}
	return (res);
}

char			*add_zeros_f(char *tmp, t_format *info)
{
	char	*zeros;
	char	*res;

	if (!(zeros = ft_strnew(info->precision - ft_strlen(tmp) + 1)))
		put_errmsg_and_exit('m');
	zeros = ft_memset(zeros, '0', info->precision - ft_strlen(tmp) + 1);
	res = ft_strjoin(tmp, zeros);
	free(tmp);
	free(zeros);
	return (res);
}

char			*fractional_to_str(t_fractional *snake, t_format *info)
{
	int			i;
	char		*res;
	int			j;

	i = 0;
	j = 0;
	if (!(res = ft_strnew(snake->length + 1)))
		put_errmsg_and_exit('m');
	ft_bzero(res, snake->length + 1);
	if (info->precision || info->flags & FLG_NBRSIGN)
		res[i++] = '.';
	if (info->precision)
	{
		while ((j < snake->length && snake->length <= info->precision) ||\
		(j < info->precision && snake->length > info->precision))
			res[i++] = (char)(snake->bigint[j++] + 48);
		if (info->precision > snake->length)
			res = add_zeros_f(res, info);
	}
	return (res);
}


void			ft_round_f(t_bigint *z, t_fractional *frac, t_format *info)
{
	int		i;

	i = info->precision;
	if (info->precision < frac->length && frac->bigint[info->precision] >= 5)
	{
		if (info->precision)
		{
			frac->bigint[info->precision - 1]++;
			normalize_frac(frac);
		}
		if (frac->bigint[0] >= 10 || !info->precision)
		{
			frac->bigint[0] >= 10 ? frac->bigint[0] -= 10 : 0;
			z->bigint[0]++;
			normalize(z);
		}
		while (i < frac->length)
			frac->bigint[i++] = 0;
		frac->length = set_len_frac(frac);
	}
}

char			*integral_to_str(t_bigint *one)
{
	int			i;
	char		*buf;
	char		*tmp;

	one->length = set_len_big(one);
	i = one->length - 1;
	if (!one->length)
	{
		if (!(buf = ft_strnew(1)))
			put_errmsg_and_exit('m');
		buf[0] = '0';
		return (buf);
	}
	if (!(buf = ft_strnew(one->length * 9)))
		put_errmsg_and_exit('m');
	ft_bzero(buf, one->length * 9);
	while (i >= 0)
	{
		tmp = itoa_ll(one->bigint[i]);
		if (i && i != one->length - 1 && one->bigint[i] && ft_strlen(tmp) != 9)
			tmp = add_zeros(tmp);
		buf = ft_strcat(buf, tmp);
		free(tmp);
		i--;
	}
	return (buf);
}

char			*get_arg_f(t_format *info)
{
	t_bigint		integral;
	t_fractional	fractional;
	char			*z;
	char			*r;
	char			*res;

	if ((res = check_inf_nan(info)))
		return (res);
	integral = get_integral(info->r.exponent, info->r.mantissa);
	fractional = get_fractional(info->r.mantissa, info->r.exponent);
	ft_round_f(&integral, &fractional, info);
	z = integral_to_str(&integral);
	r = fractional_to_str(&fractional, info);
	res = r ? ft_strjoin(z, r) : ft_strjoin(z, "");
	free(z);
	free(r);
	return (res);
}