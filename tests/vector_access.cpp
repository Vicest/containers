/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_access.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:36:07 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/10 16:13:44 by vicmarti         ###   ########.fr       */
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
void	access(size_t size, T const& t) {
	typename test::vector<T>::size_type	i;

	const test::vector<T>	const_vec(size, t);
	test::vector<T>			vec = const_vec;
	for (i = 0; i < vec.size(); i++)
	{
		std::cout << ++vec[i] << "|" << const_vec[i] << std::endl;
		std::cout << ++vec.at(i) << "|" << const_vec.at(i) << std::endl;
		std::cout << ++vec.back() << "|" << const_vec.back() << std::endl;
		std::cout << ++vec.front() << "|" << const_vec.front() << std::endl;
	}

	std::cout << vec << std::endl << const_vec << std::endl;

	try {
		vec.at(-1);
	} catch(...) {}
	try {
		vec.at(0);
	} catch(...) {}
	try {
		vec.at(vec.size());
	} catch(...) {}
	try {
		vec.at(vec.size() + 1);
	} catch(...) {}
}

int	main(void) {
	A	a;
	A	b = a;
	access<int>(5, 123);
	access<float>(0, 23.1);
	access<A>(4, A());
	access<A>(0, A());
	access<char>(1, '*');
	system("leaks -quiet a.out | grep LEAK:");
}
