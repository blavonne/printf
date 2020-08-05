#ifndef LONGS_ELEPHANT_H
#define LONGS_ELEPHANT_H

# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include "printf.h"

# define	BASE			1000000000//10^9 recommended
# define	SIZE			100
# define	RADIX			"0123456789abcdef"
# define	TWO_62_POWER	4611686018427387904
# define	FIVE_27_POWER	7450580596923828125
# define	TEN_18_POWER	1000000000000000000

typedef struct		s_power
{
	int		full; //сколько нужно полных лонг лонг для числа
	int		rest; // остаточная степень 2, поместится в один лонг лонг
}					t_power;

typedef struct		s_bigint
{
	long long int	bigint[SIZE];
	int				length;
}					t_bigint;


int				set_len_big(t_bigint *elephant);

t_bigint 		multiply(t_bigint *one, t_bigint *two);
t_bigint		addition(t_bigint *one, t_bigint *two);
t_bigint		substraction(t_bigint *one, t_bigint *two);
t_bigint 		division_by_nbr(t_bigint *res, int divider);
t_bigint		multiply_by_nbr(t_bigint *elephant, long long fly);
t_bigint		add_nbr(t_bigint *elephant, long long fly);

void			normalize(t_bigint *elephant);
t_bigint		initialize_big(t_bigint *elephant);
void			set_power(t_power *tmp, int exp, int base);
int				only_zero(t_bigint *one);
char			*add_zeros(char *s);
char			*integral_to_str(t_bigint *one);
t_bigint		create_bigint(int base, int exp);

void			set_zero(t_bigint *nbr, int position);
void			big_cat(t_bigint *dest, t_bigint *src);
t_bigint		get_integral(int exp, char *mantissa);
//int				process_mantissa(t_format *info);

//void			initialize_kar(t_bigint *nbr, t_bigint *pt_1, t_bigint *pt_2);
//void			karatsuba(t_bigint *res, t_bigint *one, t_bigint *two);
#endif
