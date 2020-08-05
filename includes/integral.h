#ifndef INTEGRAL_H
#define INTEGRAL_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include "printf.h"

# define	BASE			1000000000//10^9 recommended
# define	SIZE			549
# define	COUNT_DIGITS	9
# define	RADIX			"0123456789abcdef"

typedef struct		s_power
{
	int				full;
	int				rest;
}					t_power;

typedef struct		s_integral
{
	long long int	bigint[SIZE];
	int				length;
}					t_integral;

t_integral			multiply(t_integral *one, t_integral *two);
t_integral			addition(t_integral *one, t_integral *two);
t_integral			substraction(t_integral *one, t_integral *two);
t_integral			division_by_nbr(t_integral *res, int divider);
t_integral			multiply_by_nbr(t_integral *elephant, long long fly);
t_integral			add_nbr(t_integral *elephant, long long fly);

t_integral			create_integral(int base, int exp);
t_integral			initialize_integral(t_integral *elephant);
void				normalize_integral(t_integral *elephant);
int					set_len_integral(t_integral *elephant);

t_integral			get_integral(int exp, char *mantissa);
char				*integral_to_str(t_integral *one);

#endif
