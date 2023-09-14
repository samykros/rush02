/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programm_arguments_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:49:27 by afoth             #+#    #+#             */
/*   Updated: 2023/08/27 16:35:05 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rush(int xx, int yy);

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*pos1;
	int	*pos2;

	pos1 = &*argv[1];
	pos2 = &*argv[2];
	i = atoi(pos1);
	j = atoi(pos2);
	rush(i, j);
	return (0);
}
