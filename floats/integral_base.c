#include "integral.h"

t_integral			initialize_integral(t_integral *elephant)
{
	int		i;

	i = 0;
	while (i < SIZE)
	{
		elephant->bigint[i] = 0;
		i++;
	}
	return (*elephant);
}

void				normalize_integral(t_integral *elephant)
{
	int			i;
	int			corrector;
	int			j;

	i = 0;
	elephant->length = set_len_integral(elephant);
	while (i < elephant->length)
	{
		if (elephant->bigint[i] >= BASE && i < SIZE)
		{
			corrector = (int)(elephant->bigint[i] / BASE);
			elephant->bigint[i] = elephant->bigint[i] % BASE;
			j = i + 1;
			while (corrector && j < SIZE)
			{
				elephant->bigint[j++] += corrector % BASE;
				corrector /= BASE;
			}
		}
		i++;
		elephant->length = set_len_integral(elephant);
	}
}

int					set_len_integral(t_integral *elephant)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < SIZE)
	{
		if (elephant->bigint[i])
			len = i + 1;
		i++;
	}
	return (len);
}
