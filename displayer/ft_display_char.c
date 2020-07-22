/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <mel-kada@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:27:27 by mel-kada          #+#    #+#             */
/*   Updated: 2020/04/04 17:27:46 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_display_char(va_list *args, t_params *params)
{
	unsigned int	value;
	int				ret;

	ret = 0;
	value = (unsigned int)va_arg(*args, int);
	params->width -= 1;
	if (!params->left)
		while (params->width-- > 0)
			ret += write(1, " ", 1);
	ret += write(1, &value, 1);
	while (params->width-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}
