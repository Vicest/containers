/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:48:17 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/04 23:33:01 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <cstddef> //size_t, ptrdiff_t
# include <memory> //allocator
# include <stdexcept> //out_of_range
# include <typeinfo> //typeid
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
//TODO remove v'v
# include <algorithm> //fill
# include <iterator> //distance TODO reimplement?

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef value_type*									iterator;
			typedef const value_type*							const_iterator;
			//typedef ...	reverse_iterator;
			//typedef ...	const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

			explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(0), _size(0) {
				this->_data = this->_alloc.allocate(0);
			}

			explicit vector(size_type n, const value_type& val=value_type()
					, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(n), _size(n) {
				this->_data = this->_alloc.allocate(n);
				this->construct_range(this->begin(), this->end(), val);
			}

			//TODO std::distance allowed?? reimplement?
			//TODO This just won't work
			template < class InputIterator >
//			template < class InputIterator, typename ft::iterator_traits<InputIterator>::value_type >
//					class ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator> =0 >
//			vector(typename ft::enable_if < ft::is_integral < InputIterator >::value, InputIterator >::value first,
//			ft::enable_if < ft::iterator_traits<InputIterator>::value_type == value_type >
			vector( typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type first,
					InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc)
			{
//				typename ft::iterator_traits<InputIterator>::value_type	value_type;

				this->_capacity = std::distance(first, last);
				this->_size = this->_capacity;
				this->_data = this->_alloc.allocate(this->_capacity);
				this->construct_range_copy(first, last, this->_data);
			}

			vector(vector const &vector)
			{
				*this = vector; //Easy mode? Will see how STD behaves. TODO
			};

			virtual ~vector(void)
			{
				this->destroy_range(this->begin(), this->end());
				this->_alloc.deallocate(this->_data, this->_capacity);
			}

			vector	&operator=(vector const &vector)
			{
				if (this == &vector)
					return (*this);
				this->destroy_range(this->begin(), this->end());
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = this->_alloc.allocate(vector._capacity);
				this->construct_range_copy(vector.begin(), vector.end(), this->_data);
				this->_capacity = vector._capacity;
				this->_size = vector._size;
				this->_alloc = allocator_type(vector._alloc);
				return (*this);
			};

			//ITERATORS
			iterator		begin(void) { return this->_data; }
			iterator		end(void) { return this->_data + this->_size; }
			const_iterator	begin(void) const { return this->_data; }
			const_iterator	end(void) const { return this->_data + this->_size; }
			//TODO
			//rbegin;
			//rend;

			//CAPACITY
			bool		empty(void) const { return (this->_size == 0); }
			size_type	size(void) const { return this->_size; }
			size_type	max_size(void) const { return this->_alloc.max_size(); }
			size_type	capacity(void) const { return this->_capacity; }
			size_type	resize(size_type n, value_type val = value_type())
			{
				value_type*	new_data;

				if (n < this->_size) {
					this->destroy_range(this->at(n), this->end());
					this->_size = n;
				} else if (n > this->_size) {
					new_data = this->_alloc.allocate(n);
					this->construct_range_copy(this->begin(), this->end(), new_data);
					this->construct_range(new_data + this->_size, new_data + n, val);
					this->destroy_range(this->begin(), this->end());
					this->_alloc.deallocate(this->data, this->_capacity);
					this->_data = new_data;
					this->_size = n;
					this->_capacity = n;
				}
			}
			void		reserve(size_type n)
			{
				value_type*	new_data;

				if (this->_capacity < n)
				{
					new_data = this->_alloc.allocate(n);
					this->construct_range_copy(this->begin(), this->end(), new_data);
					this->destroy_range(this->begin(), this->end());
					this->_alloc.deallocate(this->_data, this->_capacity);
					this->_data = new_data;
					this->_capacity = n;
				}
			}

			//ACCESS
			//Some have undef behaviours when OOR and others don't. :shrug:
			reference	operator [](size_type n) { return _data[n]; }
			reference	at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector");
				return _data[n];
			}
			reference	front(void) { return _data[0]; }
			reference	back(void) { return _data[_size - 1]; }

			const_reference	operator [](size_type n) const { return _data[n]; }
			const_reference	at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector");
				return _data[n];
			}
			const_reference	front(void) const { return _data[0]; }
			const_reference	back(void) const { return _data[_size - 1]; }

			//MODIFIERS
			//TODO fit to capacity if exceeds
//			template < class InputIterator >
//			void	assign(InputIterator first, InputIterator last);
			void	assign(size_type n, const value_type& val) {
				this->destroy_range(this->begin(), this->end());
				if (this->_capacity < n)
				{
					this->_alloc.deallocate(this->_data, this->_capacity);
					this->_data = this->_alloc.allocate(n);
					this->_capacity = n;
				}
				this->_size = n;
				this->construct_range(this->begin(), this->end(), val);
			}
			//TODO double capacity if full
//			void	push_back(const value_type& val);
			void	pop_back(void) {
				if (this->_size)
					return ;
				this->_size--;
				this->_alloc.destroy(this->end());
			}
			//TODO double capacity when full
//			iterator	insert(iterator position, const value_type& val);
//			void	insert(iterator position, size_type n, const value_type& val);
//			template < class InputIterator >
//			void	insert(iterator position, InputIterator first, InputIterator last);
			iterator	erase(iterator position) {
				iterator	eit = this->end();

				this->_alloc.destroy(position);
				this->_size--;
				while (position != eit)
					*position = *(++position);
			}
			iterator	erase(iterator first, iterator last) {
				iterator	eit = this->end();

				this->destroy_range(first, last);
				this->_size -= (last - first);
				while (last != eit)
					*first++ = *last++;
			}
//			void	swap(vector& x);
			void	clear(void) {
				this->destroy_range(this->begin(), this->end());
				this->_size = 0;
			}


			//ALLOC
			allocator_type	get_allocator(void) const { return this->_alloc; }

		private:
			allocator_type			_alloc;
			size_type				_capacity;
			size_type				_size;
			value_type*				_data;//TODO needs const-ness??

			//TODO make them static??
			void	destroy_range(iterator first, iterator last) {
				for(; first != last; first++)
					this->_alloc.destroy(first);
			}
			void	construct_range(iterator first, iterator last, const_reference val) {
				for(; first != last; first++)
					this->_alloc.construct(first, val);
			}
			void	construct_range_copy(const_iterator first, const_iterator last, iterator copy_first) {
				for(; first != last; first++, copy_first++)
					this->_alloc.construct(copy_first, *first);
			}
	};
}
#endif
