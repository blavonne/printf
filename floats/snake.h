#ifndef FRACTIONAL_H
#define FRACTIONAL_H

# include "printf.h"

# define			TAIL_SIZE		100


typedef struct		s_fractional
{
	int		bigint[TAIL_SIZE];
	int		length;
}					t_fractional;

t_fractional		initialize_frac(t_fractional *snake);
int					set_len_frac(t_fractional *snake);
void				normalize_frac(t_fractional *snake);
t_fractional		addition_frac(t_fractional *one, t_fractional *two);

t_fractional		get_fractional(char *mantissa, int exp);


#endif
