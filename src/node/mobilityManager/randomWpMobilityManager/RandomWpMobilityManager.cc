/****************************************************************************

 ****************************************************************************/

#include "RandomWpMobilityManager.h"

Define_Module(RandomWpMobilityManager);
//Défiition du nouveau module
void RandomWpMobilityManager::initialize()
{

	VirtualMobilityManager::initialize();

	updateInterval = (double)par("updateInterval");
	updateInterval = updateInterval / 1000;
	//interval de temps en miliSeconde entre chaque affichage de daplacement (pas) 

	loc1_x = nodeLocation.x;
	loc1_y = nodeLocation.y;
	loc1_z = 0;

	//position initilal du noeuds
	snf_x = (double)par("sNfield_x");
	snf_y = (double)par("sNfield_y");
	snf_z = 0;
	//les cooredonées de la cour de deplacement 
	//, ces parametres vont etre utilisé pour déterminer la nouvel destination du noeud 

	speed = (double)par("speed");

	//vitesse de dplacement 

	PauseTime = (double)par("PauseTime");

	VarySpeed = par("VarySpeed");
	speedMax = (double)par("speedMax");
	speedMin = (double)par("speedMin");

	VaryPauseTime = par("VaryPauseTime");
	PauseMax = (double)par("PauseMax");
	PauseMin = (double)par("PauseMin");


	TimeOutPauseTime = 0;
	newDest = false;
	Pause = false;

	//cette variable est mise a 1 afin de generer une nouvel destination

	if(VarySpeed){
		speed = rand() % (int) speedMax + speedMin;
		trace() << "Speed defined :" << PauseTime;
	}

	if (VaryPauseTime) {
		PauseTime = rand() % (int) PauseMax + PauseMin;
		trace() << "PauseTime defined :" << PauseTime;
	}

	if (speed > 0) {

		nextDest_x = uniform(0,snf_x);
		nextDest_y = uniform(0,snf_y);

		distance = sqrt(pow(loc1_x - nextDest_x, 2) + pow(loc1_y - nextDest_y, 2));

		tmp = (distance / speed) / updateInterval;
		dx = (nextDest_x - loc1_x)/tmp;//definir le pas de X
		dy = (nextDest_y - loc1_y)/tmp;// definir le pas de y	

		if(dx != 0)
			direction =  (atan(dy/dx) * 180 * 7 )/22;
		else
			direction = 90;

		setLocation(loc1_x, loc1_y, loc1_z);
		scheduleAt(simTime() + updateInterval,
				new MobilityManagerMessage("Periodic location update message", MOBILITY_PERIODIC));
	}
	TotalDist = 0;
}

void RandomWpMobilityManager::handleMessage(cMessage * msg)
{
	int msgKind = msg -> getKind();

	switch (msgKind) {

		case MOBILITY_PERIODIC: {

															if (newDest) {

																newDestination();		

															}else {

																if(!Pause){

																	double dist = sqrt(pow(nodeLocation.x - (nodeLocation.x + dx), 2) + pow(nodeLocation.y - (nodeLocation.y + dy), 2));
																	TotalDist += dist;
																	nodeLocation.x += dx;
																	nodeLocation.y += dy;

																	trace() << "changed location(x:y) to " << nodeLocation.x << ":" << nodeLocation.y;
																	Mobinfos() <<node->getIndex() << " " << nodeLocation.x
																		<< " " << nodeLocation.y << " " << nodeLocation.z;

																} else {
																	if(TimeOutPauseTime >= PauseTime){
																		Pause=false;
																		TimeOutPauseTime = 0;
																	}else{
																		trace() << "in pause (x:y) " << nodeLocation.x << ":" << nodeLocation.y;
																		TimeOutPauseTime += updateInterval;
																	}
																}

																if ((dx > 0 && nodeLocation.x > nextDest_x)
																		|| (dx < 0 && nodeLocation.x < nextDest_x)
																		|| (dy > 0 && nodeLocation.y > nextDest_y)
																		|| (dy < 0 && nodeLocation.y < nextDest_y)) {

																	nodeLocation.x -= dx;
																	nodeLocation.y -= dy;

																	if(dx != 0)
																		direction =  (atan(dy/dx) * 180 * 7 )/22;
																	else
																		direction = 90;


																	loc1_x = nextDest_x;
																	loc1_y = nextDest_y;

																	newDest = true;
																}

															}	
															notifyWirelessChannel();
															scheduleAt(simTime() + updateInterval,
																	new MobilityManagerMessage("Periodic location update message", MOBILITY_PERIODIC));

															break;
														}

		default: {
							 trace() << "WARNING: Unexpected message " << msgKind;
						 }
	}

	delete msg;
	msg = NULL;
}
void RandomWpMobilityManager::newDestination(){

	nextDest_x = uniform(0, snf_x);
	nextDest_y = uniform(0, snf_y);
	trace() << "new random destination (x:y) " << nextDest_x << ":" << nextDest_y;

	distance = sqrt(pow(loc1_x - nextDest_x, 2) + pow(loc1_y - nextDest_y, 2));

	newDest = false;

	tmp = (distance / speed) / updateInterval;
	dx = (nextDest_x - loc1_x) / tmp;//definir le pas de X
	dy = (nextDest_y - loc1_y) / tmp;// definir le pas de y 

	if (VarySpeed) {
		speed = rand() % (int) speedMax + speedMin;
		trace() << "new speed defined :" << speed;
	}

	if (VaryPauseTime) {
		PauseTime = rand() % (int) PauseMax + PauseMin;
		trace() << "new PauseTime defined :" << PauseTime;
	}

	Pause = true;	
}
void RandomWpMobilityManager::finishSpecific(){
	declareOutput("Trajectory length");
	collectOutput("Trajectory length", "", TotalDist);
}

// --- User Defined --- //
double RandomWpMobilityManager::getSpeed(){ return speed; }
double RandomWpMobilityManager::getDirection(){ return direction; }
// ------------------- //
