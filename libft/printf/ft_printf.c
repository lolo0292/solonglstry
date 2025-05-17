/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:47:15 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/11 14:12:58 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_putchar2(va_arg(args, int));
	else if (format == 's')
		print_length += ft_putstr2(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_length += ft_putnbr2(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_putchar2('%');
	return (print_length);
}

// mimic printf behavior
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar2(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
// int main(void)
// {
//     // Test character
//     ft_printf("Character test: %c\n", '\0');
//     printf("Character test: %c\n", '\0');

//     // Test string
//     ft_printf("String test: %s\n", "");
// 	printf("String test: %s\n", "");

// 	// Test pointer2.0
// 	printf( "test: %i\n", ft_printf("Pointer test: %p\n", NULL));
// 	printf( "test: %i\n", printf("Pointer test: %p\n", NULL));

//     // Test pointer
//     int x = 42;
//     ft_printf("Pointer test: %p\n", &x);
// 	printf("Pointer test: %p\n", &x);

//     // Test integer (decimal)
//     ft_printf("Integer test: %d\n", 12345);
//     printf("Integer test: %d\n", 12345);

//     // Test integer (signed)
//     ft_printf("Signed integer test: %i\n", -6789);
//     printf("Signed integer test: %i\n", -6789);

//     // Test unsigned integer
//     ft_printf("Unsigned integer test: %u\n", 3000000000u);
//     printf("Unsigned integer test: %u\n", 3000000000u);

//     // Test hexadecimal (lowercase)
//     ft_printf("Hexadecimal test (lowercase): %x\n", 255);
//     printf("Hexadecimal test (lowercase): %x\n", 255);

//     // Test hexadecimal (uppercase)
//     ft_printf("Hexadecimal test (uppercase): %X\n", 255);
//     printf("Hexadecimal test (uppercase): %X\n", 255);

//     // Test mixing all formats
//     ft_printf("Mix test: %c, %s, %p, %d, %i, %u, %x, %X\n",
//               'Z', "42", &x, 42, -42, 42u, 42, 42);
//     printf("Mix test: %c, %s, %p, %d, %i, %u, %x, %X\n",
//               'Z', "42", &x, 42, -42, 42u, 42, 42);
//     return 0;
// }
// int main(void)
// {
// 	printf("Mix test: %c, %s, %p, %d, %i, %u, %x, %X\n",
//               'Z', "42", &x, 42, -42, 42u, 42, 42);
// 	return 0;
// }