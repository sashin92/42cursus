#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"


namespace ft
{

template <class T>
class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
  public:

    typedef typename iterator_traits<T*>::difference_type difference_type;
    typedef typename iterator_traits<T*>::value_type value_type;
    typedef typename iterator_traits<T*>::pointer pointer;
    typedef typename iterator_traits<T*>::reference reference;
    typedef typename iterator_traits<T*>::iterator_category iterator_category;
    
    random_access_iterator() : m_ptr(NULL) {}
    random_access_iterator(pointer ptr) : m_ptr(ptr) {}
    random_access_iterator(const random_access_iterator& src) { *this = src; }
    ~random_access_iterator() {}

    random_access_iterator& operator=(const random_access_iterator& src)
    {
      if (this != &src)
        m_ptr = src.m_ptr;
      return *this;
    }

    pointer operator->() const { return m_ptr; }
    reference operator*() const { return *m_ptr; }

    reference operator[](difference_type n) const { return m_ptr[n]; }

    random_access_iterator operator++()
    {
      ++m_ptr;
      return *this;
    }

    random_access_iterator operator++(int)
    {
      random_access_iterator tmp = *this;
      ++m_ptr;
      return tmp;
    }
    
    random_access_iterator operator--()
    {
      --m_ptr;
      return *this;
    }

    random_access_iterator operator--(int)
    {
      random_access_iterator tmp = *this;
      --m_ptr;
      return tmp;
    }

    random_access_iterator& operator+=(difference_type n)
    {
      m_ptr += n;
      return *this;
    }

    random_access_iterator& operator-=(difference_type n)
    {
      m_ptr -= n;
      return *this;
    }

    random_access_iterator& operator+(difference_type n)
    {
      random_access_iterator result = *this;
      result += n;
      return result;
    }

    random_access_iterator& operator-(difference_type n)
    {
      random_access_iterator result = *this;
      result -= n;
      return result;
    }


    // friend difference_type operator-(const random_access_iterator& lhs, const random_access_iterator& rhs)
    // {
    //   return rhs.m_ptr - lhs.m_ptr;
    // }

    bool operator==(const random_access_iterator& rhs)
    {
      return ((*this).m_ptr == rhs.m_ptr);
    }

    bool operator!=(const random_access_iterator& rhs)
    {
      return ((*this).m_ptr != rhs.m_ptr);
    }

    bool operator>(const random_access_iterator& rhs)
    {
      return ((*this).m_ptr > rhs.m_ptr);
    }

    bool operator>=(const random_access_iterator& rhs)
    {
      return ((*this).m_ptr >= rhs.m_ptr);
    }

    bool operator<(const random_access_iterator& rhs)
    {
      return ((*this).m_ptr < rhs.m_ptr);
    }

    bool operator<=(const random_access_iterator& rhs)
    {
      return ((*this).m_ptr <= rhs.m_ptr);
    }

    private:
      pointer m_ptr;
};



//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////



};




#endif
