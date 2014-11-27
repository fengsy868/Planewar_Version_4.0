#ifndef Bullet_HPP
#define Bullet_HPP


#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <SDL/SDL.h>

#include "Objet.hpp"




const int Bullet_Maxlife = 10;
const int Bullet_Width = 6;
const int Bullet_Height = 14;
const int Bullet_Velocity = -30;

class Bullet : public Objet{
	public:
		/** constructeur par defaut */
		Bullet(){}

		Bullet(int id);

		/** deplacement */
		void Move();
		
		/** destructeur */
		~Bullet(){}
};

#endif
