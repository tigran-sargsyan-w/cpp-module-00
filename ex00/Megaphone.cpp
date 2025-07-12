#include <cctype>
#include <iostream>
#include <string>

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
