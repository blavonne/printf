/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:48:55 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:54:23 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*itoa_ll(long long int decimal)
{
	int			len;
	long long	temp;
	char		*res;
	int			index;

	len = 1;
	temp = decimal;
	while ((temp = temp / 10))
		len++;
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		index = ft_abs((int)(decimal % 10));
		res[len] = RADIX[index];
		decimal /= 10;
	}
	return (res);
}

char	*itoa_llu(unsigned long long int decimal, int base)
{
	int						len;
	unsigned long long		temp;
	char					*res;
	int						index;

	len = 1;
	temp = decimal;
	while ((temp = temp / base))
		len++;
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		index = ft_abs((int)(decimal % base));
		res[len] = RADIX[index];
		decimal /= base;
	}
	return (res);
}
