/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hailstone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:22:43 by mvann             #+#    #+#             */
/*   Updated: 2018/06/10 18:53:28 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void print_long_in_binary(long n, int extras)
{
	long  b;
	int count;

	count = 0;
	if (extras)
		printf("%20li: ", n);
	else
		printf("%20c: ", ' ');
	if (extras && n % 2 == 0)
		printf("%80c", ' ');
	b = 0x4000000000000000;
	while (b)//int i = 0; i < (sizeof (long)) * 8 - 1; i++)
	{
		// printf("\n%li: b\n", b);

		printf("%c", (n & b) ? '1' : '.');
		count += (n & b) ? 1 : 0;
		b = b >> 1;
	}
	if (extras)
		printf(" %2i %s", count, n & 1 ? "Odd" : " ");
	printf("\n");
}

int main(int ac, char ** av)
{
	long n;

	if (ac != 2)
	{
		printf("Include 1 number as an argument.\n");
		return (0);
	}
	n = strtol(av[1], NULL, 10);
	print_long_in_binary(n, 1);
	while (n != 1)
	{
		if (n & 1)
		{
			// print_long_in_binary(n, 0);
			print_long_in_binary(n + n + 1, 0);
			print_long_in_binary(n + n + n, 0);
			print_long_in_binary(n + n + n + 1, 0);
			// print_long_in_binary((long)1, 0);
			n = n * 3 + 1;
		}
		else
			n = n >> 1;
		if (n % 2 != 0)
		print_long_in_binary(n, 1);
	}
	return (0);
}
