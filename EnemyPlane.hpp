#ifndef EnemyPlane_HPP_
#define EnemyPlane_HPP_


#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>

#include "Objet.hpp"
#include "Plane.hpp"



class EnemyPlane : public Plane{
	public:

		//constructeur par defaut 
		EnemyPlane(){}

		EnemyPlane(int id,int width,int height,int type, int maxlife);


		//const int& get() const;

		int getType();
		const int& get_Point_Die_X() const;
		const int& get_Point_Die_Y() const;
		const int& get_Frame_Die() const;


		void set_Point_Die_X(const int& x);
		void set_Point_Die_Y(const int& y);
		void set_Frame_Die(const int& f);
		

		void Move();

		// destructeur 
		~EnemyPlane(){}

	protected:
		int _type;
		int _maxlife;
		int _Point_Die_X, _Point_Die_Y, _Frame_Die;

};

#endif
