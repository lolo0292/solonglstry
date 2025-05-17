/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:08:04 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/13 16:18:09 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

// split the s
char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

// int main(int argc, char **argv)
// {
//     char **tmp; 
//     int i;

//     if (argc != 3) 
//     {
//         printf("Usage: %s <string_to_split> <delimiter>\n", argv[0]);
//         return (1);
//     }

//     tmp = ft_split(argv[1], argv[2][0]);
//     if (!tmp)
//     {
//         printf("Error: Memory allocation failed.\n");
//         return (1);
//     }

//     i = 0;
//     while (tmp[i])
//     {
//         printf("tmp[%d] = '%s'\n", i, tmp[i]);
//         free(tmp[i]); 
//         i++;
//     }
//     free(tmp); 

//     return (0);
// }