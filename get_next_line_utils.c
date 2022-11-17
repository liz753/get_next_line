/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:45:51 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/17 17:16:05 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	// if (s == NULL)
	// 	return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlen_n(char *s)
{
	size_t	len;

	len = 0;
	// if (s == NULL)
	// 	return (0);
	while (s[len] != '\n' || s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, (char *)s1);
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	x;

	if (dst == NULL || src == NULL)
		return (0);
	x = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (x);
}

/* condition if len is equal to 0,
	it returns the string from start until the end */

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	if (start + len > ft_strlen(s) || len == 0)
		len = ft_strlen(s) - start;
	if (len > ft_strlen(s))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}
