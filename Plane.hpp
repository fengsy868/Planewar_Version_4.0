#ifndef Plane_HPP
#define Plane_HPP


#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>

#include "Objet.hpp"
#include "Bullet.hpp"


class Plane : public Objet{
	public:

		/* constructeur par defaut */
		Plane();

		Plane(int id, int width, int height);

		virtual bool collision(){return true;}		

		/* destructeur */
		~Plane(){}


	
	//protected: 
		std::vector<Bullet> _BulletList;		
	//	std::vector<Bomb> _BombList;
};

#endif
