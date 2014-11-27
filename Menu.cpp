#include "Menu.hpp"


int Menu :: menu_debut()//fonction qui return 1 si le joueur veut jouer et 0 si le joueur veut des instruction
{
	int continuer = 1 ;int veri ;
	SDL_Rect position_menu, position_cur,hazar;
	SDL_Surface *menu =  NULL , *cursor = NULL,*ecran= NULL;
	SDL_Event event ;

	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(320, 568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  menu = IMG_Load("Resources/background_begin .png");
	cursor = IMG_Load("Resources/point.png");
	position_menu.x = 0 ;
	position_menu.y = 0 ;
	position_cur.x = 80;
	position_cur.y = 204;
	hazar.x = 84 ;
	hazar.y = 310 ;


  while (continuer)
	{
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                      continuer = 0;
                      return 2;
                      break;
		        case SDL_KEYDOWN:
		                switch (event.key.keysym.sym)
                    {
                      case SDLK_DOWN: /* Appui sur la touche Echap, on arrête le programme */
                    	      position_cur.x = 50 ;
                    	      position_cur.y = 360 ;
                            break;
                      case SDLK_UP: /* Appui sur la touche Echap, on arrête le programme */
                    	     position_cur.x = 80 ;
                    	     position_cur.y = 204 ;
                           break;
                      case SDLK_RETURN :
                           if(position_cur.y == 204)//pour commencer le jeu
                           {
                            veri = 1;
                            continuer = 0;
                           }
                           if(position_cur.y == 360)//pour afficher les instruction
                           { 
                            veri = 0 ;
                            continuer = 0;
                           }
                   }
            break;
        }
	     

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(menu, NULL, ecran, &position_menu);
        SDL_BlitSurface(cursor, NULL, ecran, &position_cur);
        SDL_Flip(ecran);
	}
  SDL_FreeSurface(menu);
  SDL_FreeSurface(cursor);
  SDL_FreeSurface(ecran);
  SDL_Quit();

  return veri ;
}
/*
int Menu::instructions()
{

}
*/
int Menu :: menu_fin()//fonction retourne 0 si le joueur veut quitter le jeux et 1 s'il veut rejouer
{
  int continuer = 1 ;
  int veri;
	SDL_Rect position_menu, position_cur,hazar;
	SDL_Surface *menu =  NULL , *cursor = NULL,*ecran= NULL;
	SDL_Event event ;
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(320, 568, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  menu = IMG_Load("Resources/background_qui .png");
	cursor = IMG_Load("Resources/point.png");
	position_menu.x = 0 ;
	position_menu.y = 0 ;
	position_cur.x = 90;
	position_cur.y = 175 ;
  while (continuer)
	{
        SDL_WaitEvent(&event);
        switch(event.type)
        {
                case SDL_QUIT:
                     continuer = 0;
                     return 2;
                     break;
		            case SDL_KEYDOWN:
		            switch (event.key.keysym.sym)
                {
                    case SDLK_DOWN: /* Appui sur la touche Echap, on arrête le programme */
                    	position_cur.x = 90 ;
                    	position_cur.y = 385 ;
                      break;
                    case SDLK_UP: /* Appui sur la touche Echap, on arrête le programme */
                    	position_cur.x = 90;
                    	position_cur.y = 175;
                     break;
                    case SDLK_RETURN :
                      if(position_cur.y == 175)//pour quitter le jeu
                      {     veri = 0;continuer = 0;}
                      if(position_cur.y == 385)//pour rejouer
                      {     veri = 1 ;continuer = 0;}
                }
                break;
        }
	      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(menu, NULL, ecran, &position_menu);
        SDL_BlitSurface(cursor, NULL, ecran, &position_cur);
        SDL_Flip(ecran);
 	}
  SDL_FreeSurface(menu);
  SDL_FreeSurface(cursor);
  SDL_FreeSurface(ecran);
  SDL_Quit();
  return veri ;
}

/*
int main(){
  Menu menu;

  menu.menu_fin();
}
*/