/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-idri <bel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:22 by bel-idri          #+#    #+#             */
/*   Updated: 2022/11/10 22:13:10 by bel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*buff;
	char		*for_return;
	static char	*temp;
	ssize_t		nb;

	for_return = 0;
	temp = 0;

	nb = 1;

	while (is_newline(for_return) != 1 || nb != 0)
	{

		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		nb = read(fd, buff, BUFFER_SIZE);

		if (nb == -1)
			return (free(buff), NULL);

		buff[nb] = '\0';


		for_return = temp;
		temp = join_it(for_return, buff);
		for_return = temp;
		if (is_newline(for_return) == 1)
		{
			temp = found_newline(for_return);
			return (for_return); //substr
		}
	}
	if (is_newline(for_return) == 1)
		{
			temp = found_newline(for_return);
			return (for_return); // substr
		}

	return (for_return);
}








#include <fcntl.h>
#include <stdio.h>


int main()
{
	int fd = open("t",O_RDONLY);
	int i = 0;
	while (i < 10)
	{
		char *s = get_next_line(fd);
		printf("%s\n",s);
		i++;
	}
}
