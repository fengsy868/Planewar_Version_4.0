#include "SuperPlane.hpp"


SuperPlane::SuperPlane(int id):EnemyPlane(id,SuperPlane_Width,SuperPlane_Height,3,SuperPlane_Maxlife)
{

	//initialiser une position aléatoire pour chaque SuperPlane 
	_objet.x = rand()%208;
	_objet.y = 0;

	//set the velocity of plane
	_vx = 0;
	_vy = 1;

	//std::cout << _vy << std::endl;
	
	//set start life
	_life = SuperPlane_Maxlife;

	setUnvisible();

}




/** se deplacer */
void SuperPlane::Move()
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
		_objet.y = 0;
		_objet.x = rand()%208;
		setVisible();
		_life = _maxlife; 
	}
}

