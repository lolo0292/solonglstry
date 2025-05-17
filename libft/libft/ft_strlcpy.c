/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:05:40 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/11 12:56:07 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// copy str from src to dest with size max
size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	g;

	g = 0;
	if (siz > 0)
	{
		while (src[g] && g < (siz - 1))
		{
			dst[g] = src[g];
			g++;
		}
		dst[g] = 0;
	}
	return (ft_strlen(src));
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int main(int argc, char **argv)
// {
// 	(void) argc;
// 	printf("%zu", ft_strlcpy(argv[1], NULL, 10));
// 	return (0);
// }