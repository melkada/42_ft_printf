/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:56:02 by mel-kada          #+#    #+#             */
/*   Updated: 2020/04/04 18:36:28 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_display_percent(t_params *params)
{
	int	ret;

	ret = 0;
	params->width -= 1;
	if (!params->left)
		while (params->width-- > 0)
			ret += write(1, (params->zero ? "0" : " "), 1);
	ret += write(1, "%", 1);
	while (params->width-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}
