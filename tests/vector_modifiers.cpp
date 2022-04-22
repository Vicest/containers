/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:17:13 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/22 21:16:48 by vicmarti         ###   ########.fr       */
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
void	push_pop(T const& type) {
	T				t(type);
	test::vector<T>	v;
	test::vector<T>	w(5, t);

	std::cout << v << std::endl << w << std::endl;
	for(int i = 0; i < 12; i++) {
		++t;
		v.push_back(t), w.push_back(t);
		std::cout << v << std::endl << w << std::endl;
	}
	while (!v.empty()) {
		v.pop_back();
		std::cout << v << std::endl;
	}
	while (!w.empty()) {
		w.pop_back();
		std::cout << w << std::endl;
	}
}

template < class T >
void	assign(T const& t) {
	test::vector<T>	v;
	test::vector<T>	w(5, t);
	std::vector<T>	s(12, t);


	std::cout << v << std::endl << w << std::endl;
	v.assign(3, t);
	std::cout << v << std::endl;
	v.assign(0, t);
	std::cout << v << std::endl;
	v.assign(w.begin() + 1, w.end() - 1);
	std::cout << v << std::endl;
	w.assign(s.begin(), s.end());
	std::cout << w << std::endl;
	w.assign(s.begin(), s.begin());
	std::cout << w << std::endl;
}

template < class T >
void	swap(T const& t) {
	test::vector<T>	v;
	test::vector<T>	w(5, t);

	std::cout << v << std::endl << w << std::endl;
	v.swap(v);
	std::cout << v << std::endl << w << std::endl;
	w.swap(w);
	std::cout << v << std::endl << w << std::endl;
	v.swap(w);
	std::cout << v << std::endl << w << std::endl;
	v.swap(w);
	std::cout << v << std::endl << w << std::endl;
}

template < class T >
void	deletion(T const& t) {
	test::vector<T>	v;
	test::vector<T>	w(5, t);
	test::vector<T>	x(10, t);
	test::vector<T>	xcopy(x);

	std::cout << xcopy << std::endl;
	xcopy.clear();
	std::cout << xcopy << std::endl;

	for (int i = 1; i < x.size(); i++) {
			x[i] = x[i - 1] + x[i];
	}
	std::cout << v << std::endl << w << std::endl << x << std::endl;
	x.erase(x.begin() + 3);
	std::cout << x << std::endl;
	x.erase(x.begin() + 2, x.begin() + 6);
	std::cout << x << std::endl;
	x.erase(x.begin(), x.end());
	std::cout << x << std::endl;
	std::cout << w << std::endl;
	w.clear();
	std::cout << w << std::endl;
	w.erase(w.begin(), w.end());
	std::cout << w << std::endl;
	std::cout << v << std::endl;
	v.clear();
	std::cout << v << std::endl;
	v.erase(v.begin(), v.end());
	std::cout << v << std::endl;
}

template < class T >
void	insertion(T const& t) {
	T				tcopy(t);
	test::vector<T>	v;
	test::vector<T>	w(5, tcopy);
	test::vector<T>	x(10, ++tcopy);
	std::vector<T>	y(14, ++tcopy);

	for (int i = 1; i < w.size(); i++) {
			w[i] = w[i - 1] + w[i];
	}
	for (int i = 1; i < x.size(); i++) {
			x[i] = x[i - 1] + x[i];
	}
	for (int i = 1; i < y.size(); i++) {
			y[i] = y[i - 1] + y[i];
	}
	std::cout << v << std::endl << w << std::endl << x << std::endl;
	++tcopy;
	std::cout << *(v.insert(v.begin(), tcopy)) << std::endl;
	std::cout << *(w.insert(w.begin(), tcopy)) << std::endl;
	std::cout << v << std::endl << w << std::endl;
	++tcopy;
	std::cout << *(v.insert(v.end(), tcopy)) << std::endl;
	std::cout << *(w.insert(w.end(), tcopy)) << std::endl;
	std::cout << v << std::endl << w << std::endl;
	++tcopy;
	v.insert(v.begin(), 1, tcopy);
	w.insert(w.begin(), 1, tcopy);
	std::cout << v << std::endl << w << std::endl;
	++tcopy;
	v.insert(v.begin(), 12, tcopy);
	w.insert(w.begin(), 12, tcopy);
	std::cout << v << std::endl << w << std::endl;
	++tcopy;
	v.insert(v.begin(), 0, tcopy);
	w.insert(w.begin(), 0, tcopy);
	std::cout << v << std::endl << w << std::endl;
	std::cout << "JAJAJAlol" << std::endl;
	v.insert(v.begin(), x.begin(), x.end());
	w.insert(w.begin(), x.begin(), x.end());
	std::cout << v << std::endl << w << std::endl;
	w.insert(w.end(), w.begin(), w.end());
	v.insert(v.begin(), y.begin(), y.begin());
	std::cout << v << std::endl << w << std::endl;
	w.insert(w.end(), w.end(), w.end());
	v.insert(v.begin(), y.begin(), y.end());
	std::cout << v << std::endl << w << std::endl;
	w.insert(w.end(), 10, v[0]);
	std::cout << v << std::endl << w << std::endl;
	v.insert(v.begin(), y.end(), y.end());
	w.insert(w.begin(), 1, v[2]);
	std::cout << v << std::endl << w << std::endl;
}

int	main(void) {
	std::cout << "PUSH_POP" << std::endl;
	push_pop<int>(123);
	push_pop<A>(A());
	std::cout << "ASSIGN" << std::endl;
	assign<int>(321);
	assign<A>(A());
	std::cout << "SWAP" << std::endl;
	swap<int>(12);
	swap<A>(A());
	std::cout << "DELETION" << std::endl;
	deletion<int>(444);
	deletion<A>(A());
	std::cout << "INSERTION" << std::endl;
	insertion<int>(111);
	insertion<A>(A());
#ifndef STD
	system("leaks -quiet a.out | grep LEAK:");
#endif
	return (42);
}
