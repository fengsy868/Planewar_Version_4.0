#ifndef Objet_HPP
#define Objet_HPP

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>

class Objet{
	public:

		/** constructeur par defaut */
		Objet();

		/** constructeur avec parametres */
		Objet(int width, int height, int id, int life): _life(life), _id(id), _visible(true){
			_width = width;
			_height = height;
			_objet.x = 0;
			_objet.y = 0;
		}

		/** constructeur de copie */
		Objet(const Objet& o);
		/** operator = */
		Objet& operator=(const Objet& o);
		

		/** accesseur const */
		const int& getId() const;
		const int& getWidth() const;
		const int& getHeight() const;
		const int& getLife() const;
		const bool& getVisible() const;


		/** accesseur non const */
		int getX() ;
		int getY() ;
		int get_vx();
		int get_vy();
		int getWidth();
		int getHeight();
		int getLife();
		bool getVisible();

		/** set value */
		void setWidth(const int& w);
		void setHeight(const int& h);
		void setLife(const int& l);
		void set_x(const int& x);
		void set_y(const int& y);
		void set_vx(const int& vx);
		void set_vy(const int& vy);
		void setVisible();
		void setUnvisible();

		virtual void Move(){}

		bool check_collision( const Objet &A, const Objet &B);

		/** destructeur */
		~Objet(){}

	protected:
	
		SDL_Rect _objet;

		int _id;

		int _width, _height;
		// velocity on x and y
		int _vx, _vy;

		int _life;

		bool _visible;

};

#endif
