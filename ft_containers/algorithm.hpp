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
  
  template<typename Iterator1, typename Iterator2>
  bool equal(Iterator1 head1, Iterator1 tail1, Iterator2 head2)
  {
    while (head1 != tail1)
    {
      if (!(*head1 == *head2)) return false;
      ++head1, ++head2;
    }
    return true;
  }



}




#endif
