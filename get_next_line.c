/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:10:55 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/16 03:21:47 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_newline(int fd, char *my_backup)
{
	int		nb;
	char	*buff;

	nb = -1;
	while (!is_newline(my_backup) && nb)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
			return (free(buff), NULL);
		if (nb == 0)
			return (free(buff), my_backup);
		buff[nb] = '\0';
		// res = ft_strjoin(my_backup, buff);
		// free(my_backup);
		// my_backup = ft_strdup(res);
		my_backup = ft_strjoin(my_backup, buff);
		free(buff);
	}
	return (my_backup);
}

char	*extract_newline(char *my_backup)
{
	char	*len;
	size_t	i;

	i = 0;

	if (!is_newline(my_backup))
		return (ft_strdup(my_backup));

	while (my_backup[i++] != '\n');

	len = (char *)malloc((i + 2) * sizeof(char));
	if (!len)
		return (NULL);

	i = -1;

	while(my_backup[++i] != '\n')
		len[i] = my_backup[i];

	len[i++] = '\n';
	len[i] = '\0';

	return (len);
}

char	*extract_after_newline(char *my_backup)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;

	while (my_backup[i] != '\n' && my_backup[i])
		i++;
	if (my_backup[i] == '\0')
		return (free(my_backup),NULL);
	res = (char *)malloc((ft_strlen(my_backup) - i) * sizeof(char)); // AB\nABD\0
	if (!res)
		return (NULL);
	i++;
	while(my_backup[i])
	{
		res[j] = my_backup[i];
		i++;
		j++;
	}
	res[j] = '\0';

	free(my_backup);
	return (res);
}


char	*get_next_line(int fd)
{
	static char	*my_backup;
	char		*for_return;

	my_backup = read_newline(fd, my_backup);
	if (!my_backup)
		return (NULL);
	for_return = extract_newline(my_backup);
	my_backup = extract_after_newline(my_backup);
	return(for_return);
}





#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{

	int fd;
	fd= open("a", O_RDONLY);
	char *s;
	s=get_next_line(fd);
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

	// s=get_next_line(fd);
	// printf("%s",s);
	// free(s);

	// s=get_next_line(fd);
	// printf("%s",s);
	// free(s);
	//system("leaks a.out");
}
