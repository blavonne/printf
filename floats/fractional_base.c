#include "fractional.h"
#include "printf.h"

t_fractional		initialize_frac(t_fractional *snake)
{
	int		i;

	i = 0;
	while (i < TAIL_SIZE)
	{
		snake->bigint[i] = 0;
		i++;
	}
	return (*snake);
}

int					set_len_frac(t_fractional *snake)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < TAIL_SIZE)
	{
		if (snake->bigint[i])
			len = i + 1;
		i++;
	}
	return (len);
}

void				normalize_frac(t_fractional *snake)
{
	int			len;

	len = snake->length - 1;
	snake->length = set_len_frac(snake);
	while (len >= 0)
	{
		if (snake->bigint[len] >= 10 && len - 1 >= 0)
		{
			snake->bigint[len] -= 10;
			snake->bigint[len - 1]++;
		}
		len--;
	}
}

t_fractional		get_fractional(char *mantissa, int exp)
{
	t_fractional	snake;
	t_fractional	tmp;
	int				len;
	int				i;

	i = (exp < 0) ? ft_abs(exp) : 1;
	snake = initialize_frac(&snake);
	if (!get_length(mantissa))
		return (snake);
	mantissa = (exp < 0) ? &mantissa[0] : &mantissa[exp + 1];
	len = (exp < 0) ? ft_abs(exp) + get_length(mantissa) : get_length(mantissa);
	while (len)
	{
		if (*mantissa++ == '1')
		{
			tmp = initialize_frac(&tmp);
			tmp = frac_five_power(&tmp, i);
			snake = addition_frac(&snake, &tmp);
		}
		i++;
		len--;
	}
	snake.length = set_len_frac(&snake);
	return (snake);
}
