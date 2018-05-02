// C++ preprocessor language
// preprocessor run this before the code compile
#ifndef PARTICLE_H_
// we are defining below
#define PARTICLE_H_
#include</usr/include/SDL2/SDL.h>
//#include<SDL.h>

namespace myStd
{	
	class Particle
	{
		public:
			double m_x;
			double m_y; // duble will plexible in moving pixel to pixel
			double m_xspeed;
			double m_yspeed; // duble will plexible in moving pixel to pixel
		public:
			Particle();
			//virtual ~Particle();
			void update(); // it will update the particles in every secinds		
	}; /*CLASS */
} /*NAMESPACE */

#endif /* PARTICLE_H_ */
