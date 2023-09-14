/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:51:38 by afoth             #+#    #+#             */
/*   Updated: 2023/08/26 19:04:18 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c); // function declaration
int	g_x;
int	g_y;

void	rush_top_bottom(void) // prints top and bottom line
{
	int	i;

	ft_putchar('A'); // prints left A
	i = 0;
	while (i < g_x - 2) // prints g_x -2 times B, horizontal B following left A (-2 because of the A and C, borders)
	{
		ft_putchar('B');
		i++;
	}
	if (g_x > 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n'); // line break, to build the second block below the first
}

void	rush_middle(void) // prints the vertical B by printing them horizontally
{
	int	j;
	int	i;

	j = 0;
	while (j < g_y - 2) // prints g_y - 2 times B, this is the left B
	{
		ft_putchar('B');
		i = 0;
		while (i < g_x - 2) // prints ' ' to creat the void ilusion while printing horizontally
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('B'); // prints B if g_x is greater than 1
		ft_putchar('\n');  // line break, to build the last block below this
		j++;
	}
}

void	rush_v(void) // in case x == 1 (we want a column) print vertical only
{
	int	j;

	ft_putchar('A'); // print the first A
	ft_putchar('\n');  // line break, to build the second block below the first
	j = 0;
	while (j < g_y - 2) // print g_y - 2 times B
	{
		ft_putchar('B');
		ft_putchar('\n'); // line break, to build the second block below the first
		j++;
	}
	ft_putchar('A'); // print the last A
	ft_putchar('\n'); // line break to make it pretier
}

void	rush(int xx, int yy) // function in charge of correctly using the other functions to make the pattern
{
	if (xx > 0 && yy > 0) // for "normal cases", where xx and yy are greater than 0, cannot print a negative number of caracters or invalid dimensions obviously
	{
		g_x = xx; // asigning the width to xx
		g_y = yy; // asigning the height to yy
		if (g_y == 1) // if g_y is 1, we want a line, we only use the vrush_top_bottom function once
		{
			rush_top_bottom();
		}
		else if (g_x == 1) // if we want a column, we use the rush_v function
		{
			rush_v();
		}
		else // here we have the cases where xx >= 2 && yy >= 2
		{
			rush_top_bottom();
			rush_middle();
			rush_top_bottom();
		}
	}
	else // to prevent errors, we do not accept negative, floats or characters, only natural numbers
	{
		write(1, "Please enter a natural number", 29);
		ft_putchar('\n'); // to make it pretty :)
	}
}
