#include "printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp_d;
	const char	*tmp_s;
	int			i;

	if (!dst && !src)
		return (0);
	tmp_d = dst;
	tmp_s = src;
	i = 0;
	while (i < (int)n)
	{
		tmp_d[i] = tmp_s[i];
		i++;
	}
	return (tmp_d);
}