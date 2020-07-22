/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 18:00:09 by mel-kada          #+#    #+#             */
/*   Updated: 2020/04/04 18:00:24 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_params	params;
	int			ret;

	ret = 0;
	va_start(args, format);
	ft_bzero(&params, sizeof(t_params));
	ret += ft_parse((char *)format, &args, &params);
	va_end(args);
	return (ret);
}
