/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 06:20:37 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/02 06:28:01 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

class A {
	public:
		A(void) { std::cout << "CTOR" << std::endl; }
		A(A const& a) { std::cout << "COPY" << std::endl; }
		~A(void){ std::cout << "DTOR" << std::endl; }
		A	&operator=(const A& rhs) { std::cout << "ASGN" << std::endl; return (*this); }
};

#include <vector>
int	main(void)
{
	std::cout << "CREAT" << std::endl;
	std::vector<A>	v(4, A());
	std::cout << "ERASE" << std::endl;
	v.erase(v.begin()+1);
	std::cout << "DONE" << std::endl;
}
