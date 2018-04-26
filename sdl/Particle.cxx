// for crearion of particle
//#include<iomanip>
#include"Particle.h"
#include<stdlib.h>
//using namespace std;
namespace myStd
{
	
	Particle::Particle()
	{
		// each run the particles will create its random location
		m_x = ((2.0 * rand())/RAND_MAX)-1;// [-1,1]
		m_y = ((2.0 * rand())/RAND_MAX)-1;// [-1,1]
	}


}


