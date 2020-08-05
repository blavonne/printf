#include "printf.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s && *s)
		write(fd, s, ft_strlen(s));
}
