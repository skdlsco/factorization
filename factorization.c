/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 21:57:50 by ina               #+#    #+#             */
/*   Updated: 2020/04/02 16:21:42 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				ft_is_invalid_number(const char *number)
{
	const char	max[] = "4294967295";
	int			zero_size;
	int			idx;
	int			len;

	len = 0;
	zero_size = 0;
	while (number[zero_size] == '0')
		zero_size++;
	while (number[zero_size + len])
		len++;
	if (len == 1)
		return (number[zero_size] < '2');
	if (len < 10)
		return (0);
	idx = 0;
	while (idx < len)
	{
		if (number[zero_size + idx] > max[idx])
			return (1);
		idx++;
	}
	return (0);
}

unsigned int	ft_atoi(const char *str)
{
	int				idx;
	unsigned int	num;

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
		write(2, "Error : please input number only\n", 33);
		return (0);
	}
	if (ft_is_invalid_number(str) || num <= 1)
	{
		write(2, "Error : Please input numbers between 2 to 2^32 - 1\n", 51);
		return (0);
	}
	return (num);
}

void			ft_putnbr(unsigned int num)
{
	char c;

	if (num >= 10)
		ft_putnbr(num / 10);
	c = '0' + (num % 10);
	write(1, &c, 1);
}

void			ft_factorization(unsigned int target)
{
	unsigned int	idx;
	int				is_printed;

	idx = 2;
	is_printed = 0;
	while (idx <= 65535 && target > 1)
	{
		if (target % idx == 0)
		{
			while (!(target % idx))
				target /= idx;
			if (is_printed)
				write(1, " ", 1);
			is_printed = 1;
			ft_putnbr(idx);
		}
		idx++;
	}
	if (target != 1)
	{
		if (is_printed)
			write(1, " ", 1);
		ft_putnbr(target);
	}
	write(1, "\n", 1);
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
