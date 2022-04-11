/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:46:21 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/08 20:24:30 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#ifdef STD
namespace test = std;
# include <vector>
#else
namespace test = ft;
# include "../vector.hpp"
#endif

template < class T >
void	test_fun(const T& t)
{
	test::vector<T>*	og = new test::vector<T>(12, t);
	test::vector<T>*	copy = new test::vector<T>(5, t);
	std::cout << *og << std::endl << *copy << std::endl;
	*copy = *og;
	*og = *og;
	std::cout << *og << std::endl << *copy << std::endl;
	delete og;
	delete copy;
}

int	main(void)
{
	test_fun<int>(1234);
	test_fun<double>(24.42);
	test_fun<A>(A());
#ifndef STD
	system("leaks -quiet a.out | grep LEAK:");
#endif
}
