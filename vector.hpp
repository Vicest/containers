/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:48:17 by vicmarti          #+#    #+#             */
/*   Updated: 2022/04/20 23:14:29 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <cstddef> //size_t, ptrdiff_t
# include <memory> //allocator
# include <stdexcept> //out_of_range
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "distance.hpp"

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
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
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

			template < class InputIterator >
			vector(typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type first,
					InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc)
			{
				this->_capacity = ft::distance(first, last);
				this->_size = this->_capacity;
				this->_data = this->_alloc.allocate(this->_capacity);
				this->construct_range_copy(first, last, this->_data);
			}

			vector(vector const &v)
			{
				this->_alloc = allocator_type(v._alloc);
				this->_size = v._size;
				this->_capacity = v._capacity;
				this->_data = this->_alloc.allocate(this->_capacity);
				this->construct_range_copy(v.begin(), v.end(), this->_data);
			};

			virtual ~vector(void)
			{
				this->destroy_range(this->begin(), this->end());
				this->_alloc.deallocate(this->_data, this->_capacity);
			}

			vector	&operator=(vector const &v)
			{
				if (this == &v)
					return (*this);
				this->destroy_range(this->begin(), this->end());
				this->_alloc.deallocate(this->_data, this->_capacity);
				//TODO this is being done in the ctor, maybe make it generic and private?
				this->_alloc = allocator_type(v._alloc);
				this->_size = v._size;
				this->_capacity = v._capacity;
				this->_data = this->_alloc.allocate(this->_capacity);
				this->construct_range_copy(v.begin(), v.end(), this->_data);
				//----
				return (*this);
			};

			//ITERATORS
			iterator		begin(void) { return this->_data; }
			iterator		end(void) { return this->_data + this->_size; }
			const_iterator	begin(void) const { return this->_data; }
			const_iterator	end(void) const { return this->_data + this->_size; }

			reverse_iterator		rbegin(void) { return reverse_iterator(this->end()); }
			const_reverse_iterator	rbegin(void) const { return reverse_iterator(this->end()); }
			reverse_iterator		rend(void) { return reverse_iterator(this->begin()); }
			const_reverse_iterator	rend(void) const { return reverse_iterator(this->begin()); }

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
			//Fit to capacity if exceeds
			template < class InputIterator >
			void	assign(typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type first,
					InputIterator last) {
				typename ft::iterator_traits<InputIterator>::difference_type elems = ft::distance(first, last);
				destroy_range(this->begin(), this->end());
				if (elems > this->_capacity)
				{
					this->_alloc.deallocate(this->_data, this->_capacity);
					this->_data = this->_alloc.allocate(elems);
					this->_capacity = elems;
				}
				construct_range_copy(first, last, this->_data);
				this->_size = elems;
			}

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

			//Double capacity if full
			void	push_back(const value_type& val) {
				value_type*	new_data;
				size_type	new_capacity;

				if (this->_size == this->_capacity)
				{
					new_capacity = this->enlarge_size(this->_capacity + 1, true);
					new_data = this->_alloc.allocate(new_capacity);
					this->construct_range_copy(this->begin(), this->end(), new_data);
					this->destroy_range(this->begin(), this->end());
					this->_alloc.deallocate(this->_data, this->_capacity);
					this->_data = new_data;
					this->_capacity = new_capacity;
				}
				this->_alloc.construct(this->_data + this->_size, val);
				this->_size++;
			}

			//I refuse to let _size undeflow
			void	pop_back(void) {
				if (this->_size == 0)
					return ;
				this->_size--;
				this->_alloc.destroy(this->end());
			}
			//Double capacity when full
			iterator	insert(iterator position, const value_type& val) {
				size_type	pos_index = position - this->begin();

				insert_generic(position, &val, &val, 1, false);
				return (this->begin() + pos_index);
			}

			void	insert(iterator position, size_type n, const value_type& val) {
				insert_generic(position, &val, &val, n, false);
			}

			template < class InputIterator >
			void	insert(iterator position, InputIterator first,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
				insert_generic(position, first, last, ft::distance(first, last), true);
			}

			iterator	erase(iterator first, iterator last) {
				iterator	eit = this->end();

				this->destroy_range(first, last);
				this->_size -= last - first;
				while (last != eit)
					*first++ = *last++;
				return (first);
			}

			iterator	erase(iterator position) {
				return	(this->erase(position, position + 1));
			}

			void	swap(vector& x) {
				vector	aux(x);

				if (this == &x)
					return ;
				x = *this;
				*this = aux;
			}

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
			value_type*				_data;

			template < class InputIterator >
			void	destroy_range(typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type first,
					InputIterator last) {
				for(; first != last; first++)
					this->_alloc.destroy(first);
			}

			//TODO generalize to have only one construct
			template < class InputIterator >
			void	construct_range(typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type first,
					InputIterator last, const_reference val) {
				for(; first != last; first++)
						this->_alloc.construct(&*first, val);
			}

			template < class InputIterator >
			void	construct_range_copy(typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type first,
					InputIterator last, iterator copy_first) {
				for(; first != last; first++, copy_first++)
					this->_alloc.construct(copy_first, *first);
			}

			template<class InputIterator>
			void	insert_generic(iterator pos, InputIterator first, InputIterator last, size_type n, bool is_range) {
				size_type	insert_size = n;
				
				if (this->_capacity < this->_size + insert_size)
					resize_insert(pos, first, last, insert_size, is_range);
				else
					inplace_insert(pos, first, last, insert_size, is_range);
			}

			template<class InputIterator>
			void	resize_insert(iterator pos, InputIterator first, InputIterator last, size_type insert_size, bool is_range) {
				size_type	new_capacity = enlarge_size(this->_size + insert_size, true);
				size_type	pos_index = pos - this->begin();
				value_type*	new_data;

				new_data = this->_alloc.allocate(new_capacity);
				construct_range_copy(this->begin(), pos, new_data);
				if (is_range)
					construct_range_copy(first, last, new_data + pos_index);
				else
					construct_range(new_data + pos_index, new_data + pos_index + insert_size, *first);
				construct_range_copy(pos, this->end(), new_data + pos_index + insert_size);
				destroy_range(this->begin(), this->end());
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = new_data;
				this->_capacity = new_capacity;
				this->_size += insert_size;
			}

			template<class InputIterator>
			void	inplace_insert(iterator pos, InputIterator first, InputIterator last, size_type insert_size, bool is_range) {
				for (reverse_iterator rit(this->rbegin()), reit(pos);
						rit != reit;
						rit++)
					rit[-insert_size] = rit[0];
				if (is_range)
					construct_range_copy(first, last, pos);
				else
					construct_range(pos, pos + insert_size, *first);
				this->_size += insert_size;
			}

			size_type	enlarge_size(size_type min, bool duplicate) {
				size_type	buff_size = min;

				if (duplicate) {
					buff_size = this->_capacity;
					if (buff_size == 0)
						buff_size = 1;
					while (min > buff_size)
						buff_size <<= 1;
				}
				return (buff_size);
			}
	};
}
#endif
