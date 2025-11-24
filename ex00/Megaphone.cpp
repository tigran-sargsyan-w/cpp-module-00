/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:27:14 by tsargsya          #+#    #+#             */
/*   Updated: 2025/11/24 15:27:15 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

/**
 * @brief Convert program arguments to uppercase and print them concatenated.
 *
 * This program takes any command-line arguments, converts each character
 * to uppercase and prints them in order without additional separators.
 * If no arguments are provided, a default loud message is printed.
 *
 * @param argc Number of command-line arguments (including program name).
 * @param argv Array of C-strings representing the arguments.
 * @return int Exit status (0 on success).
 */
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string str = argv[i];
			for (size_t j = 0; j < str.length(); ++j)
			{
				str[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
			}
			std::cout << str;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
	return (0);
}
