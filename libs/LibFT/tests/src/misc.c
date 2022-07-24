/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:56 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/25 22:55:27 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Lib to be tested
#include "libft.h"

// Functions to compare original to real version
#include <string.h>

// Testing lib
#include <criterion/criterion.h>

Test(number_length, basic) {
	cr_expect(ft_nbrlen(1) == 1, "Expected '1' to be a length of '1'");
	cr_expect(ft_nbrlen(1234567) == 7, "Expected '1234567' to be a length of '7'");
	cr_expect(ft_nbrlen(-101) == 4, "Expected '-101' to be a length of '4'");
	cr_expect(ft_nbrlen(24839) == 5, "Expected '24839' to be a length of '5'");
}
