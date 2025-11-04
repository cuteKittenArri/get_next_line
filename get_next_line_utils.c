/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:25:06 by stmuller          #+#    #+#             */
/*   Updated: 2025/11/04 00:57:32 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if(!s1 || !s2)
		return(0);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if(!str)
		return(0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*r;

	r = s;
	i = 0;
	while (i < n)
	{
		*r = 0;
		r++;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
	{
		array = (malloc(1));
		ft_bzero(array, 1);
		return (array);
	}
	if (size >= SIZE_MAX / nmemb)
		return (0);
	array = malloc(size * nmemb);
	if (!array)
		return (0);
	ft_bzero(array, nmemb * size);
	return (array);
}

char	*ft_strchr(const char *string, int tosearch)
{
	char			*str;
	unsigned char	c;

	if(!string)
		return(0);
	c = tosearch;
	str = (char *)string;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}
