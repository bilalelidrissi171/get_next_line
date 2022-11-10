/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:22 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/10 17:46:18 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*buff;
	static char	*for_return;
	ssize_t		nb;

	for_return = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));

	nb = 0;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nb = read(fd, buff, BUFFER_SIZE); // '\0' is add auto or need to adding it
	buff[BUFFER_SIZE] = '\0';
	if (nb == -1)
		return (free(buff), NULL);

	for_return = join_it(for_return, buff);

	return (for_return);
}







#include <fcntl.h>

int main()
{
	int fd = open("t",O_RDONLY);
	int i = 0;
	while (i < 2)
	{
		char *s = get_next_line(fd);
		printf("%s\n",s);
		i++;
	}
}


