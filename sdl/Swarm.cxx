// for the behavior of particles
//#include<iomanip>
#include"Swarm.h"
//using namespace std;
namespace myStd
{
	
	Swarm::Swarm(): lastTime(0)  
	{
		m_pParticles = new Particle[NPARTICLES];
	}
	Swarm::~Swarm()
	{
		delete [] m_pParticles;
	}
	void Swarm::update(int elapsed)
	{
		int interval = elapsed - lastTime; // common desingn pattern, interval of time since the last time
		// in here we will update the particles 
		for(int i =0; i < Swarm::NPARTICLES; i++)
		{
			m_pParticles[i].update(interval);
		}

		lastTime = elapsed; // storing the present time for next interval calculation

	}

}


