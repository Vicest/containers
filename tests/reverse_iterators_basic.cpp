/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterators_basic.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:59:50 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/15 17:48:43 by vicmarti         ###   ########.fr       */
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
void	test_relational_ops(reverse_iterator<It> r1, reverse_iterator<It> r2) {
	std::cout << r1 == r2 << std::endl;
	std::cout << r1 != r2 << std::endl;
	std::cout << r1 <= r2 << std::endl;
	std::cout << r1 >= r2 << std::endl;
	std::cout << r1 < r2 << std::endl;
	std::cout << r1 > r2 << std::endl;

	std::cout << r2 == r1 << std::endl;
	std::cout << r2 != r1 << std::endl;
	std::cout << r2 <= r1 << std::endl;
	std::cout << r2 >= r1 << std::endl;
	std::cout << r2 < r1 << std::endl;
	std::cout << r2 > r1 << std::endl;
}

int	main(void) {
	std::vector<int>			v;
	v::iterator					it;
	test::reverse_iterator<it>	rit;
	test::reverse_iterator<it>	rend;

	for (int i = 0; i < 20; i += 2) {
		v.add_back(i);
	}
	rend = test::reverse_iterator<v::iterator>(v.begin());
	rit = test::reverse_iterator<v::iterator>(v.end());
	while (rit != rend)
	{
		rit++, rit--, rit++;
		std::cout << *rit << std::endl;
	rit = test::reverse_iterator<v::iterator>(v.end());
	while (rit <= rend) {
		rit += 2;
		rit -= 1;
		rit = rit + 2;
		rit = rit - 1;
		std::cout << *(rit) << std::endl;
	}
	rit = test::reverse_iterator<v::iterator>(v.end());
	std::cout << rit[3] << std::endl;
	std::cout << rit[0] << std::endl;
	std::cout << *rit << std::endl;
	std::cout << rend[-3] << std::endl;
	rit += 5;
	rit = 1 + rit;
	std::cout << *rit << "|" << *(rit.base()) << std::endl;

	std::boolalpha;
	test_relational_ops(test::reverse_iterator<v::iterator>(v.end()), test::reverse_iterator<v::iterator>(v.end()));
	test_relational_ops(test::reverse_iterator<v::iterator>(v.begin()), test::reverse_iterator<v::iterator>(v.begin()));
	test_relational_ops(test::reverse_iterator<v::iterator>(v.begin()), test::reverse_iterator<v::iterator>(v.end()));
	test_relational_ops(test::reverse_iterator<v::iterator>(v.begin()), test::reverse_iterator<v::iterator>(++(v.begin()));
	std::cout << *(5 + test::reverse_iterator<v::iterator>(v.end())) << std::endl;
	std::cout << test::reverse_iterator<v::iterator>(v.begin()) - test::reverse_iterator<v::iterator>(v.end())) << std::endl;


}
