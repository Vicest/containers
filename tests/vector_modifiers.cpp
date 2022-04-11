/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:17:13 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/11 20:33:23 by vicmarti         ###   ########.fr       */
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
void	push_pop(T const& t) {
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
	x.clear();
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
	v.insert(v.beign(), tcopy());
	w.insert(w.beign(), tcopy());
	std::cout << v << std::endl << w << std::endl;
	v.insert(v.beign(), x.begin());
	w.insert(w.beign(), x.begin());
	std::cout << v << std::endl << w << std::endl;
	v.insert(v.beign(), x.begin());
	w.insert(w.end(), x.begin()++);
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
	push_pop<int>(123);
	push_pop<A>(A());
	assign<int>(321);
	assign<A>(A());
	swap<int>(12);
	swap<A>(A());
	deletion<int>(444);
	deletion<A>(A());
	insertion<int>(111);
	insertion<A>(A());
#ifndef STD
	system("leaks -quiet a.out | grep LEAK:");
#endif
	return (42);
}
