/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 01:05:04 by blavonne          #+#    #+#             */
/*   Updated: 2020/07/25 01:05:09 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	put_errmsg_and_exit(char type)
{
	if (type == 'm')
	{
		ft_putstr_fd("Error: not enough memory to process data.\n", 2);
		exit(1);
	}
}
