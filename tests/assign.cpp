/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:46:21 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/02 02:57:26 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

class A {
	public:
		int	_a;

		A(void) : _a(0) { std::cout << "CTOR" << std::endl; }
		A(A const& a) : _a(a._a) { std::cout << "COPY" << std::endl; }
		~A(void){ std::cout << "DTOR" << std::endl; }
};

#ifdef STD
namespace ft = std;
# include <vector>
#else
# include "../vector.hpp"
#endif

template < typename T >
void	test_fun(const T& t)
	//TODO it should use methods to check the contents
{
	ft::vector<T>*	og = new ft::vector<T>;
	ft::vector<T>*	copy = new ft::vector<T>;
	*copy = *og;
	*og = *og;
	delete og;
	delete copy;
}

int	main(void)
{
	test_fun<int>(1234);
	test_fun<double>(24.42);
	test_fun<A>(A());
	system("leaks -quiet a.out | grep LEAK:");
}
