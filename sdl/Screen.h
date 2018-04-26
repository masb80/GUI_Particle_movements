// C++ preprocessor language
// preprocessor run this before the code compile
#ifndef SCREEN_H_
// we are defining below
#define SCREEN_H_
#include</usr/include/SDL2/SDL.h>

namespace myStd
{	
	class Screen
	{
		private:
			SDL_Window *m_window;
			SDL_Renderer *m_renderer;
			SDL_Texture *m_texture;
			Uint32 *m_buffer;
		public:
			const static int SCREEN_WIDTH = 800;
			const static int SCREEN_HEIGHT = 600; // 800 x 600 pixel
		
		public:	
			Screen();
			bool init();
			void update();
			bool processEvents();
			void close();
			void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue); // uint8_t is char type 
	};
}

#endif /* BITMAP_H_ */
