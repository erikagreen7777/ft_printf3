/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:17:26 by egreen            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/11/17 12:28:20 by egreen           ###   ########.fr       */
=======
/*   Updated: 2017/10/06 09:30:50 by egreen           ###   ########.fr       */
>>>>>>> 912280583a873f6858d24bb07e02d90a66fee452
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cs1;
	int		cs2;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	cs1 = ft_strlen(s1);
	cs2 = ft_strlen(s2);
	temp = (char *)malloc(sizeof(*temp) * (ft_strlen(s1) + (ft_strlen(s2))));
	if (!temp)
		return (NULL);
	ft_strcpy(temp, s1);
	ft_strcat(temp, s2);
	return (temp);
}
