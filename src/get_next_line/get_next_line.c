/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:06:53 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/02/03 16:00:31 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*gnl_strdup(const char *s1)
{
	char	*buffer;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	*ft_free(char **buffer, char **stash)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*temp;
	char	*read_buffer;
	ssize_t	bytes_read;

	if (!stash)
		stash = gnl_calloc(1, sizeof(char));
	read_buffer = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&read_buffer, &stash));
		read_buffer[bytes_read] = '\0';
		temp = gnl_strjoin(stash, read_buffer);
		ft_free(NULL, &stash);
		stash = temp;
	}
	ft_free(&read_buffer, NULL);
	if ((stash[0] == '\0' || !stash) && bytes_read == 0)
		ft_free(NULL, &stash);
	return (stash);
}

static char	*get_line(char **stash)
{
	char	*line;
	char	*new_buffer;
	size_t	len;

	if (gnl_strchr(*stash, '\n'))
	{
		len = gnl_strchr(*stash, '\n') - *stash + 1;
		line = gnl_substr(*stash, 0, len);
		new_buffer = gnl_strdup(*stash + len);
		ft_free(NULL, stash);
		*stash = new_buffer;
	}
	else
	{
		line = gnl_strdup(*stash);
		ft_free(NULL, stash);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(&stash);
	if (!line)
		return (ft_free(NULL, &stash));
	return (line);
}
