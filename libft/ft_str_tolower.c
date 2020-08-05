/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:13:53 by blavonne          #+#    #+#             */
/*   Updated: 2020/07/24 03:58:29 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_str_tolower(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (char)ft_tolower(str[i]);
		i++;
	}
}
