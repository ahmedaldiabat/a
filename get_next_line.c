/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-taha <hal-taha@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:34:00 by hal-taha          #+#    #+#             */
/*   Updated: 2026/01/08 19:21:47 by hal-taha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_loop(int fd, char *stash, char *buffer)
{
	ssize_t	bytes;

	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stash), NULL);
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_loop(fd, stash, buffer);
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

static char	*clean_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_substr(stash, i + 1,
			ft_strlen(stash) - i - 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash || !stash[0])
		return (free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
