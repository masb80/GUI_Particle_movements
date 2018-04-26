// C++ preprocessor language
// preprocessor run this before the code compile
#ifndef PARTICLE_H_
// we are defining below
#define PARTICLE_H_
#include</usr/include/SDL2/SDL.h>

namespace myStd
{	
	class Particle
	{
		public:
			double m_x;
			double m_y; // duble will plexible in moving pixel to pixel
		public:
			Particle();
			//virtual ~Particle();
		
	}; /*CLASS */
} /*NAMESPACE */

#endif /* PARTICLE_H_ */
