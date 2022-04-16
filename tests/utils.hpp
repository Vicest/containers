/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:20:31 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/11 22:02:34 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include "../vector.hpp"

class A {
	private:
		int	_num;
	public:
		A(void) : _num(42) { std::cout << "CTOR" << std::endl; }
		A(A const& a) : _num(a._num) { std::cout << "COPY" << std::endl; }
		~A(void){ std::cout << "DTOR" << std::endl; }
		A	&operator=(A const& rhs) {
			std::cout << "ASGN" << std::endl;
			this->_num = rhs._num;
			return (*this);
		}

		A	&operator++(void) {
			this->_num += 1;
			return (*this);
		}
		A	&operator+(A const& rhs) {
			this->_num += rhs._num;
			return (*this);
		}

		int	getNum(void) const { return this->_num; }
};

std::ostream	&operator<<(std::ostream & out, A const& a) {
	out << a.getNum();
	return (out);
}

template < class T >
std::ostream	&operator<<(std::ostream & out, ft::vector<T> const& v) {
	typename ft::vector<T>::const_iterator	it = v.begin();
	typename ft::vector<T>::const_iterator	eit = v.end();

	out << std::boolalpha;
	out << "Size: " << v.size() << std::endl;
	out << "Is empty: " << v.empty() << std::endl;
	for (; it != eit; it++) {
		out << *it << std::endl;
	}
	return (out);
}

# include <vector>
template < class T >
std::ostream	&operator<<(std::ostream & out, std::vector<T> const& v) {
	typename std::vector<T>::const_iterator	it = v.begin();
	typename std::vector<T>::const_iterator	eit = v.end();

	out << std::boolalpha;
	out << "Size: " << v.size() << std::endl;
	out << "Is empty: " << v.empty() << std::endl;
	for (; it != eit; it++) {
		out << *it << std::endl;
	}
	return (out);
}
#endif
