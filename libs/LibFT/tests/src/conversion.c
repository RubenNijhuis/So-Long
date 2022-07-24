/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:56 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/03 20:30:51 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Lib to be tested
#include "libft.h"

// Functions to compare original to real version
#include <string.h>

// Testing lib
#include <criterion/criterion.h>

Test(ft_atoi, basic) {
	cr_expect(ft_atoi("100") == 100, "Expected '100' to be 100");
	cr_expect(ft_atoi("381932") == 381932, "Expected '381932' to be '381932'");
	cr_expect(ft_atoi("-100023") == -100023, "Expected '-100023' to be '-100023'");
	cr_expect(ft_atoi("-69696969") == -69696969, "Expected '-69696969' to be '-69696969'");
}

Test(ft_itoa, basic) {
	cr_expect(strcmp(ft_itoa(100), "100") == 0, "Expected '100'");
	cr_expect(strcmp(ft_itoa(-1231), "-1231") == 0, "Expected '-1231'");
	cr_expect(strcmp(ft_itoa(-1), "-1") == 0, "Expected '-1'");
	cr_expect(strcmp(ft_itoa(54857483), "54857483") == 0, "Expected '54857483'");
}

Test(to_lower, basic) {
	cr_expect(ft_tolower('A') == 'a', "Expected 'A' to be 'a'");
	cr_expect(ft_tolower('Z') == 'z', "Expected 'Z' to be 'z'");
	cr_expect(ft_tolower('G') == 'g', "Expected 'G' to be 'g'");
	cr_expect(ft_tolower('L') == 'l', "Expected 'L' to be 'l'");

	// These should fail
	cr_expect(ft_tolower('b') == 'b', "Expected 'b' to still be 'b' (98)");
	cr_expect(ft_tolower(']') == ']', "Expected ']' to still be ']' (93)");
	cr_expect(ft_tolower('=') == '=', "Expected '=' to still be '=' (61)");
	cr_expect(ft_tolower('0') == '0', "Expected '0' to still be '0' (48)");
}

Test(to_upper, basic) {
	cr_expect(ft_toupper('a') == 'A', "Expected 'a' to be 'A'");
	cr_expect(ft_toupper('b') == 'B', "Expected 'b' to be 'B'");
	cr_expect(ft_toupper('p') == 'P', "Expected 'p' to be 'P'");
	cr_expect(ft_toupper('z') == 'Z', "Expected 'z' to be 'Z'");

	// These should fail
	cr_expect(ft_toupper('0') == '0', "Expected 'b' to still be '0' (48)");
	cr_expect(ft_toupper('"') == '"', "Expected ']' to still be '\"' (34)");
	cr_expect(ft_toupper('1') == '1', "Expected '=' to still be '1' (49)");
	cr_expect(ft_toupper('&') == '&', "Expected '0' to still be '&' (38)");
}
