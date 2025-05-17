/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:39:12 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/11 12:56:07 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// compare first n bytes of MZ s1 and s2 --> give diff
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

// int main(int argc, char **argv)
// {
//     (void) argc;
//     int	ptr1;
//     int	ptr2;

//     ptr1 = ft_memcmp(argv[1], argv[2], atoi(argv[3]));
//     ptr2 = memcmp(argv[1], argv[2], atoi(argv[3]));
//     printf("your %d \n", ptr1);
//     printf("normal %d", ptr2);
//     return (0);
// }