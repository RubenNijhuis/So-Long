/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:49:49 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/08 17:34:28 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int32_t	overflow_check(const char *str, int32_t sign)
{
	int32_t	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	if (i >= 20 && sign == -1)
		return (0);
	else if (i >= 20 && sign == 1)
		return (-1);
	return (2);
}

int64_t	ft_atoi(const char *src)
{
	int32_t		sign;
	int64_t		val;
	uint32_t	i;

	sign = 1;
	val = 0;
	i = 0;
	while (ft_isinset("\t\n\v\f\r ", src[i]))
		i++;
	if (src[i] == '+' || src[i] == '-')
	{
		if (src[i] == '-')
			sign = -1;
		i++;
	}
	if (overflow_check(&src[i], sign) < 2)
		return (overflow_check(&src[i], sign));
	while (ft_isdigit(src[i]))
	{
		val *= 10;
		val += src[i] - '0';
		i++;
	}
	return ((int64_t) val * sign);
}
