/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:22 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/12 04:30:36 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_newline(int fd, char *my_backup, ssize_t *nb)
{
	//ssize_t	nb;
	char	*buff;

	if (!my_backup)
	{
		return (free(my_backup), NULL);
	}
	while(is_newline(my_backup) == 0)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		*nb = read(fd, buff, BUFFER_SIZE);

		if (*nb == -1)
			return(free(buff),NULL);

		if (*nb == 0 && my_backup != NULL)
			return(free(buff),my_backup);



		buff[*nb] = '\0';

		my_backup = ft_strjoin(my_backup,buff);
		if (!my_backup)
			return(free(buff),free(my_backup),NULL);
	}
	return (my_backup);
}

char	*extract_newline(char *for_return, char **my_backup)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (for_return[i] != '\n' && for_return[i])
		i++;
	if (for_return[i] == '\0')
	{
		*my_backup = NULL;
		return for_return;
	}
	line = (char *)malloc((i) * sizeof(char));
	if (!line)
		return (free(line), NULL);
	while(j < i)
	{
		line[j] = for_return[j];
		j++;
	}
	line[j] = '\0';
	*my_backup = ft_strchr(*my_backup);
	return(line);
}


char	*get_next_line(int fd)
{
	char		*for_return;
	static char	*my_backup = "";
	ssize_t			nb;

	nb = 1;

	for_return = read_newline(fd, my_backup, &nb);
	my_backup = for_return;
	if (is_newline(for_return) || nb == 0)
		for_return = extract_newline(for_return, &my_backup);
	return (for_return);
}








// #include <fcntl.h>
// #include <stdio.h>


// int main()
// {
// 	int i = 0;
// 	int fd = open("t",O_RDONLY);
// 	while (i < 15)
// 	{
// 		char *s = get_next_line(fd);
// 		printf("%s\n",s);
// 		i++;
// 	}
// }
