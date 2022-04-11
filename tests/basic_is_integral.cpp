/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:09:46 by vicmarti          #+#    #+#             */
/*   Updated: 2022/03/28 23:06:06 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef STD
namespace ft = std;
#else
# include "../is_integral.hpp"
#endif

class dummy {};

int	main(void)
{
	typedef int new_type;
	std::cout << std::boolalpha;
	std::cout << ft::is_integral<new_type>() << std::endl;
	std::cout << ft::is_integral<int &>() << std::endl;
	std::cout << ft::is_integral<int *>() << std::endl;
	std::cout << ft::is_integral<wchar_t>() << std::endl;
	std::cout << ft::is_integral<float>::value << std::endl;
	std::cout << ft::is_integral<int>::value << std::endl;
	std::cout << ft::is_integral<dummy>::value << std::endl;
}
