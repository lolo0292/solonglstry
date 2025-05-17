/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:51:51 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/15 16:52:06 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_strchr3(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*free2(char **ptr1, char **ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}

char	*store(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = ft_calloc3(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr3(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free2(&buffer, NULL));
		buffer[bytes_read] = '\0';
		stash = ft_strjoin3(stash, buffer);
		if (!stash)
			return (free2(&buffer, NULL));
	}
	free(buffer);
	return (stash);
}

char	*getline1(char **stash)
{
	char	*line;
	char	*temp;
	size_t	len;

	if (*stash == NULL || **stash == '\0')
		return (NULL);
	if (ft_strchr3(*stash, '\n'))
		len = ft_strchr3(*stash, '\n') - *stash + 1;
	else
		len = ft_strlen3(*stash);
	line = ft_substr3(*stash, 0, len);
	if (!line)
		return (NULL);
	temp = ft_substr3(*stash, len, ft_strlen3(*stash) - len);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(*stash);
	*stash = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd == -1)
		return (free2(&stash, NULL));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = store(fd, stash);
	if (!stash)
		return (NULL);
	line = getline1(&stash);
	if (!line)
		free2(&stash, NULL);
	return (line);
}
