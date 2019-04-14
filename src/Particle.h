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

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();

	void update(int interval);
};

} /* namespace caveofprograming */

#endif /* PARTICLE_H_ */
