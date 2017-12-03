/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:12:46 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:16:17 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_verif_utf(wchar_t wc)
{
	if (MB_CUR_MAX < 2)
	{
		ft_putchar(wc);
		return (1);
	}
	return (0);
}

static int		ft_wputchar_nnext(wchar_t wc)
{
	if (wc <= 0x03FFFFFF)
	{
		ft_putchar(0xF8 | (wc >> 24));
		ft_putchar(0x80 | (wc >> 18 & 0x3F));
		ft_putchar(0x80 | (wc >> 12 & 0x3F));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		return (5);
	}
	else if (wc <= 0x7FFFFFFF)
	{
		ft_putchar(0xFC | (wc >> 30));
		ft_putchar(0x80 | (wc >> 24 & 0x3F));
		ft_putchar(0x80 | (wc >> 18 & 0x3F));
		ft_putchar(0x80 | (wc >> 12 & 0x3F));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		return (6);
	}
	return (0);
}

static int		ft_wputchar_next(wchar_t wc)
{
	int ret;

	ret = 0;
	if (wc <= 0x0000FFFF)
	{
		ft_putchar(0xE0 | (wc >> 12));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		ret = 3;
	}
	else if (wc <= 0x001FFFFF)
	{
		ft_putchar(0xF0 | (wc >> 18));
		ft_putchar(0x80 | (wc >> 12 & 0x3F));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		ret = 4;
	}
	else
		ret = ft_wputchar_nnext(wc);
	return (ret);
}

int				ft_wputchar(wchar_t wc)
{
	int ret;

	ret = 0;
	if (ft_verif_utf(wc))
		return (1);
	if (wc <= 0x0000007F)
	{
		ft_putchar(wc);
		ret = 1;
	}
	else if (wc <= 0x000007FF)
	{
		ft_putchar(0xC0 | (wc >> 6));
		ft_putchar(0x80 | (wc & 0x3F));
		ret = 2;
	}
	else
		ret = ft_wputchar_next(wc);
	return (ret);
}

void		format_wstring(t_print *ptr, t_spec *ts)
{
	size_t	i;

	i = 0;
	ts->data.bigs = va_arg(ptr->arg, wchar_t *);
	if (ts->data.bigs == NULL)
		ts->len = 0;
	else
	{
		while (ts->data.bigs[i])
			i++;
		ts->len = i;
		i = 0;
	}
	while (ts->data.bigs[i])
	{
		ft_wputchar(ts->data.bigs[i]);
		i++;
	}
}
