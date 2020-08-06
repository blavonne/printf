/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_flags_cases.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:58:47 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:58:48 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*flg_others_case_f(t_format *info, char *arg, char *res)
{
	int		i;
	int		j;
	char	sign;

	i = 0;
	j = 0;
	sign = 0;
	info->flags & FLG_PLUS ? sign = '+' : 0;
	info->flags & FLG_SPACE ? sign = ' ' : 0;
	info->r.sign == 1 ? sign = '-' : 0;
	j = sign ? 1 : 0;
	while (info->width != -1 && j + (int)ft_strlen(arg) < info->width--)
		res[i++] = ' ';
	sign && res ? res[ft_strlen(res)] = sign : 0;
	res = ft_strcat(res, arg);
	return (res);
}

static char		*flg_zero_case_f(t_format *info, char *arg, char *res)
{
	int		i;
	int		j;
	char	sign;

	i = 0;
	j = 0;
	sign = 0;
	info->flags & FLG_PLUS ? sign = '+' : 0;
	info->flags & FLG_SPACE ? sign = ' ' : 0;
	info->r.sign == 1 ? sign = '-' : 0;
	sign && res ? res[0] = sign : 0;
	sign ? (i = 1) : 0;
	j = sign ? 1 : 0;
	while (info->width != -1 && j + (int)ft_strlen(arg) < info->width--)
		res[i++] = '0';
	res = ft_strcat(res, arg);
	return (res);
}

static char		*flg_minus_case_f(t_format *info, char *arg, char *res)
{
	int		i;
	char	sign;

	i = 0;
	sign = 0;
	info->flags & FLG_PLUS ? sign = '+' : 0;
	info->flags & FLG_SPACE ? sign = ' ' : 0;
	info->r.sign == 1 ? sign = '-' : 0;
	sign && res ? res[0] = sign : 0;
	res = ft_strcat(res, arg);
	i = ft_strlen(res);
	while (info->width != -1 && (int)ft_strlen(res) < info->width)
	{
		res[i++] = ' ';
		info->width--;
	}
	return (res);
}

char		*process_flags_f(t_format *info, char *arg)
{
	int			len;
	char		*res;

	len = ft_strlen(arg);
	if (info->flags & FLG_PLUS || info->flags & FLG_SPACE || info->r.sign ==\
	'1')
		len++;
	len = info->width > len ? info->width : len;
	res = NULL;
	if (!(res = ft_strnew(len)))
		put_errmsg_and_exit('m');
	if (info->flags & FLG_MINUS)
		res = flg_minus_case_f(info, arg, res);
	else if (info->flags & FLG_ZERO)
		res = flg_zero_case_f(info, arg, res);
	else
		res = flg_others_case_f(info, arg, res);
	free(arg);
	return (res);
}
