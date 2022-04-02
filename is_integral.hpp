/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:52:46 by vicmarti          #+#    #+#             */
/*   Updated: 2022/03/26 22:20:41 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include <type_traits> //TODO  allowed, reimplement?

namespace ft
{
	//TODO implement false/true types and check the boolean-ness
	template < typename T >
	struct is_integral : std::false_type {};

	template <>
	struct is_integral<bool> : std::true_type {};
	template <>
	struct is_integral<char> : std::true_type {};
	template <>
	struct is_integral<unsigned char> : std::true_type {};
	template <>
	struct is_integral<signed char> : std::true_type {};
	template <>
	struct is_integral<char16_t> : std::true_type {};
	template <>
	struct is_integral<char32_t> : std::true_type {};
	template <>
	struct is_integral<wchar_t> : std::true_type {};
	template <>
	struct is_integral<short int> : std::true_type {};
	template <>
	struct is_integral<int> : std::true_type {};
	template <>
	struct is_integral<long int> : std::true_type {};
	template <>
	struct is_integral<long long int> : std::true_type {};
	template <>
	struct is_integral<unsigned short int> : std::true_type {};
	template <>
	struct is_integral<unsigned int> : std::true_type {};
	template <>
	struct is_integral<unsigned long int> : std::true_type {};
	template <>
	struct is_integral<unsigned long long int> : std::true_type {};
};
#endif

