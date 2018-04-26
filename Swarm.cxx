// for the behavior of particles
//#include<iomanip>
#include"Swarm.h"
//using namespace std;
namespace myStd
{
	
	Swarm::Swarm()
	{
		m_pParticles = new Particle[NPARTICLES];
	}
	Swarm::~Swarm()
	{
		delete [] m_pParticles;
	}

}


