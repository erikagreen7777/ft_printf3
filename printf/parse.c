/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:56:56 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 15:22:01 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	constructor(t_print *ptr, t_spec *this)
{
	this->left_align = false;
	this->show_sign = false;
	this->prepend_space = false;
	this->prepend_zero = false;
	this->aform = false;
	this->width = 0;
	this->prec = -1;
	this->lgth[0] = '\0';
	this->lgth[1] = '\0';
	this->lgth[2] = '\0';
	this->type = 0;
	this->len = 0;
	this->arg = &ptr->arg;
	this->fd = &ptr->fd;
	this->ret = &ptr->ret;
}

static void	type_finder(t_print *ptr, int *xptr)
{
	t_spec	this;

	constructor(ptr, &this);
	find_flags(&this, ptr->format, xptr);
	if (this.type == 's')
		format_string(ptr, &this);
	else if (this.type == 'S' || (this.type == 'l'\
				&& ptr->format[++*xptr] == 's'))
		format_wstring(ptr, &this);
	else if (this.type == 'd' || this.type == 'U' ||\
			this.type == 'i' || this.type == 'D')
		format_decimal(ptr, &this);
	else if (this.type == 'c' || this.type == 'C')
		format_char(ptr, &this);
	else if (this.type == '%')
		format_percent(&this);
	else if (this.type == 'p')
		format_pointer(ptr, &this);
	else if (this.type == 'o')
		format_octal(ptr, &this);
	else if (this.type == 'x' || this.type == 'X')
		format_hex(ptr, &this);
	else if (this.type == 'u')
		format_udecimal(ptr, &this);
}

static void	print_buffer(t_print *ptr, int start, int x)
{
	write(ptr->fd, ptr->format + start, x - start);
	ptr->ret += x - start;
}

void		parse(t_print *ptr)
{
	int		x;
	int		start;

	x = 0;
	start = 0;
	while (ptr->format[x] != '\0')
	{
		if (ptr->format[x] == '%')
		{
			print_buffer(ptr, start, x);
			type_finder(ptr, &x);
			start = x + 1;
		}
		x++;
	}
	print_buffer(ptr, start, x);
}
