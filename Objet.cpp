#include "Objet.hpp"

Objet::Objet(const Objet& o){
	*this = o;
}

Objet& Objet::operator=(const Objet& o){
	_objet = o._objet;
	_width = o._width;
	_height = o._height;
	_vx = o._vx;
	_vy = o._vy;
	_life = o._life;
	_visible = o._visible;

	return *this;
}

/** accesseur const */ 
const int& Objet::getId() const {return _id;}
const int& Objet::getWidth() const {return _width;}
const int& Objet::getHeight() const {return _height;}
const int& Objet::getLife() const {return _life;}
const bool& Objet::getVisible() const {return _visible;}

/** accesseur non const */
int Objet::getX()  {return _objet.x;}
int Objet::getY()  {return _objet.y;}
int Objet::get_vx() {return _vx;}
int Objet::get_vy() {return _vy;}
int Objet::getWidth(){return _width;}
int Objet::getHeight(){return _height;}
int Objet::getLife(){return _life;}
bool Objet::getVisible(){return _visible;}

/** set value **/
void Objet::setWidth(const int& w){ _width = w;}
void Objet::setHeight(const int& h){ _height = h;}
void Objet::setLife(const int& l){_life=l;}
void Objet::setVisible(){_visible=true;}
void Objet::setUnvisible(){_visible=false;}
void Objet::set_x(const int& x){_objet.x=x;}
void Objet::set_y(const int& y){_objet.y=y;}
void Objet::set_vx(const int& vx){_vx=vx;}
void Objet::set_vy(const int& vy){_vy=vy;}



bool Objet::check_collision(const Objet &A, const Objet &B) 
{
	//all sides of the rectangle
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//calculate all the sides of A
	leftA = A._objet.x;
	rightA = A._objet.x + A._width;
	topA = A._objet.y;
	bottomA = A._objet.y + A._height;

	//calculate all the sides of B
	leftB = B._objet.x;
	rightB = B._objet.x + B._width;
	topB = B._objet.y;
	bottomB = B._objet.y + B._height;

	if( bottomA <= topB )
	{
		return false;
	}
	if( topA >= bottomB )
	{
		return false;
	}
	if( rightA <= leftB )
	{
		return false;
	}
	if( leftA >= rightB )
	{
		return false;
	}
	//there is a collision
	return true;
}
	
