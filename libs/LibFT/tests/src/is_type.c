/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_type.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:56 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/25 22:44:19 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Lib to be tested
#include "libft.h"

// Functions to compare original to real version
#include <string.h>

// Testing lib
#include <criterion/criterion.h>

Test(is_alpha, basic) {
	cr_expect(ft_isalpha('A') == 1, "Expected 'A' to be alpha");
	cr_expect(ft_isalpha('Z') == 1, "Expected 'Z' to be alpha");
	cr_expect(ft_isalpha('9') == 0, "Expected '9' to be alpha");
	cr_expect(ft_isalpha(':') == 0, "Expected ':' to be alpha");
}

Test(is_print, basic) {
	cr_expect(ft_isprint('A') == 1, "Expected 'A' to be alpha");
	cr_expect(ft_isprint('Z') == 1, "Expected 'Z' to be alpha");
	cr_expect(ft_isprint('9') == 1, "Expected '9' to be alpha");
	cr_expect(ft_isprint(':') == 1, "Expected ':' to be alpha");

	// These should fail
	cr_expect(ft_isprint(0) == 0, "Expected 'null' to not be printable");
	cr_expect(ft_isprint(127) == 0, "Expected 'del' to not be printable");
	cr_expect(ft_isprint(12) == 0, "Expected 'np' to not be printable");
	cr_expect(ft_isprint(8) == 0, "Expected 'bs' to not be printable");
}

Test(is_alnum, basic) {
	cr_expect(ft_isalnum('b') == 1, "Expected 'A' to be alphanumeric");
	cr_expect(ft_isalnum('X') == 1, "Expected 'Z' to be alphanumeric");
	cr_expect(ft_isalnum('2') == 1, "Expected '9' to be alphanumeric");
	cr_expect(ft_isalnum('O') == 1, "Expected ':' to be alphanumeric");

	// These should fail
	cr_expect(ft_isalnum('"') == 0, "Expected 'null' to not be alphanumeric");
	cr_expect(ft_isalnum('+') == 0, "Expected 'del' to not be alphanumeric");
	cr_expect(ft_isalnum('`') == 0, "Expected 'np' to not be alphanumeric");
	cr_expect(ft_isalnum('~') == 0, "Expected 'bs' to not be alphanumeric");
}

Test(is_isascii, basic) {
	cr_expect(ft_isascii(0) == 1, "Expected '0' to be acii");
	cr_expect(ft_isascii(10) == 1, "Expected '10' to be acii");
	cr_expect(ft_isascii(43) == 1, "Expected '43' to be acii");
	cr_expect(ft_isascii(126) == 1, "Expected '126' to be acii");

	// These should fail
	cr_expect(ft_isascii(200) == 0, "Expected '200' to not be ascii");
	cr_expect(ft_isascii(-200) == 0, "Expected '-200' to not be ascii");
	cr_expect(ft_isascii(128) == 0, "Expected '128' to not be ascii");
	cr_expect(ft_isascii(-1) == 0, "Expected '-1' to not be ascii");
}

Test(is_isdigit, basic) {
	cr_expect(ft_isdigit('2') == 1, "Expected '2' to be a digit");
	cr_expect(ft_isdigit('8') == 1, "Expected '8' to be a digit");
	cr_expect(ft_isdigit('0') == 1, "Expected '0' to be a digit");
	cr_expect(ft_isdigit('9') == 1, "Expected '9' to be a digit");

	// These should fail
	cr_expect(ft_isdigit('a') == 0, "Expected '10' to not be a digit");
	cr_expect(ft_isdigit(']') == 0, "Expected ']' to not be a digit");
	cr_expect(ft_isdigit('=') == 0, "Expected '200' to not be a digit");
	cr_expect(ft_isdigit('\\') == 0, "Expected 'a' to not be a digit");
}
