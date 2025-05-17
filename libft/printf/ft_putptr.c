/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:30:01 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/11 14:13:22 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

// Function to print a pointer in hexadecimal format
int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	tmp;

	len = 0;
	tmp = (unsigned long)ptr;
	if (tmp == 0)
		len += ft_putstr2("(nil)");
	else
	{
		len += ft_putstr2("0x");
		if (tmp >= 16)
			len += ft_puthex(tmp / 16, 'x');
		len += ft_putchar2("0123456789abcdef"[tmp % 16]);
	}
	return (len);
}
// int main(void)
// {
//     printf("Test 1 : ");
//     ft_putptr((void*)0); // Doit afficher : 0x0
//     printf("\n");

//     printf("Test 2 : ");
//     printf("%p %p %p", (void*)0, (void*)0, (void*)0); 
//     printf("\n");

//     printf("Test 3 : ");
//     ft_putptr((void *)0);
//     printf(" ");
//     ft_putptr((void *)0);
//     printf(" ");
//     ft_putptr((void *)0);
//     printf("\n");

//     return 0;
// }