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
		m_x = ((2.0 * rand())/RAND_MAX)-1;// [-1,1] // particals positions x
		m_y = ((2.0 * rand())/RAND_MAX)-1;// [-1,1] // particles positiion y
		// particles speed
		m_xspeed = 0.01 * (((2.0 * rand())/RAND_MAX) -1); // random number between -1 to 1
		m_yspeed = -0.01 * (((2.0 * rand())/RAND_MAX) -1); // random number between -1 to 1
	}
	void Particle::update()
	{
	// in here we will change the position of the particles
		//const double speed = 0.01;
		// this speed of movement I can do in the constructor and diminish at the edge
		//const double m_xspeed = 0.01 * (((2.0 * rand())/RAND_MAX) -1); // random number between -1 to 1
		//const double m_yspeed = -0.01 * (((2.0 * rand())/RAND_MAX) -1); // random number between -1 to 1
		m_x +=m_xspeed;
		m_y +=m_yspeed;
	
		if(m_x < -1.0 || m_x >= 1.0)
			m_xspeed = - m_xspeed;
		if(m_y < -1.0 || m_y >= 1.0)
			m_yspeed = - m_yspeed;
	}

}


