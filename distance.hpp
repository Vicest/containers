/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:59:20 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/19 15:59:39 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_HPP
# define DISTANCE_HPP

namespace ft
{
	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last) {
			typename iterator_traits<InputIterator>::difference_type	dist = 0;

			while (first != last)
				first++, dist++;
			return (dist);
	}
}
#endif

