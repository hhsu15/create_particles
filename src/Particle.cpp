/*
 * Particle.cpp
 *
 *  Created on: Apr 6, 2019
 *      Author: hsin
 */

#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace caveofprograming {

Particle::Particle() :
		m_x(0), m_y(0) { // start from 0
	init();
}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	// this will give you the radious direction
	m_direction = (2 * M_PI * rand()) / RAND_MAX;

	// define the speed
	// the smaller the slower
	m_speed = (0.05 * rand()) / RAND_MAX;
	m_speed *= m_speed;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval) {
	// this can control the direction
	// the bigger the currlier
	m_direction += interval * 0.0001;
	// not sure how the math works...
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	// this is where we move the particles
	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}

	if(rand() < RAND_MAX/100){
		init();
	}
}

} /* namespace caveofprograming */
