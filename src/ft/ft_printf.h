/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:52:50 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/17 13:28:58 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_nb(char c, int *count);
void	ft_putstr_nb(char *str, int *count);
void	ft_puthex(unsigned long nb, int *count, int arg, int first);
void	ft_putnbr_nb(int nbr, int	*count);
void	ft_put_u_nbr_nb(long int n, int *count);

#endif
