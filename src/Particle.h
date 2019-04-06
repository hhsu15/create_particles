/*
 * Particle.h
 *
 *  Created on: Apr 6, 2019
 *      Author: hsin
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace caveofprograming {

// struct is pretty much same as class but
// struct by default you have declared variables as public if not specified
struct Particle {
	double m_x;
	double m_y;

public:
	Particle();
	virtual ~Particle();
};

} /* namespace caveofprograming */

#endif /* PARTICLE_H_ */
