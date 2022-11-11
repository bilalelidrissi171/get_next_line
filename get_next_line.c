/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:22 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/11 23:04:45 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*read_newline(int fd, char *my_backup)
{
	ssize_t	nb;
	char	*buff;
	//char	*res;

	if (!my_backup)
	{
		my_backup = ft_strdup("");
		if (!my_backup)
			return (free(my_backup), NULL);
	}
	nb = 1;
	//res = ft_strdup("");
	while(is_newline(my_backup) == 0) // if nb == 0 return (null);
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1 || (nb == 0 && !my_backup))
			return(free(buff),free(my_backup),NULL); // wach darouri
		if (nb == 0)
			return(free(buff),my_backup); // fo9ach nkhadma
		buff[nb] = '\0';
		my_backup = ft_strjoin(my_backup,buff);
		if (!my_backup)
			return(free(buff),free(my_backup),NULL);
	}
	return (my_backup);
}

char	*extract_newline(char *for_return, char **my_backup)
{

}


char	*get_next_line(int fd)
{
	char		*for_return;
	static char	*my_backup;

	for_return = read_newline(fd, my_backup);
	my_backup = for_return;
	if (is_newline(for_return))
		for_return = extract_newline(for_return, &my_backup);
	return (for_return);
}








#include <fcntl.h>
#include <stdio.h>


int main()
{
	int fd = open("t",O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s\n",s);


}
