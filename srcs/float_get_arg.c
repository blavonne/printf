/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_get_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:58:55 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:58:56 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_round_f(t_integral *z, t_fractional *frac, t_format *info)
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
		if ((!info->precision && (frac->bigint[0] > 5 || (frac->bigint[0]\
		== 5 && frac->length > 1))) || frac->bigint[0] >= 10 || (z->length &&\
		frac->bigint[0] == 5 && z->bigint[0] % 2))
		{
			frac->bigint[0] >= 10 ? frac->bigint[0] -= 10 : 0;
			z->bigint[0]++;
			normalize_integral(z);
		}
		while (i < frac->length)
			frac->bigint[i++] = 0;
		frac->length = set_len_frac(frac);
	}
}

char			*get_arg_f(t_format *info)
{
	t_integral		integral;
	t_fractional	fractional;
	char			*z;
	char			*r;
	char			*res;

	res = NULL;
	z = NULL;
	r = NULL;
	if ((res = check_inf_nan(info)))
		return (res);
	integral = get_integral(info->r.exponent, info->r.mantissa);
	fractional = get_fractional(info->r.mantissa, info->r.exponent);
	ft_round_f(&integral, &fractional, info);
	z = integral_to_str(&integral);
	r = frac_to_str(&fractional, info->precision, info->flags);
	res = r ? ft_strjoin(z, r) : ft_strjoin(z, "");
	free(z);
	free(r);
	return (res);
}
