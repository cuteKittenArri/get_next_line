/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 02:16:55 by stmuller          #+#    #+#             */
/*   Updated: 2025/11/05 01:34:09 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	while (1 == 1)
	{
		printf("%s", get_next_line(fd));
		usleep(8000);
	}
	return (0);
}