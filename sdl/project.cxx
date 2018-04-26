// To compile this file
// g++ basic.cxx -w -lSDL2 -o basic
// SDL, Simple Direct Media Layer
#include<iostream>
#include</usr/include/SDL2/SDL.h>
#include"Screen.h"
#include"Swarm.h"
#include<stdlib.h>
#include<time.h>

using namespace std;
using namespace myStd;

int main()
{
	srand(time(NULL));
	Screen screen;
	if(screen.init() == false)
		cout << "Can't open SDL" << endl;
#if 0
	//const int SCREEN_WIDTH = 800;
	//const int SCREEN_HEIGHT = 600; // 800 x 600 pixel

	if(SDL_Init(SDL_INIT_VIDEO) < 0) // <0 means if can't initialize
	{
		cout << " NOt! success"<< endl;
		return 1;
	}

	//****** initiaize window
	window = SDL_CreateWindow("Particle Explotion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); 
	if(window == NULL) // if window cant open
	{
		SDL_Quit();
		return 2;
	}
	
	// **************main game or GUI start from here ************

	// keep screen refresh after couple of second
	// rendering syncronized without refresh
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	// rendering texture in RGB format, per pixel =32 bits = 4 byte, each value have 255 colouring posibility 
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	
	// *****if could not open render then program doesnt crash, just out 
	if(renderer == NULL)
	{
		cout << "Could not return renderer" << endl;
		SDL_DestroyWindow(window); // window destroy
		SDL_Quit();
		return 3; 
	}
	
	//****** if could not open texture then program doesnt crash, just out 
	if(texture == NULL)
	{
		cout << "Could not return texture" << endl;
		SDL_DestroyRenderer(renderer); // rederer destroy
		SDL_DestroyWindow(window); // window destroy
		SDL_Quit();
		return 4; 
	}
	
	//****** alltocate memoryt / fixing memory for the pixel or window
	// buffer = area of memory
	// how much memory I need = SCREEN_WIDTH * SCREEN_HEIGHT
	// Uint32 = interger = SDL 32 bits
	// sometime need to give exception here if not allocate memory
	buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	// memset allow you to set memory for a particular value
	// every byte writing 255 value of RGB
	//255 in hexadecimal is 0xFF, 0x means this is hexadecimal velue
	//memset(buffer, 255, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	for(int i =0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
	{
		buffer[i] = 0xFF00FFFF;
		//FF = 1 byte
	}
	//****** updatig the texture
	// texture passing to the buffer -> clear the reder -> copy the render -> present the render
	//sizeof(Uint32) = 4;
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	// Below NULL means render and texture are fully captured
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
#endif	
	//***** eventing start
	Swarm swarm;
	SDL_Event event;
	bool quit = false;
	while(!quit)
	{
		// updates particles
		// draw praticles
		int elapsed = SDL_GetTicks(); // This is a number in SDL in mili second
		unsigned char green =(unsigned char)((1 + sin(elapsed*0.001))*128); // multiply with 128 to make 255. becuse green is highest 255. 
		unsigned char red =(unsigned char)((1 + sin(elapsed*0.002))*128); // multiply with 128 to make 255. becuse green is highest 255. 
		unsigned char blue =(unsigned char)((1 + sin(elapsed*0.003))*128); // multiply with 128 to make 255. becuse green is highest 255. 
		const Particle * const pParticles = swarm.getParticles(); 
		for(int i =0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;
			
			screen.setPixel(x,y,red, green, blue);
		}
	/*
		int elapsed = SDL_GetTicks(); // This is a number in SDL in mili second
		unsigned char green =(unsigned char)((1 + sin(elapsed*0.001))*128); // multiply with 128 to make 255. becuse green is highest 255. 
		unsigned char red =(unsigned char)((1 + sin(elapsed*0.002))*128); // multiply with 128 to make 255. becuse green is highest 255. 
		unsigned char blue =(unsigned char)((1 + sin(elapsed*0.003))*128); // multiply with 128 to make 255. becuse green is highest 255. 
		
		for(int y =0; y < Screen::SCREEN_HEIGHT;y++)
		{
			for(int x = 0; x < Screen::SCREEN_WIDTH; x++)
			{
				screen.setPixel(x,y,0,green,0);
			}	
		}	
		*/
		// Event loop, window te ja dhekha jay
		/*
		while(SDL_PollEvent(&event)) // event jotokkhon thake eta active thakbe
		{
			if(event.type == SDL_QUIT)
				quit = true;

			//
		}
		*/
	//	screen.setPixel(400,300,0,255,0);
		screen.update();
		if(screen.processEvents() == false)
		{
			break;
		}
	}
	screen.close();
#if 0	
	// ***** Deleting or destriying everithing
	delete [] buffer; // delete the memory assigned for buffer
	SDL_DestroyRenderer(renderer); // rederer destroy
	SDL_DestroyTexture(texture); // Texture destroy
	SDL_DestroyWindow(window); // window destroy
	SDL_Quit();
#endif
return 0;
}
