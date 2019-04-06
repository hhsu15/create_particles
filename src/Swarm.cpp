/*
 * Swarm.cpp
 *
 *  Created on: Apr 6, 2019
 *      Author: hsin
 */

#include "Swarm.h"

namespace caveofprograming {

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

} /* namespace caveofprograming */
