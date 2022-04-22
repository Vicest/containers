/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators_basic.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:59:50 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/19 14:33:23 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#ifdef STD
namespace test = std;
# include <vector>
# include <iterator>
#else
namespace test = ft;
# include "../vector.hpp"
# include "../reverse_iterator.hpp"
#endif

template< class It >
void	test_relational_ops(It r1, It r2) {
	std::cout << (r1 == r2) << std::endl;
	std::cout << (r1 != r2) << std::endl;
	std::cout << (r1 <= r2) << std::endl;
	std::cout << (r1 >= r2) << std::endl;
	std::cout << (r1 < r2) << std::endl;
	std::cout << (r1 > r2) << std::endl;

	std::cout << (r2 == r1) << std::endl;
	std::cout << (r2 != r1) << std::endl;
	std::cout << (r2 <= r1) << std::endl;
	std::cout << (r2 >= r1) << std::endl;
	std::cout << (r2 < r1) << std::endl;
	std::cout << (r2 > r1) << std::endl;
}

int	main(void) {
	std::vector<int>									v;
	std::vector<int>::iterator							it;
	test::reverse_iterator<std::vector<int>::iterator>	rit;
	test::reverse_iterator<std::vector<int>::iterator>	rend;

	for (int i = 0; i < 20; i += 2) {
		v.push_back(i);
	}
	rend = test::reverse_iterator<std::vector<int>::iterator>(v.begin());
	rit = test::reverse_iterator<std::vector<int>::iterator>(v.end());
	while (rit != rend)
	{
		std::cout << *rit << std::endl;
		rit++, rit--, rit++;
	}
	rit = test::reverse_iterator<std::vector<int>::iterator>(v.end());
	while (rit < rend) {
		std::cout << *(rit) << std::endl;
		rit += 2;
		rit -= 1;
		rit = rit + 2;
		rit = rit - 1;
	}
	rit = test::reverse_iterator<std::vector<int>::iterator>(v.end());
	std::cout << rit[3] << std::endl;
	std::cout << rit[0] << std::endl;
	std::cout << *rit << std::endl;
	std::cout << rend[-3] << std::endl;
	rit += 5;
	rit = 1 + rit;
	std::cout << *rit << "|" << *(rit.base()) << std::endl;

	std::cout << std::boolalpha;
	test_relational_ops(
			test::reverse_iterator<std::vector<int>::iterator>(v.end()),
			test::reverse_iterator<std::vector<int>::iterator>(v.end()));
	test_relational_ops(
			test::reverse_iterator<std::vector<int>::iterator>(v.begin()),
			test::reverse_iterator<std::vector<int>::iterator>(v.begin()));
	test_relational_ops(
			test::reverse_iterator<std::vector<int>::iterator>(v.begin()),
			test::reverse_iterator<std::vector<int>::iterator>(v.end()));
	test_relational_ops(
			test::reverse_iterator<std::vector<int>::iterator>(v.begin()),
			test::reverse_iterator<std::vector<int>::iterator>(++(v.begin())));
	std::cout << *(5 + test::reverse_iterator<std::vector<int>::iterator>(v.end())) << std::endl;
	std::cout << test::reverse_iterator<std::vector<int>::iterator>(v.begin())
			- test::reverse_iterator<std::vector<int>::iterator>(v.end()) << std::endl;
}
