/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:33:12 by aezzahir          #+#    #+#             */
/*   Updated: 2023/11/28 08:33:13 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
    int fd = open(av[1], O_RDONLY);
    char *line;
	int i = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%d - %s", i, line);
		i++;
        free(line);
    }
    free(line);
    close(fd);
    }
	return 0;
}
