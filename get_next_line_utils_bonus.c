/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:35:02 by jthor             #+#    #+#             */
/*   Updated: 2023/03/21 14:35:02 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char const *s, int c)
{
	if (c >= 256)
		c -= 256;
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retptr;
	char	*save;

	retptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!retptr)
		return (NULL);
	save = retptr;
	while (*s1)
		*save++ = *s1++;
	while (*s2)
		*save++ = *s2++;
	*save = '\0';
	return (retptr);
}

char	*ft_strldup(char const *s1, int len)
{
	char	*retptr;
	int		i;

	if (len <= 0)
		return (NULL);
	retptr = (char *)malloc((len + 1) * sizeof(char));
	if (!retptr)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		retptr[i] = s1[i];
		i++;
	}
	retptr[i] = '\0';
	return (retptr);
}

void	ft_handleptr(char **ptr, int mode)
{
	if (mode == 0)
	{
		*ptr = (char *)malloc(1 * sizeof(char));
		(*ptr)[0] = '\0';
	}
	else if (mode == 1)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
