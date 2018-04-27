// C++ preprocessor language
// preprocessor run this before the code compile
#ifndef SWARM_H_
// we are defining below
#define SWARM_H_
#include</usr/include/SDL2/SDL.h>
#include "Particle.h"
namespace myStd
{	
	class 	Swarm
	{
		private:
			Particle *m_pParticles; 
		public:
			Swarm();
		
		public:
			const static int NPARTICLES = 6000;
			Particle * const getParticles() { return m_pParticles;}
			virtual ~Swarm();
	}; /*CLASS */
} /*NAMESPACE */

#endif /* SWARM_H_ */
