#include "Music.hpp"

Music::Music(int id): _id(id){}


Music::Music(const Music& o){
    *this = o;
}

Music& Music::operator=(const Music& o){
    music = o.music;

    //The sound effects that will be copied
    bullet_sound = o.bullet_sound;
    enemy1_down = o.enemy1_down;
    enemy2_down = o.enemy2_down;
    enemy3_down = o.enemy3_down;
    enemy4_down = o.enemy4_down;
    enemy5_down = o.enemy5_down;
    game_over =  o.game_over;
    return *this;
}


void Music::init()
{
	//Initialize SDL_mixer
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );


    //Load the music
    music = Mix_LoadMUS( "Resources/game_music.wav" );

    //Load the sound effects
    bullet_sound = Mix_LoadWAV( "Resources/Yu_gameover.wav" );
    enemy1_down = Mix_LoadWAV( "Resources/enemy1_down.wav" );
    enemy2_down = Mix_LoadWAV( "Resources/enemy3_down.wav" );
    enemy3_down = Mix_LoadWAV( "Resources/enemy2_down.wav");
    enemy4_down = Mix_LoadWAV( "Resources/enemy4_down.wav");
    enemy5_down = Mix_LoadWAV( "Resources/enemy5_down.wav");
    game_over   = Mix_LoadWAV( "Resources/game_over.wav");
}

void Music::play_music()
{
	Mix_PlayMusic( music, -1 );
}
void Music::play_enemy1()
{
	Mix_PlayChannel( -1, enemy1_down, 0 );
}
void Music::play_enemy2()
{
	Mix_PlayChannel( -1, enemy2_down, 0 );
}
void Music::play_enemy3()
{
	Mix_PlayChannel( -1, enemy3_down, 0 );
}
void Music::play_gameover()
{
    Mix_PlayChannel( -1, game_over, 0 );
}
void Music::play_bullet()
{
	Mix_PlayChannel( -1, bullet_sound, 0 );
}

void Music::clean_up()
{
	//Free the sound effects
    Mix_FreeChunk( bullet_sound );
    Mix_FreeChunk( enemy1_down );
    Mix_FreeChunk( enemy2_down );
    Mix_FreeChunk( enemy3_down );
    Mix_FreeChunk( enemy4_down );
    Mix_FreeChunk( enemy5_down );
    Mix_FreeChunk( game_over );

    //Free the music
    Mix_FreeMusic( music );

    //Quit SDL_mixer
    Mix_CloseAudio();
}