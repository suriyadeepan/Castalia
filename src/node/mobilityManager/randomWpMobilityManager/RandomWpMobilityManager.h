/****************************************************************************
 
 ****************************************************************************/

#ifndef _MOBILITYMODULE_H_
#define _MOBILITYMODULE_H_

#include "MobilityManagerMessage_m.h"
#include "VirtualMobilityManager.h"

using namespace std;

class RandomWpMobilityManager: public VirtualMobilityManager {
 private:
	/*--- The .ned file's parameters ---*/
	double updateInterval;
	double loc1_x;
	double loc1_y;
	double loc1_z;
	double snf_x;
	double snf_y;
	double snf_z;
	double speed;
	double direction;

	double PauseTime;
	bool VarySpeed ;
	double speedMax ;
	double speedMin ;

	bool VaryPauseTime ;
	double PauseMax ;
	double PauseMin ;

	/*--- Custom class parameters ---*/
	

	double dx;
	double dy;
	double distance;
	double TotalDist;
	
	double nextDest_x; 
	double nextDest_y; 
	
	double tmp;
	double TimeOutPauseTime;
	bool newDest;
	bool Pause;

 protected:

	void initialize();
	void newDestination();
	void handleMessage(cMessage * msg);
	void finishSpecific();

 public:
	double getSpeed();
	double getDirection();

};

#endif
