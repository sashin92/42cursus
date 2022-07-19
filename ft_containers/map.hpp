#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <exception>


namespace ft {
  template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
  > class map{
    private:
    
    public:


   };

}

// iterators_traits

// • reverse_iterator

// • enable_if
// Yes, it is C++11 but you will be able to implement it in a C++98 manner.
// This is asked so you can discover SFINAE.

// • is_integral

// • equal and/or lexicographical_compare

// • std::pair

// • std::make_pair


#endif
