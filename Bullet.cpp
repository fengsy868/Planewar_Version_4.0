#include "Bullet.hpp"


Bullet::Bullet(int id):Objet(Bullet_Width,Bullet_Height,id,Bullet_Maxlife)
{

	_visible = false;

	_objet.x = 0;
	_objet.y = 0;
	_vx = 0;
	_vy = 0;

}

void Bullet::Move()
{

	/** deplacement horizontal */
	_objet.x += _vx; 

	/** retourner si frapper le mur*/
	if((_objet.x<0 ) || (_objet.x + Bullet_Width > 320 ))
	{
		_objet.x -= _vx; 
	}

	/** deplacement vertical */
	_objet.y += _vy;

	/** retourner si toucher les limites en haut et en bas */	
	if(_objet.y<0) 
	{
		 set_y(-15);
		//_objet.
		_visible = false;
	}

	if( _objet.y > 568  )
	{
		set_y(0);
		_visible = false;
	}
}


