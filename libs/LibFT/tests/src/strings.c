/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strings.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:55 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/03 22:57:25 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Lib to be tested
#include "libft.h"

// Functions to compare original to real version
#include <string.h>

// Testing lib
#include <criterion/criterion.h>

Test(ft_strlen, basic) {
	cr_expect(ft_strlen("100") == 3, "Expected '100' to be a length of 3");
	cr_expect(ft_strlen("dhwuahdwaiojdiowajidjwiajdiojwahfufejaidfoawdpkaopfjnaueidijaopfgioewuqrwyaeruihfdbzncmpoaxjdmfnuaiailjwianodfbeaiuoirujnfaiuflisrjdmqainousfkgjhsrjiadnfeuabifkjwajdilwajfmidogzujfpa") == 182, "Expected a length of 182 chars");
	cr_expect(ft_strlen("") == 0, "Expected '' to be a length of 0");
	cr_expect(ft_strlen("Today is a great day") == 20, "Expected 'Today is a great day' to have a length of 21");
}

Test(ft_strlcpy, basic) {
	const char *src = "String to be copied";
	char *dst = calloc(strlen(src) + 1, sizeof(char));
	ft_strlcpy(dst, src, strlen(src) + 1);

	cr_expect(strcmp(src, dst) == 0, "Expected the string to be copied over");
}

Test(ft_strlcat, passing) {
	char *str = "This is a string that might be long";
	char buffer[17];

	ft_strlcat(buffer,str,17);
	cr_expect(strcmp(buffer, "This is a string") == 0, "Expected the string to be concatenated");
}

Test(ft_strncmp, passing) {
	char *strmain = "This is a string that might be long";
	char *strsecondary = "This is a string that might be long";

	cr_expect(ft_strncmp(strmain, strsecondary, strlen(strmain)) == 0, "Expected the strings to be equal (0)");

	char *strtrue = "This string is not equal to the next";
	char *strfalse = "This string is equal to the previous";

	cr_expect(ft_strncmp(strtrue, strfalse, strlen(strmain)) > 1, "Expected the strings to be equal (0)");
}

Test(ft_split, passing)
{
	char *test_string = "This is a string";
	char **split_string = ft_split(test_string, ' ');

	cr_expect(strcmp(split_string[0], "This") == 0, "Expected the first word to be to be 'This'");
	cr_expect(strcmp(split_string[3], "string") == 0, "Expected the last word to be to be 'string'");

	char *secondary_test_string = "This:string:is:split:based:on:colons";
	char **secondary_split_string = ft_split(secondary_test_string, ':');

	cr_expect(strcmp(secondary_split_string[1], "string") == 0, "Expected the second word to be to be 'string'");
	cr_expect(strcmp(secondary_split_string[5], "on") == 0, "Expected the sixth word to be to be 'on'");
}

Test(ft_strdup, passing)
{
	char *origin = "Yo i am this string";
	char *origin_dup = ft_strdup(origin);

	cr_expect(strcmp(origin, origin_dup) == 0, "Expected the strings to match after dup");
}

Test(ft_strchr, passing)
{
	char search_char = 'a';
	char *search = "Yo i am this string";

	char *found_char = ft_strchr(search, search_char);
	cr_expect(found_char[0] == 'a', "Expected the char to be found");
}

Test(ft_substr, passing)
{
	char *full_str = "Mischief managed";
	char *second_word;
	char *expected_output = "managed";

	second_word = ft_substr(full_str, 9, strlen(expected_output));
	cr_expect(strcmp(second_word, expected_output) == 0, "Expected the output to be 'managed'");
}

Test(ft_strjoin, passing)
{
	char *first_string = "Hello ";
	char *second_string = "World!";
	char *expected_output = "Hello World!";

	char *joined_str = ft_strjoin(first_string, second_string);
	cr_expect(strcmp(expected_output, joined_str) == 0, "Expected the output to be 'Hello World!'");
}

Test(ft_strnstr, passing)
{
	char *searchable_string = "Hello world";
	char *searchable_word = "world";
	char *word_found = ft_strnstr(searchable_string, searchable_word, strlen(searchable_string));

	cr_expect(strcmp(word_found, searchable_word) == 0, "Expected the string 'world' to be found");
}
