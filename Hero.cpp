#include "Hero.hpp"


Hero::Hero(int id, const Music& mymusic): Plane(id,Hero_WIDTH,Hero_HEIGHT), _music(mymusic)
{
    //Initialize the offsets
    _objet.x = 320/2;
    _objet.y = 568-Hero_HEIGHT;

    //Initialize the velocity
    _vx = 0;
    _vy = 0;

    //Initialize the visible
    _visible = true;

    //Initialize the player score
    _score = 0;

    //Initialize the life
    _life = Hero_Life;

    //Initialize the frame count to 1
    _frame_count = 1;

    //Loading the bullet

    for(size_t i = 0; i<Hero_Bullet_Number; ++i)
    {
        _BulletList.push_back(Bullet(i));
    }

}

const int& Hero::get_Frame_Count() const {return _frame_count;}
const int& Hero::getScore() const {return _score;}

void Hero::set_Frame_Count(const int& f){_frame_count = f;}

void Hero::resetScore() { _score = 0;}

void Hero::Handle_input(SDL_Event &event)
{

    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: _vy -= Hero_HEIGHT / 10; break;
            case SDLK_DOWN: _vy += Hero_HEIGHT / 10; break;
            case SDLK_LEFT: _vx -= Hero_WIDTH / 10; break;
            case SDLK_RIGHT: _vx += Hero_WIDTH / 10; break;
            case SDLK_s: LaunchBullet();
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: _vy += Hero_HEIGHT / 10; break;
            case SDLK_DOWN: _vy -= Hero_HEIGHT / 10; break;
            case SDLK_LEFT: _vx += Hero_WIDTH / 10; break;
            case SDLK_RIGHT: _vx -= Hero_WIDTH / 10; break;
        }
    }
}

void Hero::LaunchBullet()
{   
    bool standby = true;
    for(std::vector<Bullet>::size_type i = 0; (i < _BulletList.size()) && standby; ++i) 
    {
        
        if (_BulletList[i].getVisible() == false )
        {
            _BulletList[i].set_x(_objet.x + 34);
            _BulletList[i].set_y(_objet.y - 20);
            _BulletList[i].set_vy(Bullet_Velocity);
            _BulletList[i].setLife(1);
            _BulletList[i].setVisible();
            _music.play_bullet();

            standby = false;
        }
    }

}



void Hero::Move()
{

if(_visible)
{
    //Move the Hero left or right
    _objet.x += _vx;

    //If the Hero went too far to the left or right
    if( ( _objet.x < 0 ) || ( _objet.x + Hero_WIDTH > 320 ) )
    {
        //move back
        _objet.x -= _vx;
    }

       //Move the Hero up or down
    _objet.y += _vy;

    //If the Hero went too far up or down
    if( ( _objet.y < 0 ) || ( _objet.y + Hero_HEIGHT > 568 ) )
    {
        //move back
        _objet.y -= _vy;
    }
}
else {_vx=0;_vy=0;}
    
}

void Hero::CollisionEnemy(std::vector<EnemyPlane> &ObjetList)
{
    for(std::vector<EnemyPlane>::size_type i = 0; i < ObjetList.size(); ++i)
    {
        if (ObjetList[i].getVisible())
        {
            if (check_collision( *this , ObjetList[i]))
            {
                _life -= 1;  
                if (_life<=0)
                    setUnvisible();
                    _music.play_gameover();
            }   
        }   
    }
}

void Hero::AttackEnemy(std::vector<EnemyPlane> &ObjetList)
{
    for(std::vector<Bullet>::size_type i = 0; i < _BulletList.size(); ++i) 
    {
        if (_BulletList[i].getVisible())
        {
            for(std::vector<EnemyPlane>::size_type j = 0; j < ObjetList.size(); ++j)
            {
                if (ObjetList[j].getVisible())
                {
                    if (check_collision( _BulletList[i] , ObjetList[j]))
                    {
                        ObjetList[j].setLife((ObjetList[j].getLife()-1));
                        if (ObjetList[j].getLife()<=0)
                            {
                                ObjetList[j].setUnvisible();
                                ObjetList[j].set_Point_Die_X(ObjetList[j].getX() );
                                ObjetList[j].set_Point_Die_Y(ObjetList[j].getY() );
                                ObjetList[j].set_Frame_Die(1);
                            }
                        _BulletList[i].setLife(0);
                        _BulletList[i].setUnvisible();   
                        _score += 5;
                    }
                }   
            }   
        }
    }
}