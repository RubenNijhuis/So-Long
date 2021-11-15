/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 09:45:43 by rnijhuis      #+#    #+#                 */
/*   Updated: 2021/11/09 09:45:44 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i + 1 != 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
