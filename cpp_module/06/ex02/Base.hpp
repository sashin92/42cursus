/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:38:31 by sashin            #+#    #+#             */
/*   Updated: 2022/04/28 20:18:02 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
private:
	Base(const Base &c);

public:

	Base();
	Base &operator=(const Base &c);
	virtual ~Base();
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
