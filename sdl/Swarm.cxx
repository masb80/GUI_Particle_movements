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
	void Swarm::update()
	{
		// in here we will update the particles 
		for(int i =0; i < Swarm::NPARTICLES; i++)
		{
			m_pParticles[i].update();
		}

	}

}


