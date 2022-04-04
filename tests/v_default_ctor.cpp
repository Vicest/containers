/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_default_ctor.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:52:08 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/04 23:33:17 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

class A {
	public:
		A(void) { std::cout << "CTOR" << std::endl; }
		A(A const& a) { std::cout << "COPY" << std::endl; }
		~A(void){ std::cout << "DTOR" << std::endl; }
};

#include <vector>
#ifdef STD
namespace ft = std;
#else
# include "../vector.hpp"
#endif

template < typename T >
void	test_ctors(const T& val)
{
	ft::vector< T >		empty;
	//Contructor with value bcause school's macs aren't fully c++98 compatible.
	ft::vector< T >		size_zero(0, val);
	ft::vector< T >		size_short(10, val);
	ft::vector< T >		size_large(4442, val);
	//TRY OTHER CTORS and check status TODO
	ft::vector< T >		my_iterator_constructor(size_short.begin(), size_short.end());
//	std::vector< T >	ref(20, val);
//	ft::vector< T >		iterator_constructor(ref.begin(), ref.end());
	try {
		ft::vector< T >	extra(std::numeric_limits< typename ft::vector<T>::size_type >::max(), val);
	} catch (std::length_error const&) {
	} catch (std::bad_alloc const&) {}
}

void	test_wrapper(void)
{
}

//TODO actually leaks could run this process but can't link with the leaks lib.
int	main(void) {
	//std::cout << "CPP Standard: " << __cplusplus << std::endl;
	test_wrapper();
	std::cout << "Int1" << std::endl;
	test_ctors< int >(5);
	std::cout << "Int2" << std::endl;
	test_ctors< int >(-1);
	std::cout << "Float" << std::endl;
	test_ctors< float >(42.42);
	std::cout << "Class" << std::endl;
	test_ctors< A >(A());
	//This actually uses copy ctor too.
	std::cout << "Vector" << std::endl;
	test_ctors< ft::vector< A > >(ft::vector< A >(5, A()));
	system("leaks -quiet a.out | grep LEAK:");
	return (42);

	//TODO migrate to different test?
//	std::cout << std::boolalpha;
//	std::cout << s1.size() << std::endl;
//	std::cout << s1.capacity() << std::endl;
//	std::cout << s1.empty() << std::endl;
//	std::cout << s1_arg_zero.size() << std::endl;
//	std::cout << s1_arg_zero.capacity() << std::endl;
//	std::cout << s1_arg_zero.empty() << std::endl;
}
