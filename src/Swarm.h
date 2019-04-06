/*
 * Swarm.h
 *
 *  Created on: Apr 6, 2019
 *      Author: hsin
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace caveofprograming {

class Swarm {
public:
	const static int NPARTICLES = 5000;

private:
	Particle *m_pParticles;

public:
	Swarm();
	virtual ~Swarm();

	Particle* const getParticles(){ return m_pParticles; };
};

} /* namespace caveofprograming */

#endif /* SWARM_H_ */
