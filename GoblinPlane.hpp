#ifndef GoblinPlane_HPP_
#define GoblinPlane_HPP_



#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "EnemyPlane.hpp"


const int GoblinPlane_Width = 38;
const int GoblinPlane_Height = 28;
const int GoblinPlane_Maxlife = 1;

class GoblinPlane : public EnemyPlane
{
	public:
		/** constructeur par defaut */
		GoblinPlane();
		GoblinPlane(int id);
		
		/** mouvement */
		void Move();


		/** destructeur */
		~GoblinPlane(){}
};
#endif
