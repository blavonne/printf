/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:24:41 by blavonne          #+#    #+#             */
/*   Updated: 2020/07/25 19:54:24 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		nbr_len_int_l(t_format *info)
{
	long		temp;
	int			len;
	char		*res;

	res = NULL;
	temp = info->z.l;
	if (!(res = itoa_l(temp)))
		put_errmsg_and_exit('m');
	len = (int)ft_strlen(res);
	return (len);
}

int		nbr_len_uint_l(t_format *info, int base)
{
	unsigned long	temp;
	int				len;
	char			*res;

	res = NULL;
	temp = info->z.lu;
	if (!(res = itoa_lu(temp, base)))
		put_errmsg_and_exit('m');
	len = (int)ft_strlen(res);
	return (len);
}
