/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:10:55 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/15 23:19:00 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_newline(int fd, char *my_backup)
{
	ssize_t	nb;
	char	*buff;
	char	*line;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);


	while(is_newline(my_backup) == 0)
	{

		nb = read(fd, buff, BUFFER_SIZE);


		if (nb == -1 || (nb == 0 && my_backup == NULL))
			return (free(buff), free(my_backup), NULL);

		buff[nb] = '\0';

		if (nb == 0)
			return (free(buff), my_backup);


		if (my_backup == NULL)
			my_backup = ft_strdup("");

		line = my_backup;
		my_backup = ft_strjoin(line, buff);
		free(line);
	}
	return (free(buff), my_backup);
}

char	*extract_newline(char **my_backup)
{
	char	*line;
	size_t	i;

	i = 0;
	if (is_newline(*my_backup) == 1)
		return *my_backup;
	// else
	// 	return *my_backup;


	while ((*my_backup)[i] != '\n' && (*my_backup)[i] )
		i++;

	line = (char *)malloc((i + 2) * sizeof(char)); // +1 f \0 w +2 f \n you have to write another condition

	i = 0;

	while ((*my_backup)[i] != '\n' && (*my_backup)[i] )
	{
		line[i] = (*my_backup)[i];
		i++;
	}
	if ((*my_backup)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';

	*my_backup = ft_strchr(*my_backup);
	// if ((*my_backup)[0] == '\0')
	// 	*my_backup = NULL;


	return (line);


}


char	*get_next_line(int fd)
{
	static char	*my_backup;
	char		*for_return;

	// protection Buffer size and fd
	if (fd < 0  || BUFFER_SIZE <=0)
		return (NULL);

	my_backup = read_newline(fd, my_backup);

	// if (my_backup[0]== '\0')
	// 	return (NULL);



	for_return = extract_newline(&my_backup);



	return (for_return);
}





#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{

		int fd;
	fd= open("a", O_RDONLY);
	char *s=get_next_line(fd);

		printf("%s",s);
		free(s);

		s=get_next_line(fd);
		printf("%s",s);
		free(s);

		s=get_next_line(fd);
		printf("%s",s);
		free(s);

				s=get_next_line(fd);
		printf("%s",s);
		free(s);
	// while (s)
	// {
	// 	printf("%s",s);
	// 	free(s);
	// 	s = get_next_line(fd);
	// }
	// 	printf("%s",s);

	//while (1);
	//system("leaks a.out");


}
