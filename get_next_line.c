/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:10:55 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/13 05:46:35 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_newline(int fd, char **my_backup)
{
	char	*buff;
	int		nb;

	if (!*my_backup)
		*my_backup = ft_strdup("");
	nb = 0;
	while (is_newline(*my_backup) == 0)
	{
		buff = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (free(*my_backup), NULL);
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
			return (free(buff), free(*my_backup), NULL);
		buff[nb] = '\0';
		if (nb == 0 && *my_backup[0] == '\0')
			return(free(buff),free(*my_backup), NULL);
		if (nb == 0)
			return(free(buff),*my_backup);
		*my_backup = ft_strjoin(*my_backup,buff);
	}
	if (nb == 0)
		return (NULL);
	return (free(buff),*my_backup);
}

char	*extract_newline(char *for_return, char **my_backup)
{
	char	*line;

	if (is_newline(for_return))
	{
		char	*line;
		size_t	i;

		i = 0;
		while (for_return[i] != '\n')
			i++;
		line = (char *)malloc((++i) * sizeof(char));
		if (!line)
			return(free(*my_backup), NULL);

		*my_backup = ft_strchr(for_return);
		i = 0;
		while (for_return[i] != '\n')
		{
			line[i] = for_return[i];
			i++;
		}
		line[i] = '\0';
	}
	else
		return (free(*my_backup),free(line), NULL);

	//printf("|%s|",line);

	return (line);
}

char	*get_next_line(int fd)
{
	char		*for_return;
	static char	*my_backup;

	for_return = read_newline(fd, &my_backup);
	for_return = extract_newline(for_return, &my_backup);
	//printf("|%s|",my_backup);
	return (for_return);
}

#include <fcntl.h>
#include <stdio.h>


int main()
{
	int i = 0;
	int fd = open("a",O_RDONLY);

	char *s ;
	s = get_next_line(fd);
	printf("%s\n",s);
	//free(s);

	//while (1);

}
