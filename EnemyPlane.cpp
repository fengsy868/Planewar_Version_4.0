#include "EnemyPlane.hpp"

EnemyPlane::EnemyPlane(int id, int width, int height, int type, int maxlife): Plane(id,width,height),_type(type), _maxlife(maxlife)
{}

int EnemyPlane::getType() {return _type;}

const int& EnemyPlane::get_Point_Die_X() const {return _Point_Die_X;}
const int& EnemyPlane::get_Point_Die_Y() const {return _Point_Die_Y;}
const int& EnemyPlane::get_Frame_Die() const {return _Frame_Die;}

void EnemyPlane::set_Point_Die_X(const int& x){_Point_Die_X = x;}
void EnemyPlane::set_Point_Die_Y(const int& y){_Point_Die_Y = y;}
void EnemyPlane::set_Frame_Die(const int& f){_Frame_Die = f;}

void EnemyPlane::Move()
{
	//The enemy go left or right
    _objet.x += _vx;

    //If the plane went too far to the left or right
    if( ( _objet.x < 0 ) || ( _objet.x + _width > 320 ) )
    {
        //move back
        _objet.x -= _vx;
    }

       //Move the Hero up or down
    _objet.y += _vy;

    //If the Hero went too far up or down
    if( ( _objet.y < -(_height) ) || ( _objet.y + _height > 568 ) )
    {
        //move back
        _objet.y = -(_height);
        switch(_type)
		{
			case 1: _objet.x = rand()%282; break;
			case 2: _objet.x = rand()%274; break;
			case 3: _objet.x = rand()%208; break;
			default: break;
		}

		switch(_type)
		{
			case 1: set_vy(3 + (rand()%5)); break;
			case 2: set_vy(2 + (rand()%3)); break;
			case 3: set_vy(1); break;
			default: break;
		}

		setVisible();
		_life = _maxlife;
    }



}


