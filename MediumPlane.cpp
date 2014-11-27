#include "MediumPlane.hpp"

MediumPlane::MediumPlane(int id):EnemyPlane(id,MediumPlane_Width,MediumPlane_Height,2,MediumPlane_Maxlife)
{

	//initialiser une position aléatoire pour chaque MediumPlane 
	_objet.x = rand()%274;
	_objet.y = 0;

	//set the velocity of plane
	_vx = 0;
	_vy = 1+rand()%3;

	//std::cout << _vy << std::endl;
	
	//set start life
	_life = MediumPlane_Maxlife;

	setUnvisible();

}





/** se deplacer */
void MediumPlane::Move()
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
		_objet.x = 23 + (rand()%274);
		setVisible();
		_life = _maxlife; 
	}
}


