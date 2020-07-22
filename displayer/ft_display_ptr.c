/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:37:12 by mel-kada          #+#    #+#             */
/*   Updated: 2020/04/04 17:40:20 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_0x(int *state)
{
	if (!*state)
	{
		write(1, "0x", 2);
		*state = 1;
		return (2);
	}
	return (0);
}

static int	ft_write
	(t_params *params, unsigned long value, int preci, int digits)
{
	int ret;
	int state;

	ret = 0;
	state = 0;
	if (params->zero)
	{
		ret += ft_print_0x(&state);
		while (params->width-- > 0)
			ret += write(1, "0", 1);
	}
	if (!params->left)
		while (params->width-- > 0)
			ret += write(1, (params->zero ? "0" : " "), 1);
	ret += ft_print_0x(&state);
	while (digits < params->precision_val--)
		ret += write(1, "0", 1);
	if (ft_allowed_to_print(value, params->precision, preci))
	{
		ft_putnbr_base(value, BASE_16_LO);
		ret += digits;
	}
	while (params->width-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}

int			ft_display_ptr(va_list *args, t_params *params)
{
	void	*value;
	int		digits;
	int		preci;

	if (params->precision && params->zero)
		params->zero = 0;
	preci = params->precision_val;
	value = va_arg(*args, void *);
	digits = ft_get_base_size((unsigned long)value, 16);
	if (digits > params->precision_val &&
		ft_allowed_to_print((unsigned long)value, params->precision, preci))
		params->precision_val = digits;
	params->width -= (params->precision_val + 2);
	return (ft_write(params, (unsigned long)value, preci, digits));
}
