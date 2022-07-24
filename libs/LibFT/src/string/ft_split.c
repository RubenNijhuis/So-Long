/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 15:50:42 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/15 23:39:19 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static uint32_t	word_len(char const *s, char c)
{
	uint32_t	i;

	i = 0;
	while (*s != c && *s != 0)
	{
		s++;
		i++;
	}
	return (i);
}

static uint32_t	get_amount_of_words(char const *s, char c)
{
	uint32_t	amount_words;
	uint32_t	new_word;
	uint32_t	i;

	amount_words = 0;
	new_word = 0;
	i = 0;
	while (*s != 0)
	{
		if (new_word == 0 && *s != c)
		{
			amount_words++;
			new_word = !new_word;
		}
		if (*s == c)
			new_word = 0;
		i++;
		s++;
	}
	return (amount_words);
}

static void	add_words_to_string(const char *s, char c, char ***string)
{
	uint32_t	new_word;
	uint32_t	n_words;

	new_word = 0;
	n_words = 0;
	while (*s != 0)
	{
		if (new_word == 0 && *s != c)
		{
			new_word = !new_word;
			(*string)[n_words] = ft_calloc((word_len(s, c) + 1), sizeof(char));
			if ((*string)[n_words] == NULL)
			{
				ft_free_2d_array(string, n_words);
				return ;
			}
			ft_strlcpy((*string)[n_words], s, word_len(s, c) + 1);
			n_words++;
		}
		if (*s == c)
			new_word = 0;
		s++;
	}
}

/**
 * @brief 
 * Splits a string based on character
 * and returns a null-terminated char * array
 * 
 * @param s to be split
 * @param c to split on
 * @return char**
 */
char	**ft_split(char const *s, char c)
{
	char		**string;
	uint32_t	amount_of_words;

	if (s == NULL)
		return (NULL);
	amount_of_words = get_amount_of_words(s, c);
	string = ft_calloc((amount_of_words + 1), sizeof(char *));
	if (string == NULL)
		return (NULL);
	string[amount_of_words] = NULL;
	add_words_to_string(s, c, &string);
	return (string);
}
