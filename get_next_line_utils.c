/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:11:12 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/16 02:52:36 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
		x++;
	return (x);
}

char	*ft_strchr(char *s)
{
	size_t	i;
		size_t	j;

	char *str;

	i = 0;
	j = 0;

	while (s[i])
	{
		if (s[i] == '\n')
		{
			str = (char *)malloc((ft_strlen(s) - i) * sizeof(char)); //bilal\nhjkka\0
			i++;
			while (s[i])
			{
				str[j] = s[i];
				j++;
				i++;
			}
			str[j] = '\0';
			return (str);
		}
		i++;
	}
	return (s);
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
	size_t	i;
	size_t	j;
	size_t	ls1;
	size_t	ls2;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);


	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc((ls1 + ls2 + 1) * sizeof(char)); // change ft_strlen b ls1 and ls2
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < ls1)
		str[i] = s1[i];
	while (++j < ls2)
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
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

