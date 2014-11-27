#ifndef Map_HPP
#define Map_HPP


#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"



#include "Bullet.hpp"
#include "Hero.hpp"
#include "EnemyPlane.hpp"
#include "GoblinPlane.hpp"
#include "MediumPlane.hpp"
#include "SuperPlane.hpp"
#include "Music.hpp"

//The screen attributes
const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 568;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 30;

//declare the number of enemy
const int GoblinPlane_Number = 5;
const int MediumPlane_Number = 2;
const int SuperPlane_Number = 1;

//declare the blow up frames number
const int GoblinPlane_Blownup_Number = 4;
const int MediumPlane_Blownup_Number = 4;
const int SuperPlane_Blownup_Number = 7;


class Map{
    
	public:
		/** constructeur par defaut */
		Map( const Hero& myhero, const Music& mymusic);

	//	Hero get_Hero(){return _Hero;}

		void setPlayerVisible();
		void setPlayerInvisible();
		void Handle_input(SDL_Event &event);


		void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip );

		SDL_Surface *load_image( std::string filename );

		bool init();

		bool load_files();

		void move();
		void collision();
		void PrintEnemyPlane();
		void PrintBackground();
		void PrintHero();	
		void Print();
		void clean_up();

		/** destructeur */
		~Map(){}

	private:

		std::vector<EnemyPlane> _EnemyList;


		Hero _Hero;
		Music _music;

		//The offsets of the background
    	int _bgX, _bgY;

		//about to clip_hero
		SDL_Rect hero_fly_1;
		SDL_Rect bullet1;
		SDL_Rect enemy1_fly;
		SDL_Rect enemy2_fly;
		SDL_Rect enemy3_fly;
		
		SDL_Rect enemy1_blownup[4];
		SDL_Rect enemy2_blownup[4];
		SDL_Rect enemy3_blownup[7];
		SDL_Rect hero_blownup[4];


		//The surfaces
		SDL_Surface *sprites = NULL;
		SDL_Surface *sprites2 = NULL;
		SDL_Surface *background = NULL;
		SDL_Surface *screen = NULL;

};

#endif
