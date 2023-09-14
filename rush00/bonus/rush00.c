/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:51:38 by afoth             #+#    #+#             */
/*   Updated: 2023/08/27 14:24:22 by lgalach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int	g_x;
int	g_y;

void	rush_top_bottom(void)
{
	int	i;

	ft_putchar('o');
	i = 0;
	while (i < g_x - 2) 
	{
		ft_putchar('-');
		i++;
	}
	if (g_x > 1) 
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	rush_middle(void)
{
	int	j;
	int	i;

	j = 0;
	while (j < g_y - 2) 
	{
		ft_putchar('|');
		i = 0;
		while (i < g_x - 2) 
		{
			ft_putchar(' ');
			i++;
		}
		if (g_x > 1) 
		{
			ft_putchar('|');
		}
		ft_putchar('\n');
		j++;
	}
}

void	rush_v(void)
{
	int	j;
	int	i;

	ft_putchar('o');
	ft_putchar('\n');
	j = 0;
	while (j < g_y - 2) 
	{
		ft_putchar('|');
		i = 0;
		while (i < g_x - 2) 
		{
			ft_putchar(' ');
			i++;
		}
		if (g_x > 1) 
		{
			ft_putchar('o');
		}
		ft_putchar('\n');
		j++;
	}
	ft_putchar('o');
	ft_putchar('\n');
}

void	rush(int xx, int yy)
{
	if (xx > 0 && yy > 0)
	{
		g_x = xx;
		g_y = yy;
		if (g_y == 1)
		{
			rush_top_bottom();
		}
		else if (g_x == 1)
		{
			rush_v();
		}
		else
		{
			rush_top_bottom();
			rush_middle();
			rush_top_bottom();
		}
	}
	else 
	{
		write(1, "Please enter a natural number", 29);
		ft_putchar('\n');
	}
}
