/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:10:55 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/13 04:47:50 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_newline(int fd, char **my_backup)
{
	char	*buff;
	int		nb;
	char	*temp;
	char	*line;

	if (!*my_backup)
		*my_backup = ft_strdup("");

	while (is_newline(*my_backup) == 0)
	{
		buff = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (free(*my_backup), NULL);
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
			return (free(buff), free(*my_backup), NULL);
		buff[nb] = '\0';
		if (nb == 0)
			return(free(buff),*my_backup);
		*my_backup = ft_strjoin(*my_backup,buff);
		printf("|%s|",*my_backup);
		if (**my_backup == '\0')
			return (NULL);
	}
	return (*my_backup);
}

char	*get_next_line(int fd)
{
	char		*for_return;
	static char	*my_backup = 0;

	for_return = read_newline(fd, &my_backup);
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

	s = get_next_line(fd);
	printf("%s\n",s);

	s = get_next_line(fd);
	printf("%s\n",s);

	s = get_next_line(fd);
	printf("%s\n",s);

	s = get_next_line(fd);
	printf("%s\n",s);

	s = get_next_line(fd);
	printf("%s\n",s);

	s = get_next_line(fd);
	printf("%s\n",s);

	//while (1);

}
