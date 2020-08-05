/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:17:13 by blavonne          #+#    #+#             */
/*   Updated: 2020/07/24 03:58:29 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strnew(size_t size)
{
	char	*obj;

	if (size + 1 == 0)
		return (NULL);
	obj = 0;
	if (!(obj = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(obj, size + 1);
	return (obj);
}
