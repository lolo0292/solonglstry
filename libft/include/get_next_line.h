/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:52:40 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/14 12:28:58 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen3(const char *s);
char	*ft_strjoin3(char *s1, char *s2);
void	*ft_calloc3(size_t count, size_t size);
char	*ft_substr3(char const *s, unsigned int start, size_t len);
char	*ft_strchr3(const char *s, int c);
char	*getline1(char **stash);
char	*store(int fd, char *stash);
char	*free2(char **ptr1, char **ptr2);
void	free_all_gnl_stashes(void);

#endif
