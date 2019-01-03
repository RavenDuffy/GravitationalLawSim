#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameRun.h"
#include "particle.h"
 
sf::RenderWindow window;
std::vector<particle> pList;

int wWidth;
int wHeight;

// BLANK CONSTRUCTOR
GameRun::GameRun() {
	window.create(sf::VideoMode(800, 600), "Particle Sim");

	wWidth = window.getSize().x;
	wHeight = window.getSize().y;

	fillPList(100);

	startGame();
}

// FILL THE LIST OF PARTICLES WITH RANDOM PARTICLES
void GameRun::fillPList(int pNum) {
	for (auto p = 0; p < pNum; p++) {
		particle part(rand() % wWidth, rand() % wHeight);
		pList.push_back(part);
	}
}

// FULL GAME UPDATES
#pragma region GameUpdates

void GameRun::update() {
	updateParticles();
}

void GameRun::draw() {
	drawParticles();
}

#pragma endregion


// PARTICLE UPDATES
#pragma region ParticleUpdates

void GameRun::updateParticles() {
	for (int p = 0; p < pList.size(); p++) {
		for (int o = 0; o < pList.size(); o++)
			pList.at(p).moveGravity(pList.at(o));
	}
}

void GameRun::drawParticles() {
	for (particle p : pList) {
		window.draw(p);
	}
}

#pragma endregion


// START THE GAME LOOP
#pragma region GameLoop

void GameRun::startGame() {
	GameRun::gameLoop();
}

// HOLDS GAME LOOP
void GameRun::gameLoop() {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		// PARTICLE RENDERING HERE
		update();
		draw();

		window.display();
		window.setFramerateLimit(60);
	}
}

#pragma endregion