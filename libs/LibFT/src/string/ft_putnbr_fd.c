/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:50:39 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/07 12:11:23 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int64_t n, uint32_t fd)
{
	char	s;
	int64_t	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		s = nb % 10 + '0';
		ft_putchar_fd(s, fd);
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
}
