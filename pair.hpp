/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:22:50 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/22 22:12:57 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first;
		T2	second;

		pair(void)
			: first(first_type()), second(second_type()) {}

		pair(const first_type& a, const second_type& b)
			: first(a), second(b) {}

		template <U, V>
		pair(const pair<U, V>& pr)
			: first(pr.first), second(pr.second) {}

		pair&	operator=(const pair& pr) {
			this->first = first_type(pr.first);
			this->second = second_type(pr.second);
			return *this;
		}
	}

	template <class T1, class T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool	operator< (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return ((lhs.first < rhs.first)
			|| (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(rhs < lhs));
	}
	template <class T1, class T2>
	bool	operator> (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T1, class T2>
	pair<T1, T2>&	make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}
}
#endif
