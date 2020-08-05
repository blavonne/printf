/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 05:59:00 by blavonne          #+#    #+#             */
/*   Updated: 2020/07/24 03:58:29 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		floats(t_format *info, va_list *arg)
{
	int			count;
	double		d;
	long double	ld;
	char		*res;

	count = 0;
	ld = 0;
	res = NULL;
	if (info->length[0] && info->length[0] == 'L')
		ld = va_arg(*arg, long double);
	else if (!info->length[0])
	{
		d = va_arg(*arg, double);
		ld = d;
	}
	info->r = initialize_float(ld);
	if (info->precision < 0)
		info->precision = 6;
	res = get_arg_f(info);
	if (res)
	{
		count = ft_strlen(res);
		ft_printf("%s", res);
		free(res);
	}
	return (count);
}
