/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:22 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/12 20:24:34 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_newline(int fd, char *my_backup, ssize_t *nb)
{
	//ssize_t	nb;
	char	*buff;

	while(is_newline(my_backup) == 0)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // malloc buff 42
		*nb = read(fd, buff, BUFFER_SIZE);
		if (*nb == -1 || (*nb == 0 && my_backup == NULL))
			return(free(buff),free(my_backup),NULL);
		buff[*nb] = '\0';
		if (*nb == 0)
			return(free(buff),my_backup);
		my_backup = ft_strjoin(my_backup,buff);
		free(buff);
		if (!my_backup)
			return(NULL);
	}
	return (my_backup);
}
char	*extract_newline(char *for_return, char **my_backup)
{
	char	*line;
	char	*bkup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (for_return[i] != '\n' && for_return[i])
		i++;
	// if (for_return[i] == '\0' || for_return[i+1] == '\0')
	// {
	// 	*my_backup = NULL;
	// 	return for_return;
	// }
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while(j <= i)  //1 - 0 // 2 - 1 //
	{
		line[j] = for_return[j];
		j++;
	}
	line[j] = '\0';
	bkup = malloc(ft_strlen(for_return) - i + 1);
	if(!bkup)
		return(free(for_return),NULL);
	j = 0;
	while (j <= ft_strlen(for_return) - i)
	{
		bkup[j] = for_return[i];
		j++;
		i++;
	}
	*my_backup = bkup;
	return(line);
}


// char	*get_next_line(int fd)
// {
// 	char		*for_return;
// 	static char	*my_backup;
// 	ssize_t			nb;

// 	nb = 1;

// 	for_return = read_newline(fd, my_backup, &nb);
// 	my_backup = for_return;
// 	if (is_newline(for_return) || nb == 0)
// 	{
// 		for_return = extract_newline(for_return, &my_backup);
// 		if (for_return != NULL && nb == 0)
// 		{
// 			if (for_return[0] =='\0')
// 				return (NULL);
// 		}
// 	}
// 	return (for_return);
// }


char	*get_next_line(int fd)
{
	char		*for_return;
	static char	*my_backup;
	ssize_t			nb;

	nb = 1;

	for_return = read_newline(fd, my_backup, &nb);
	// printf("|%s|",for_return);
	if (nb <= 0 && is_newline(for_return) == 0)
	{
		my_backup = 0;
		return for_return;
	}
	// printf("here");
	for_return = extract_newline(for_return, &my_backup);
	return (for_return);
}

// read 0
// return line





#include <fcntl.h>
#include <stdio.h>


int main()
{
	int i = 0;
	int fd = open("41_with_nl",O_RDONLY);

	char *s ;
	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);

	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);

	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);

	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);

	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);

	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);

	s = get_next_line(fd);
	printf("%s\n",s);
	free(s);

	//while (1);

}
