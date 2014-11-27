#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <stdlib.h>
#include <iostream>
#include <vector>

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

class Music
{
	public:

	Music(int id);


	/** constructeur de copie */
	Music(const Music& o);
		
	/** operator = */
	Music& operator=(const Music& o);
		
	void init();

	void play_music();
	void play_enemy1();
	void play_enemy2();
	void play_enemy3();
	void play_bullet();
	void play_gameover();

	void clean_up();

	private:

	int _id;

	//The music that will be played
	Mix_Music *music = NULL;

	//The sound effects that will be used
	Mix_Chunk *bullet_sound = NULL;
	Mix_Chunk *enemy1_down = NULL;
	Mix_Chunk *enemy2_down = NULL;
	Mix_Chunk *enemy3_down = NULL;
	Mix_Chunk *enemy4_down = NULL;
	Mix_Chunk *enemy5_down = NULL;
	Mix_Chunk *game_over = NULL;

};

#endif