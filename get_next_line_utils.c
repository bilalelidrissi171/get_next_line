/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:23:00 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/10 17:46:39 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

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

	str = (char *)malloc(100 * sizeof(char));
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

int	is_newlin_end(char *buff,size_t nb)
{
	size_t	i;

	i = 0;
	if (nb != BUFFER_SIZE)
		return (1);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (2);
	}
	return (0);
}

char	*join_it(char *for_return, char *buff)
{

	for_return = ft_strjoin(for_return, buff);

	return(for_return);

}
