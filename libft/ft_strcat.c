#include "../includes/printf.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1[i])
		i = ft_strlen(s1);
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
