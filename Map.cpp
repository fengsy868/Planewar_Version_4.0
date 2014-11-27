#include "Map.hpp"



Map::Map( const Hero& myhero, const Music& mymusic ):_Hero( myhero),_music(mymusic)
{

    _music.init();

    hero_fly_1.x = 768;
    hero_fly_1.y = 130;
    hero_fly_1.w = Hero_WIDTH;
    hero_fly_1.h = Hero_HEIGHT;

    bullet1.x = 2;
    bullet1.y = 2;
    bullet1.w = 6;
    bullet1.h = 14;

    enemy1_fly.x = 843;
    enemy1_fly.y = 1;
    enemy1_fly.w = 38;
    enemy1_fly.h = 28;


    enemy2_fly.x = 810;
    enemy2_fly.y = 26;
    enemy2_fly.w = 46;
    enemy2_fly.h = 66;

    enemy3_fly.x = 570;
    enemy3_fly.y = 340;
    enemy3_fly.w = 112;
    enemy3_fly.h = 172;

    enemy1_blownup[ 0 ].x = 880;//1
    enemy1_blownup[ 0 ].y = 2;
    enemy1_blownup[ 0 ].w = 35;
    enemy1_blownup[ 0 ].h = 27;

    enemy1_blownup[ 1 ].x = 701;//1
    enemy1_blownup[ 1 ].y = 93;
    enemy1_blownup[ 1 ].w = 35;
    enemy1_blownup[ 1 ].h = 27;

    enemy1_blownup[ 2 ].x = 955;//1
    enemy1_blownup[ 2 ].y = 474;
    enemy1_blownup[ 2 ].w = 34;
    enemy1_blownup[ 2 ].h = 38;

    enemy1_blownup[ 3 ].x = 738;//1
    enemy1_blownup[ 3 ].y = 92;
    enemy1_blownup[ 3 ].w = 32;
    enemy1_blownup[ 3 ].h = 30;

    enemy2_blownup[ 0 ].x = 858;//1
    enemy2_blownup[ 0 ].y = 28;
    enemy2_blownup[ 0 ].w = 46;
    enemy2_blownup[ 0 ].h = 62;

    enemy2_blownup[ 1 ].x = 374;//2
    enemy2_blownup[ 1 ].y = 840;
    enemy2_blownup[ 1 ].w = 46;
    enemy2_blownup[ 1 ].h = 62;

    enemy2_blownup[ 2 ].x = 252;//2
    enemy2_blownup[ 2 ].y = 831;
    enemy2_blownup[ 2 ].w = 46;
    enemy2_blownup[ 2 ].h = 62;

    enemy2_blownup[ 3 ].x = 903;//1
    enemy2_blownup[ 3 ].y = 84;
    enemy2_blownup[ 3 ].w = 46;
    enemy2_blownup[ 3 ].h = 62;



    enemy3_blownup[ 0 ].x = 564;//1
    enemy3_blownup[ 0 ].y = 17;
    enemy3_blownup[ 0 ].w = 110;
    enemy3_blownup[ 0 ].h = 173;

    enemy3_blownup[ 1 ].x = 451;//1
    enemy3_blownup[ 1 ].y = 17;
    enemy3_blownup[ 1 ].w = 110;
    enemy3_blownup[ 1 ].h = 173;

    enemy3_blownup[ 2 ].x = 339;//1
    enemy3_blownup[ 2 ].y = 17;
    enemy3_blownup[ 2 ].w = 110;
    enemy3_blownup[ 2 ].h = 173;

    enemy3_blownup[ 3 ].x = 226;//1
    enemy3_blownup[ 3 ].y = 17;
    enemy3_blownup[ 3 ].w = 110;
    enemy3_blownup[ 3 ].h = 173;

    enemy3_blownup[ 4 ].x = 114;//2
    enemy3_blownup[ 4 ].y = 17;
    enemy3_blownup[ 4 ].w = 110;
    enemy3_blownup[ 4 ].h = 173;

    enemy3_blownup[ 5 ].x = 1;//2
    enemy3_blownup[ 5 ].y = 17;
    enemy3_blownup[ 5 ].w = 110;
    enemy3_blownup[ 5 ].h = 173;

    enemy3_blownup[ 6 ].x = 666;//1
    enemy3_blownup[ 6 ].y = 210;
    enemy3_blownup[ 6 ].w = 100;
    enemy3_blownup[ 6 ].h = 135;

    hero_blownup[ 0 ].x = 763;//1
    hero_blownup[ 0 ].y = 260;
    hero_blownup[ 0 ].w = 68;
    hero_blownup[ 0 ].h = 84;

    hero_blownup[ 1 ].x = 741;//1
    hero_blownup[ 1 ].y = 6;
    hero_blownup[ 1 ].w = 68;
    hero_blownup[ 1 ].h = 84;

    hero_blownup[ 2 ].x = 699;//1
    hero_blownup[ 2 ].y = 125;
    hero_blownup[ 2 ].w = 68;
    hero_blownup[ 2 ].h = 84;

    hero_blownup[ 3 ].x = 904;//1
    hero_blownup[ 3 ].y = 92;
    hero_blownup[ 3 ].w = 48;
    hero_blownup[ 3 ].h = 58;

    //Initialize the offset of background
    _bgX = 0; 
    _bgY =-(1136-568);

    //create the enemies
    for(size_t i = 0; i < GoblinPlane_Number; ++i)
    {
        _EnemyList.push_back(GoblinPlane(i));
    }
    for(size_t i = 0; i < MediumPlane_Number; ++i)
    {
        _EnemyList.push_back(MediumPlane(i));
    }
    for(size_t i = 0; i < SuperPlane_Number; ++i)
    {
        _EnemyList.push_back(SuperPlane(i));
    }

}



void Map::setPlayerVisible()
{

	_Hero.setVisible();
	
}

void Map::setPlayerInvisible()
{
	_Hero.setUnvisible();
}

void Map::Handle_input(SDL_Event &event)
{
	_Hero.Handle_input(event);

}


SDL_Surface* Map::load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormatAlpha( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

    }

    //Return the optimized surface
    return optimizedImage;
}


void Map::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool Map::init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }


    //Set the window caption
    SDL_WM_SetCaption( "Plane Wars BY Feng", NULL );

    //If everything initialized fine
    return true;
}

bool Map::load_files()
{
    //Load the Hero image
    sprites = load_image( "Resources/sprites.png" );
    sprites2 = load_image( "Resources/sprites2.png" );
    background = load_image( "Resources/background_new.png");

    //If there was a problem in loading the sprites
    if( sprites == NULL || sprites2 == NULL || background == NULL)
    {
        return false;
    }


    

    //If everything loaded fine
    return true;
}


void Map::move()
{
    for(std::vector<EnemyPlane>::size_type i = 0; i < _EnemyList.size(); ++i)
    {
        _EnemyList[i].Move();
    }



    if (_Hero.getVisible())
    {
        _Hero.Move();
        for (std::vector<Bullet>::size_type i = 0; i < _Hero._BulletList.size(); ++i)
        {    
            _Hero._BulletList[i].Move();

        }    
    }
}


void Map::collision()
{
    if (_Hero.getVisible())
    {

        _Hero.CollisionEnemy(_EnemyList);
        _Hero.AttackEnemy(_EnemyList);
    }   
    
}


void Map::PrintHero()
{



	if (_Hero.getVisible())
	{
        
        for (std::vector<Bullet>::size_type i = 0; i < _Hero._BulletList.size(); ++i)
        {
            if(_Hero._BulletList[i].getVisible())
            apply_surface(_Hero._BulletList[i].getX(),_Hero._BulletList[i].getY(),sprites,screen,&bullet1);
        }

        apply_surface(_Hero.getX(),_Hero.getY(),sprites,screen,&hero_fly_1);
	}

    else {
        switch (_Hero.get_Frame_Count())
        {
            case 1 : apply_surface( _Hero.getX(), _Hero.getY(), sprites, screen, &hero_blownup[ 0 ] );break;
            case 2 : apply_surface( _Hero.getX(), _Hero.getY(), sprites, screen, &hero_blownup[ 1 ] );break;
            case 3 : apply_surface( _Hero.getX(), _Hero.getY(), sprites, screen, &hero_blownup[ 2 ] );break;
            case 4 : apply_surface( _Hero.getX(), _Hero.getY(), sprites, screen, &hero_blownup[ 3 ] );break;
            default : break;
        }
        _Hero.set_Frame_Count(_Hero.get_Frame_Count() + 1 );
        if (_Hero.get_Frame_Count() >= 4 || _Hero.get_Frame_Count() == 1)
            _Hero.set_Frame_Count(0);

    }

}

void Map::PrintEnemyPlane()
{
    for(std::vector<EnemyPlane>::size_type i = 0; i < _EnemyList.size(); ++i)
    {
        if (_EnemyList[i].getVisible())
        {
          //  std::cout << "case:" << i << "   Type:"<< _EnemyList[i].getType() << std::endl;
            switch(_EnemyList[i].getType())
            {
                case 1:

                 //   std::cout << i << ":"<<_EnemyList[i].getX() << "  "<< _EnemyList[i].getY()<< std::endl;
                    
                    apply_surface(_EnemyList[i].getX(),_EnemyList[i].getY(),sprites,screen,&enemy1_fly);break;
                case 2:
                    //std::cout << "case2:" << i << std::endl;
                
                    apply_surface(_EnemyList[i].getX(),_EnemyList[i].getY(),sprites,screen,&enemy2_fly);break;

                case 3:

                    apply_surface(_EnemyList[i].getX(),_EnemyList[i].getY(),sprites,screen,&enemy3_fly);break;
              
                    

                default: break;
            }
            
        }
        
        else if ( true )
        {
            switch(_EnemyList[i].getType())
            {
                case 1:
                    switch (_EnemyList[i].get_Frame_Die())
                    {
                        case 1 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy1_blownup[ 0 ] );_music.play_enemy1();break;
                        case 2 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy1_blownup[ 1 ] );break;
                        case 3 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy1_blownup[ 2 ] );break;
                        case 4 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy1_blownup[ 3 ] );break;
                        default : break;
                    }
                    break;
                case 2:
                    switch (_EnemyList[i].get_Frame_Die())
                    {
                        case 1 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy2_blownup[ 0 ] );_music.play_enemy2();break;
                        case 2 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites2, screen, &enemy2_blownup[ 1 ] );break;
                        case 3 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites2, screen, &enemy2_blownup[ 2 ] );break;
                        case 4 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy2_blownup[ 3 ] );break;
                        default :  break;
                    }
                    break;

                case 3:
                    switch (_EnemyList[i].get_Frame_Die())
                    {
                        case 1 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy3_blownup[ 0 ] );_music.play_enemy3();break;
                        case 2 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy3_blownup[ 1 ] );break;
                        case 3 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy3_blownup[ 2 ] );break;
                        case 4 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy3_blownup[ 3 ] );break;
                        case 5 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy3_blownup[ 4 ] );break;
                        case 6 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy3_blownup[ 5 ] );break;
                        case 7 : apply_surface( _EnemyList[i].get_Point_Die_X(), _EnemyList[i].get_Point_Die_Y(), sprites, screen, &enemy3_blownup[ 6 ] );break;
                        default :  break;
                    }
                    break;

                default : break;
            }        

            if(_EnemyList[i].getType() == 1 || _EnemyList[i].getType() == 2)
            {
                _EnemyList[i].set_Frame_Die(_EnemyList[i].get_Frame_Die() + 1 );
                if (_EnemyList[i].get_Frame_Die() >= 4 || _EnemyList[i].get_Frame_Die() == 1)
                    _EnemyList[i].set_Frame_Die(0);
            }       

            if(_EnemyList[i].getType() == 3)
            {
                _EnemyList[i].set_Frame_Die(_EnemyList[i].get_Frame_Die() + 1 );
                if (_EnemyList[i].get_Frame_Die() >= 7 || _EnemyList[i].get_Frame_Die() == 1)
                    _EnemyList[i].set_Frame_Die(0);
            }   
        }
    }
}
    
void Map::PrintBackground()
{
	
    //Scroll background
    _bgY += 1;

    //If the background has gone tmyhero far
    if( _bgY == 0 )
 	{
     	//Reset the offset
        _bgY = -(1136-568);
    }

    //Show the background
    apply_surface( _bgX, _bgY, background, screen, NULL);
   // apply_surface( _bgX , _bgY + background->w, background, screen, NULL );



}

void Map::Print()
{
	
	PrintBackground();
    PrintEnemyPlane();
	PrintHero();	

	SDL_Flip( screen );
    
}


void Map::clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( sprites );
    SDL_FreeSurface( sprites2 );

    
    
    SDL_Quit();// quitter SDL */
}