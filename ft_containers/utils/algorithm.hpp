/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:02:12 by sashin            #+#    #+#             */
/*   Updated: 2022/08/29 19:13:08 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{
// https://cplusplus.com/reference/algorithm/equal/?kw=equal
template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  while (first1!=last1) {
    if (!(*first1 == *first2))
      return false;
    ++first1; ++first2;
  }
  return true;
}


template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
  while (first1!=last1) {
    if (!pred(*first1 == *first2))
      return false;
    ++first1; ++first2;
  }
  return true;
}



// https://cplusplus.com/reference/algorithm/lexicographical_compare/
template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || comp(*first2, *first1)) return false;
    else if (comp(*first1, *first2)) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}









}




#endif
