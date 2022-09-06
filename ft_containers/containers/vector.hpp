#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

#include "../utils/algorithm.hpp"
#include "../utils/iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/type_traits.hpp"


namespace ft
{

// https://cplusplus.com/reference/memory/allocator_traits/
template < class T, class Alloc = std::allocator<T> >
class vector
{
  public:
    typedef T value_type;
    typedef Alloc allocator_type;

    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::size_type size_type;


    typedef ft::random_access_iterator<value_type> iterator;
    typedef ft::random_access_iterator<const value_type> const_iterator;


  private:



  
};





};




#endif
