/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 21:57:50 by ina               #+#    #+#             */
/*   Updated: 2020/04/02 01:15:01 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_atoi(const char *str)
{
	int idx;
	unsigned int num;

	num = 0;
	idx = 0;
	while (str[idx] && str[idx] >= '0' && str[idx] <= '9')
	{
		num *= 10;
		num += str[idx] - '0';
		idx++;
	}
	if (str[idx])
	{
		write(2, "Error : please enter number only\n", 33);
		return (0);
	}
	if (idx > 9 || num < 2)
	{
		write(2, "Error : Please enter numbers form 2 to 2^32 - 1\n", 48);
		return (0);
	}
	return (num);
}

void			ft_putnbr(unsigned int num)
{
	char c;

	if (num > 10)
		ft_putnbr(num / 10);
	c = '0' + (num % 10);
	write(1, &c, 1);
}

void			ft_print_primes(unsigned int *primes, unsigned int size)
{
	unsigned int	idx;
	int				is_printed;

	is_printed = 0;
	idx = 2;
	while (idx < size)
	{
		if (primes[idx])
		{
			if (is_printed)
				write(1, " ", 1);
			is_printed = 1;
			ft_putnbr(idx);
		}
		idx++;
	}
	write(1, "\n", 1);
}

void			ft_factorization(unsigned int target)
{
	unsigned int idx;
	unsigned int primes[65536];

	idx = 2;
	while (idx <= 65535 && target > 1)
	{
		primes[idx] = 0;
		if (target % idx == 0)
		{
			while (!(target % idx))
				target /= idx;
			primes[idx] = 1;
		}
		idx++;
	}
	ft_print_primes(primes, idx);
}

int				main(int argc, char *argv[])
{
	unsigned int target;

	if (argc > 2)
	{
		write(2, "Error : Too many arguments\n", 27);
		return (1);
	}
	if (argc < 2)
	{
		write(2, "Error : Too few arguments\n", 26);
		return (1);
	}
	target = ft_atoi(argv[1]);
	if (!target)
		return (1);
	ft_factorization(target);
	return (0);
}
