#ifndef Hero_HPP
#define Hero_HPP


#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
#include <vector>

#include "Objet.hpp"
#include "Plane.hpp"
#include "EnemyPlane.hpp"
#include "Music.hpp"



//The dimensions of the Hero
const int Hero_WIDTH = 68;
const int Hero_HEIGHT = 84;

const int Hero_Life = 3;

const int Hero_Bullet_Number = 10;


class Hero : public Plane{
	public:

		/* constructeur par defaut */
		Hero(int id, const Music& mymusic);


		const int& get_Frame_Count() const;
		const int& getScore() const;

		void set_Frame_Count(const int& f);

		void resetScore();
		
		void Handle_input(SDL_Event &event);
		
		void LaunchBullet();
	
		/* mouvement */
		void Move();

		void CollisionEnemy(std::vector<EnemyPlane> &ObjetList);
		void AttackEnemy(std::vector<EnemyPlane> &ObjetList);
		/* destructeur */
		~Hero(){}
		
	protected:
		Music _music;
		int _score;
		int _frame_count;
		
};

#endif