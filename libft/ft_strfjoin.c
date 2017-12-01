/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:17:58 by egreen            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/11/17 12:34:41 by egreen           ###   ########.fr       */
=======
/*   Updated: 2017/11/13 15:18:29 by egreen           ###   ########.fr       */
>>>>>>> 912280583a873f6858d24bb07e02d90a66fee452
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char			*ft_strfjoin(char *s1, char *s2)
{
	size_t		lens;
	char		*str;
	size_t		len1;
	size_t		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	lens = (len1 + len2);
	str = (char *)malloc(sizeof(str) * (lens + 1));
	if (str == 0)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	str[lens + 1] = '\0';
	ft_strdel(&s1);
=======
char	*ft_strfjoin(char *s1, char *s2)
{
	char			*str;
	size_t			i;
	size_t			j;
	size_t			len1;
	size_t			len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_strnew(len1 + len2);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
		str[j++] = s1[i++];
	i = 0;
	while (i < len2)
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	s1 = NULL;
>>>>>>> 912280583a873f6858d24bb07e02d90a66fee452
	return (str);
}
