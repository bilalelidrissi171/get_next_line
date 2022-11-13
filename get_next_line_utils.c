/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:11:12 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/13 05:34:10 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

char	*ft_strchr(char *s)
{
	size_t	i;

	i = 0;
	//
	while (s[i])
	{
		if (s[i] == '\n')
		{
			char *str = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char));
			str = &s[i + 1];
			return (free(s), str);
		}
		i++;
	}
	return (free(s) ,NULL);
}

int	is_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;
	size_t	i;
	size_t	j;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);

	if (!s1)
		return (s2);
	str = (char *)malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ls1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ls2)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (free(s1), str);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

