#include "printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*cat;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (size < ft_strlen(s1) || size < ft_strlen(s2))
		return (NULL);
	if (!(cat = ft_strnew(size)))
		return (NULL);
	cat = ft_strcat(cat, s1);
	cat = ft_strcat(cat, s2);
	return (cat);
}
