/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:06:56 by nbuchhol          #+#    #+#             */
/*   Updated: 2025/01/03 13:50:23 by nbuchhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s1, int c)
{
	if (!s1)
		return (NULL);
	while (*s1)
	{
		if (*s1 == (char)c)
			return ((char *)s1);
		s1++;
	}
	if (*s1 == (char)c)
		return ((char *)s1);
	return (NULL);
}

char	*ft_strjoin(const char *prefix, const char *suffix)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!prefix && !suffix)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(prefix) + ft_strlen(suffix) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*prefix)
		str[i++] = *prefix++;
	j = 0;
	while (suffix[j])
		str[i++] = suffix[j++];
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			length;
	void			*buffer;
	unsigned char	*ptr;
	size_t			i;

	if ((nmemb != 0 && size) > ((size_t)-1) / nmemb)
		return (NULL);
	length = size * nmemb;
	buffer = malloc(length);
	if (!buffer)
		return (NULL);
	ptr = (unsigned char *)buffer;
	i = 0;
	while (i < length)
		ptr[i++] = 0;
	return (buffer);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*buffer;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > size)
		len = size - start;
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len)
		buffer[i++] = s[start++];
	buffer[i] = '\0';
	return (buffer);
}
