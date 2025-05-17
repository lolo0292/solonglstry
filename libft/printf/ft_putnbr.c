/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:25:12 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/11 12:57:55 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

// Function to print a signed integer
int	ft_putnbr2(int n)
{
	int		len;
	char	buffer[12];
	int		i;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	i = 0;
	while (n >= 10)
	{
		buffer[i++] = (n % 10) + '0';
		n = n / 10;
	}
	buffer[i++] = n + '0';
	while (--i >= 0)
		len += ft_putchar(buffer[i]);
	return (len);
}
