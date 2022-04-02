/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:43:53 by vicmarti          #+#    #+#             */
/*   Updated: 2022/03/27 20:33:37 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
# include <iterator> //random_access_iterator_tag

namespace ft {
	template < class Iterator >
	struct iterator_traits {
		typedef Iterator::difference_type	difference_type;
		typedef Iterator::value_type		value_type;
		typedef Iterator::pointer			pointer;
		typedef Iterator::reference			reference;
		typedef Iterator::iterator_category	iterator_category;
	};

	template < class T >
	struct iterator_traits< T* > {
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template < class T >
	struct iterator_traits< const T* > {
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T							pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};
}
#endif
