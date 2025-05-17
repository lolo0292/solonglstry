/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:11:54 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/11 12:56:07 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
// size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
// {
// 	size_t	g;

// 	g = 0;
// 	if (!dst || !src)
// 		return (0);
// 	if (siz > 0)
// 	{
// 		while (src[g] && g < (siz - 1))
// 		{
// 			dst[g] = src[g];
// 			g++;
// 		}
// 		dst[g] = 0;
// 	}
// 	return (ft_strlen(src));
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)(s + i));
// 	else
// 		return (NULL);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t x;

// 	x = 0;
// 	while (s[x])
// 		x++;
// 	return (x);
// }

// delete car define by set before and after string
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	z;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	z = ft_strlen(s1);
	while (z > i && ft_strchr(set, s1[z - 1]))
		z--;
	trim = malloc(sizeof(char) * (z - i + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[i], z - i + 1);
	return (trim);
}

// int main(int argc, char **argv)
// {
// 	char *tmp;
// 	(void) argc;
// 	tmp = ft_strtrim(argv[1], argv[2]);
// 	printf("%s", tmp);
// 	free (tmp);
// 	return (0);
// }