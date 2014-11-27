#ifndef MENU_HPP_
#define MENU_HPP_
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"
#include <iostream>


class Menu {
	public:
		/** constructeur par defaut */
        Menu(int id):_id(id){std::cout << "PlaneWars start!!!"<<std::endl;}

		/** deplacement */
		int menu_debut() ;
		int menu_fin();
	//	int instructions();
		/** destructeur */
		~Menu(){};
	private:
		int _id;
};

#endif
