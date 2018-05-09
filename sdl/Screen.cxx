//#include<iomanip>
#include"Screen.h"
//using namespace std;
namespace myStd
{
	Screen::Screen(): m_window(NULL),m_renderer(NULL),m_texture(NULL),m_buffer1(NULL),m_buffer2(NULL)
	{
	}

	bool Screen::init()
	{
		if(SDL_Init(SDL_INIT_VIDEO) < 0) // <0 means if can't initialize
		{
			return false;
		}

		//****** initiaize window
		m_window = SDL_CreateWindow("Particle Explotion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(m_window == NULL) // if window cant open
		{
			SDL_Quit();
			return false;
		}
		//return true;    


		// keep screen refresh after couple of second
		// rendering syncronized without refresh
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		// rendering texture in RGB format, per pixel =32 bits = 4 byte, each value have 255 colouring posibility 
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		// *****if could not open render then program doesnt crash, just out 
		if(m_renderer == NULL)
		{
			//cout << "Could not return renderer" << endl;
			SDL_DestroyWindow(m_window); // window destroy
			SDL_Quit();
			return false; 
		}

		//****** if could not open texture then program doesnt crash, just out 
		if(m_texture == NULL)
		{
			//cout << "Could not return texture" << endl;
			SDL_DestroyRenderer(m_renderer); // rederer destroy
			SDL_DestroyWindow(m_window); // window destroy
			SDL_Quit();
			return false; 

		}

		//****** alltocate memoryt / fixing memory for the pixel or window
		// buffer = area of memory																	        // how much memory I need = SCREEN_WIDTH * SCREEN_HEIGHT							        // Uint32 = interger = SDL 32 bits
		// sometime need to give exception here if not allocate memory
		m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		// memset allow you to set memory for a particular value
		// every byte writing 255 value of RGB
		//255 in hexadecimal is 0xFF, 0x means this is hexadecimal velue
		//memset(buffer, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		//memset(m_buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		/*
		   for(int i =0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		   {
		   m_buffer[i] = 0xFF00FFFF;
		//FF = 1 byte
		}
		 */
		return true;	
	}
	void Screen::clear()
	{
	//	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	//	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	}
	void Screen::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
	{
		//	unsigned char alpha = 0xFF;
		//unsigned char red = 0x12;
		//unsigned char green = 0x34;
		//unsigned char blue = 0x56;
		if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		{
			return ;
		}
		Uint32 color = 0 ;
		color +=red;
		color <<=8;
		color +=green;
		color <<=8;
		color +=blue;
		color <<=8;
		color +=0xFF;
		m_buffer1[y*SCREEN_WIDTH + x] = color;

		//cout << setfill('0') << setw(8) << hex << color << endl;

	}
	void Screen::blurAlgorithm()
	{
		Uint32 *temp = m_buffer1;
		m_buffer1 = m_buffer2;
		m_buffer2 = temp;


		for(int y =0; y < SCREEN_HEIGHT; y++)
		{
			for(int x = 0; x < SCREEN_WIDTH; x++)
			{
				int redTotal = 0;
				int greenTotal = 0;
				int blueTotal = 0;
				for(int row = -1; row <=1; row++)
				{
					for(int col = -1; col <=1; col++)
					{
						int currentX = x + col;
						int currentY = y + row;
						if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >=0 && currentY < SCREEN_HEIGHT)
						{
							Uint32 color = m_buffer2[currentY*SCREEN_WIDTH + currentX];
							Uint8 red = color >> 24;
							Uint8 green = color >> 16;
							Uint8 blue = color >> 8;

							redTotal += red;
							greenTotal += green;
							blueTotal +=blue;

						}

					}
				}
				Uint8 red = redTotal/9; // since comsidering 9 pixel, average of 9 put in  middle one
				Uint8 green = greenTotal/9;
				Uint8 blue = blueTotal/9;

				setPixel(x, y, red, green, blue);

			}
		}
	}
	void Screen::update()
	{
		//****** updatig the texture
		// texture passing to the buffer -> clear the reder -> copy the render -> present the render
		//sizeof(Uint32) = 4;
		SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32));
	//	SDL_UpdateTexture(m_texture, NULL, m_buffer2, SCREEN_WIDTH*sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		// Below NULL means render and texture are fully captured
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}		
	// ***** Deleting or destriying everithing

	bool Screen::processEvents()
	{
		SDL_Event event;
		while(SDL_PollEvent(&event)) // event jotokkhon thake eta active thakb		
		{
			if(event.type == SDL_QUIT)
				return false;
		}
		return true;
	}
	void Screen::close()
	{
		delete [] m_buffer1; // delete the memory assigned for buffer
		delete [] m_buffer2; // delete the memory assigned for buffer
		SDL_DestroyRenderer(m_renderer); // rederer destroy
		SDL_DestroyTexture(m_texture); // Texture destroy
		SDL_DestroyWindow(m_window); // window destroy
		SDL_Quit();

	}


}


