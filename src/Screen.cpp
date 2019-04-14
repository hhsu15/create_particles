/*
 * Screen.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: hsin
 */

#include "Screen.h"

namespace caveofprograming {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {

}

bool Screen::init() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	// refer to the documentation
	m_window = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// check if window is created correctly
	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	// create renderer obj
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	// create texture obj
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	// SDL defines this int type to force 32 bit of int
	// we are allocating enough memory to store the pixels
	m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// memset - set a block of memory with particular value
	// very very useful
	// set one byte 0xFF = 255 max value
	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	// set a pixel to a color (it's hard to see)

//	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
//	SDL_RenderClear(m_renderer);
//	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
//	SDL_RenderPresent(m_renderer);

	return true;
}
;
bool Screen::processEvents() {
	SDL_Event event; // btw, this is a a struct. The difference between class and struct is struct by default has variables as public, whereas class is private by default

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}
;

void Screen::boxBlur() {
	// swap the buffers so pixel is in the m_buffer2 and we are drawing to m_buffer1
	Uint32 *temp = m_buffer1;
	m_buffer1 = m_buffer2; // change buffer1 to point to bufffer 2 memory
	m_buffer2 = temp;

	for (int y=0; y<SCREEN_HEIGHT; y++) {
		for(int x=0; x< SCREEN_WIDTH; x++){
            // to create the blur effect
			// for each pixel, we look at the surrounding pixel

			/*
			 * 0 0 0
			 * 0 1 0  << 1 is the one we are at
			 * 0 0 0
			 */

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;


			// take the average
			for (int row=-1; row<=1; row++){
				for(int col=-1; col<=1; col++){
					int currentX = x + col;
					int currentY = y + row;

					if(currentX >=0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT){
						Uint32 color = m_buffer2[currentY*SCREEN_WIDTH + currentX];

						Uint8 red = color >> 24; //shift 3 bytes
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}
			Uint8 red = redTotal/9;
			Uint8 green = greenTotal/9;
			Uint8 blue = blueTotal/9;

			setPixel(x, y, red, green, blue);
		}
	}
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	};
	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer1[(y * SCREEN_WIDTH) + x] = color;
}
;
void Screen::update() {
	//update texture to put it in the memory(buffer)
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

}

void Screen::close() {
	// make sure you free the memory
	delete[] m_buffer1;
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

//void Screen::clear() {
//	//use memset to clear the memory
//	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
//	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
//}
//;

} /* namespace caveofprograming */
