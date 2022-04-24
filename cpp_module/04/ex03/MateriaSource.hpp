/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:13:49 by sashin            #+#    #+#             */
/*   Updated: 2022/04/24 18:13:49 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "Character.hpp"
# include "IMateriaSource.hpp"

# define MATERIASOURCE_SIZE 4

class MateriaSource: public IMateriaSource
{
private:
	AMateria* m_materiaSource[MATERIASOURCE_SIZE];

public:
  const AMateria* getAMateria(int idx) const;

  void learnMateria(AMateria* m);
  AMateria* createMateria(const std::string& type);

  MateriaSource(void);
  MateriaSource& operator=(const MateriaSource& src);
  MateriaSource(const MateriaSource& src);
  virtual ~MateriaSource(void);
};

#endif
