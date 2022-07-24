/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:32:34 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/02 19:39:54 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_u_nbr_nb(long int n, int *count)
{
	if ((int)n < 0)
	{
		n -= UINT_MAX - 1;
		ft_putnbr_nb(n, count);
	}
	else if (n <= 9)
	{
		n += '0';
		ft_putchar_nb(n, count);
	}
	else
	{
		ft_putnbr_nb(n / 10, count);
		ft_putnbr_nb(n % 10, count);
	}
}

void	ft_putchar_nb(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
	return ;
}

void	ft_putstr_nb(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		ft_putchar_nb(str[i++], count);
	}
	return ;
}

void	ft_puthex(unsigned long nb, int *count, int arg, int first)
{
	unsigned long	hex;
	int				letter;
	int				len;

	len = ft_nbrlen(nb);
	letter = 'a';
	if (arg == 'X')
		letter = 'A';
	else if (arg == 'p')
	{
		arg = 'n';
		ft_putstr_nb("0x", count);
	}
	if (len == 0 && first)
		return (ft_putchar_nb('0', count));
	if (nb > 0)
	{
		ft_puthex(nb / 16, count, arg, 0);
		hex = nb % 16;
		if (hex > 9)
			ft_putchar_nb(hex + letter - 10, count);
		else
			ft_putchar_nb(hex + '0', count);
	}
	return ;
}

void	ft_putnbr_nb(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr_nb("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_nb('-', count);
		n *= -1;
		ft_putnbr_nb(n, count);
	}
	else if (n <= 9)
	{
		n += '0';
		ft_putchar_nb(n, count);
	}
	else
	{
		ft_putnbr_nb(n / 10, count);
		ft_putnbr_nb(n % 10, count);
	}
}
