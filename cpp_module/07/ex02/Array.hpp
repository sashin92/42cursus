/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:56:40 by sashin            #+#    #+#             */
/*   Updated: 2022/04/29 13:00:10 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template<class T>
class Array
{
private:
	T* m_element;
	unsigned int m_size;

public:

	class OutofBoundException: public std::exception
	{
		const char* what() const throw()
		{
			return "Out of bound";
		}
	};

	unsigned int size() const
	{
		return m_size;
	}


	Array()
	: m_element(0), m_size(0)
	{
		m_element = new T[m_size];
	}
	
	Array(unsigned int size)
	: m_element(0), m_size(size)
	{
		m_element = new T[m_size];
	}

	T& operator[](unsigned int i)
	{
		if (i >= m_size)
			throw OutofBoundException();
		return m_element[i];
	}

	Array& operator=(const Array& src)
	{
		if (this != &src)
		{
			m_size = src.m_size;
			if (m_element)
			{
				delete[] m_element;
				m_element = 0;
			}
			m_element = new T(src.m_size);
			for (int i = 0; i < src.m_size; i++)
				m_element[i] = src.m_element[i];
		}
		return *this;
	}

	Array(const Array& src)
	: m_element(0), m_size(src.m_size)
	{
		m_element = new T[src.m_size];
		for (int i = 0; i < src.m_size; i++)
			m_element[i] = src.m_element[i];
	}

	~Array()
	{
		std::cout << "destructor!!" << std::endl;
		if (m_element)
			delete[] m_element;
		m_element = 0;
	}

};


#endif
