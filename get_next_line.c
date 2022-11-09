/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:22 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/09 18:59:15 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>

char *get_next_line(int fd)
{
	char	*buff;
	ssize_t	nb;
	nb = 0;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	nb = read(fd, buff, BUFFER_SIZE);

	printf ("%zd\n",nb);

	if (nb == -1)
		return (NULL);

	return (buff);
}

int main()
{
	int fd = open("t",O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s",s);
}


