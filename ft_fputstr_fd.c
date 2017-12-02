#include "../includes/libft.h"

void	ft_fputstr_fd(char *str, int fd)
{
	int x;

	x = -1;
	while (str[++x] != '\0')
		;
	write(fd, str, x);
}