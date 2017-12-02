#include "../includes/libft.h"

void	ft_fputstr(char *str)
{
	int x;

	x = -1;
	while (str[++x] != '\0')
		;
	write(1, str, x);
}