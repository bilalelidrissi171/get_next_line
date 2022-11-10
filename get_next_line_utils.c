/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:23:00 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/10 20:45:53 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	if(!s)
		return (1);
	x = 0;
	while (s[x])
		x++;
	return (x);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	if(!s1)
		return (s2);

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) +1 ) * sizeof(char));
	if (!str)
		return (free(str), NULL);
	i = -1;
	j = -1;
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while (++j < ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*found_newline(char *s)
{
	while (*s)
	{
		if ((char)*s == '\n')
			return ((char *)s + 1);
		s++;
	}
	return (s);
}

int	is_newline(char *s)
{
	if(!s)
		return (1);
	while (*s)
	{
		if ((char)*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_substr(char *s)
{
	char	*str;
	size_t	i;
	size_t end;

	end = 0;

	while(s[end] != '\n' && s[end])
		end++;

	i = 0;
	str = (char *)malloc((end) * sizeof(char));
	if (!str)
		return (free(str),NULL);
	while (i < end)
		str[i++] = s[i++];
	str[i] = '\0';
	return (str);
}

char	*join_it(char *for_return, char *buff)
{
	for_return = ft_strjoin(for_return, buff);
	return(for_return);
}
