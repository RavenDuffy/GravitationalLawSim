#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#ifndef PARTICLE_H
#define PARTICLE_H

class particle : public sf::CircleShape {
	public:
		particle(int xpos, int ypos);
		void moveGravity(particle other);
		bool collide(particle other, float distance);
	protected:

	private:
		float getMass();
};

const float MAX_RADIUS = 10.f;
const float G = 6.67408 * pow(10, -11); // NEEDS TO BE CHANGED

#endif // !PARTICLE_H