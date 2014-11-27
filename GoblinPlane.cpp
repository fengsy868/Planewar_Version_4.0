#include "GoblinPlane.hpp"

GoblinPlane::GoblinPlane(int id):EnemyPlane(id,GoblinPlane_Width,GoblinPlane_Height,1,GoblinPlane_Maxlife)
{

	//initialiser une position aléatoire pour chaque GoblinPlane 
	_objet.x = rand()%282;
	_objet.y = -GoblinPlane_Height;

	//set the velocity of plane
	_vx = 0;
	_vy = 3+rand()%5;

	//set the frames of die
	set_Point_Die_X(0);
	set_Point_Die_Y(0);
	set_Frame_Die(1);

	//std::cout << _vy << std::endl;
	
	//set start life
	_life = GoblinPlane_Maxlife;

	setUnvisible();

}




/** se deplacer */
void GoblinPlane::Move()
{
	_objet.x += _vx; 

	if((_objet.x<0 ) || (_objet.x + _objet.w > 320 )) 
	{
		_objet.x -= _vx; 
	}

	_objet.y += _vy; 
	
	if(_objet.y<0)  
	{
		_objet.y -= _vy;
	}

	if((_objet.y<0) || ( _objet.y > 568 ) ) 
	{

		_objet.y = -GoblinPlane_Height;
		_objet.x = rand()%282;
		setVisible();
		_life = _maxlife; 
	}
}

