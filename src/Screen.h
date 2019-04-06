/*
 * Screen.h
 *
 *  Created on: Mar 31, 2019
 *      Author: hsin
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace caveofprograming {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HIGHT = 600;

private:
	// refer to the documentation
	// convention is to use m_ to show it's a member variable (instance variable) rather than local variable
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
};

} /* namespace caveofprograming */

#endif /* SCREEN_H_ */
