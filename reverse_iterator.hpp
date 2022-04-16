/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:38:39 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/15 17:47:12 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {
	template <class Iterator>
	class reverse_iterator
	{

		public:
			typename Iterator											iterator_type;
			typename ft:iterator_traits<Iterator>::iterator_category	iterator_category;
			typename fr::iterator_traits<Iterator>::value_type			value_type;
			typename fr::iterator_traits<Iterator>::difference_type		difference_type;
			typename fr::iterator_traits<Iterator>::pointer				pointer;
			typename fr::iterator_traits<Iterator>::reference			reference;

			reverse_iterator(void) {}
			explicit reverse_iterator(iterator_type it)
				: _base(it) {}
			reverse_iterator(reverse_iterator const& reverse_iterator)
				: _base(reverse_iterator._base) {}
			virtual ~reverse_iterator(void) {}
			reverse_iterator	&operator=(reverse_iterator const& reverse_iterator) {
				this->_base = reverse_iterator._base;
				return (*this);
			}

			iterator_type	base(void) const { return (this->_base); }
			reference			operator*(void) const {
				Iterator	aux = this->_base;
				return (*(--aux));
			}
			reference			operator[](difference_type n) const {
				return (this->_base[-n - 1]);
			}
			pointer				operator->(void) const { return &(*this); }
			reverse_iterator	&operator++(void) {
				--(this->_base);
				return (*this);
			}
			reverse_iterator	operator++(int) {
				reverse_iterator	aux = *this;
				--(this->_base);
				return (aux);
			}
			reverse_iterator	&operator--(void) {
				++(this->_base);
				return (*this);
			}
			reverse_iterator	operator--(int) {
				reverse_iterator	aux = *this;
				++(this->_base);
				return (aux);
			}
			reverse_iterator	operator+=(difference_type n) {
				this->_base -= n;
				return (*this);
			}
			reverse_iterator	operator-=(difference_type n) {
				this->_base += n;
				return (*this);
			}
			reverse_iterator	operator+(difference_type n) { return (reverse_iterator(this->base - n)); }
			reverse_iterator	operator-(difference_type n) { return (reverse_iterator(this->base + n)); }

		private:
			Iterator						_base;
	};

	template< class Iterator >
	bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }

	template< class Iterator >
	bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }

	template< class Iterator >
	bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }

	template< class Iterator >
	bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }

	template< class Iterator >
	bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.base()); }

	template< class Iterator >
	bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type	operator-(reverse_iterator<Iterator> const& lhs, reverse_iterator<Iterator> const& rhs) { return (rhs.base() - lhs.base()); }

	template< class Iterator >
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) { return (rev_it.operator+(n)); }
}
#endif
