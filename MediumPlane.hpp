#ifndef MediumPlane_HPP_
#define MediumPlane_HPP_

#include "EnemyPlane.hpp"


#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

const int MediumPlane_Width = 46;
const int MediumPlane_Height = 66;

const int MediumPlane_Maxlife = 5;

class MediumPlane : public EnemyPlane
{
	public:
		// constructeur par defaut 
		MediumPlane();
		MediumPlane(int id);
		
		/** mouvement */
		void Move();


		/** destructeur */
		~MediumPlane(){}
};
#endif
