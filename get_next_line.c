/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:40:28 by iidkhebb          #+#    #+#             */
/*   Updated: 2021/11/13 23:40:29 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			reading_return[1];
	static char		*str_static;
	int				reading_status;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (0);
	str_static = (char *)malloc(2 * sizeof(char));
	reading_status = read(fd, reading_return, 1);
	if (!str_static || reading_status < 0)
		return (free(str_static), NULL);
	str_static[0] = *reading_return;
	str_static[1] = '\0';
	while (reading_status && str_static)
	{
		if (*reading_return == '\n')
			return (str_static);
		reading_status = read(fd, reading_return, 1);
		if (reading_status == 0)
			return (str_static);
		str_static = ft_add_char(str_static, reading_return);
	}
	return (free(str_static), NULL);
}
/*
int main()
{
    int fd;
    char *line;
    int i;
    i =0;
    fd = open("test.txt", O_RDWR | O_CREAT);
    //printf("the FD is : %d\n",fd);
    while(line)
    {
        line = get_next_line(fd);
        printf("%s",line);
    }
    return (0);
}*/
