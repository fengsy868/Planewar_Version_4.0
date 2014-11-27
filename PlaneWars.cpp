#include <stdlib.h>
#include <iostream>


#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

#include "Map.hpp"
#include "Timer.hpp"
#include "Hero.hpp"
#include "Bullet.hpp"
#include "EnemyPlane.hpp"
#include "Music.hpp"
#include "Menu.hpp"

//The event structure
SDL_Event event;

bool game = false; 
bool debut = true;
bool finish = false; 
bool quit = false;


int main( int argc, char* args[] )
{

    Menu mymenu(2);

    Music mymusic(1);
    mymusic.init();
    mymusic.play_music();

    Hero myhero(22,mymusic);

    //The Hero that will be used
    Map mymap(myhero,mymusic);

    //The frame rate regulator
    Timer fps;

    //Initialize
    if( mymap.init() == false )
    {
        return 1;
    }

    //Load the files
    if( mymap.load_files() == false )
    {
        return 1;
    }


    //While the user hasn't quit
    while( quit == false )
    {
        while(debut = true)
        {   
            if( mymenu.menu_debut() == 1 )
            {
                debut = false;
                game = true;

            }

            else if( mymenu.menu_debut() == 2 )
            {
                debut = false;
                quit = true;
            }
            std::cout<<"gamestart?   "<<debut<<std::endl;
        }

        std::cout<<"gamestart????"<<game<<std::endl;

        while(game = true){
            //Start the frame timer
            fps.start();

            //While there's events to handle
            while( SDL_PollEvent( &event ) )
            {
                //Handle events for the Hero
                mymap.Handle_input(event);

                //If the user has Xed out the window
                if( event.type == SDL_QUIT )
                {
                    //Quit the program
                    quit = true;
                }
            }

            mymap.move();

            mymap.collision();
            //Show the background
            mymap.Print();

            //Cap the frame rate
            if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }
    
        }

        while( finish = true )
        {
            if( mymenu.menu_fin() == 1 )
            {
                game = false;
                debut = true;
            }

            if( mymenu.menu_fin() == 0)
            {
                finish = false;
                quit = true;
            }
        }


    }

    //Clean up
    mymap.clean_up();

    return 0;
}
