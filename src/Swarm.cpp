/*
 * Swarm.cpp
 *
 *  Created on: Apr 6, 2019
 *      Author: hsin
 */

#include "Swarm.h"

namespace caveofprograming {

Swarm::Swarm(): lastTime(0) {
	// instantiate defined number of particles
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update(int elapsed){
	// update all particles
	// object particle has update method
	int interval = elapsed - lastTime;
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}

	lastTime = elapsed;

}

} /* namespace caveofprograming */
