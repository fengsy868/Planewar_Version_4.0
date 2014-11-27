#ifndef SuperPlane_HPP_
#define SuperPlane_HPP_

#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "EnemyPlane.hpp"

const int SuperPlane_Width = 112;
const int SuperPlane_Height = 172;
const int SuperPlane_Maxlife = 20;


class SuperPlane : public EnemyPlane
{
	public:
		/** constructeur par defaut */
		SuperPlane();
		SuperPlane(int id);

		/** mouvement */
		void Move();


		/** destructeur */
		~SuperPlane(){}
};
#endif
