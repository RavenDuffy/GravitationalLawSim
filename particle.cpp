#include <SFML/Graphics.hpp>
#include <iostream>

#include "particle.h"
#include "GameRun.h"

float mass;

particle::particle(int xpos, int ypos) : sf::CircleShape(MAX_RADIUS) {
	setRadius(rand() % (int) MAX_RADIUS);
	setFillColor(sf::Color::White);
	setPosition(xpos, ypos);

	// will change how quickly the simulation runs
	//mass = getRadius() * (3.8555555 * pow(10, 4.5));
	mass = pow(3.8555555, getRadius());
}

void particle::moveGravity(particle other) {
	// calculate distance between objects
	float distanceX, distanceY, distance;
	distanceX = (getPosition().x - other.getPosition().x);
	distanceY = (getPosition().y - other.getPosition().y);
	
	distance = sqrt((pow(distanceX, 2)) + (pow(distanceY, 2)));

	// calc gravity
	float gravity = (G * mass * other.getMass()) / pow(distance, 2);

	if (std::isinf(gravity))
		gravity = 0;

	// calc force
	sf::Vector2f force = getPosition() - other.getPosition();

	// normalise
	float forceMag = sqrt(pow(other.getPosition().x - getPosition().x, 2) + pow(other.getPosition().y - getPosition().y, 2));
	if (forceMag > 0) {
		force.x /= forceMag;
		force.y /= forceMag;
	}

	// scale by gravity
	force.x *= gravity;
	force.y *= gravity;
	//std::cout << force.x << "   " << force.y << std::endl;

	force *= -1.f;

	// move
	//if (force.x > 1 || force.y > 1)
	//	std::cout << forceMag << "\t" << gravity << std::endl;
	if (!collide(other, distance)) {
		move(force.x, force.y);
		other.move(-force.x, -force.y);
	}
}

bool particle::collide(particle other, float distance) {
	if (distance < getRadius() * 4 || distance < other.getRadius() * 4)
		return true;
	return false;
}

float particle::getMass() {
	return mass;
}