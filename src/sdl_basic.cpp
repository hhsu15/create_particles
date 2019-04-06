//============================================================================
// Name        : sdl_basic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace caveofprograming;

int main() {
	// from stdlib.h
	srand(time(NULL));

	Screen screen;
	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}

	Swarm swarm;

	// Game loop
	while (true) {

		int elasped = SDL_GetTicks();

		// a bit security
		// if green becomes greater than 255
		// unsigned char can only store 255 (1 byte)
		// it will assign a junk color
		// (ussigned char) is a cast
		unsigned char green =
				(unsigned char) ((1 + sin(elasped * 0.0001)) * 128);
		unsigned char red = (unsigned char) ((1 + sin(elasped * 0.0002)) * 128);
		unsigned char blue = (unsigned char) ((1 + cos(elasped * 0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		// draw the screen
		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	};

	screen.close();

	return 0;
}
