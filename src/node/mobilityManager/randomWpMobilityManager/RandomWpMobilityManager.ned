//****************************************************************************

//****************************************************************************/

package node.mobilityManager.randomWpMobilityManager;

simple RandomWpMobilityManager like node.mobilityManager.iMobilityManager {
 parameters:
	bool collectTraceInfo = default (false);
	double updateInterval = default (100);
	double sNfield_x = default (100);
	double sNfield_y = default (100);
	double speed = default (1);

	double PauseTime = default (0);
	
	bool VarySpeed = default (true);
	double speedMax = default(1);
	double speedMin = default(1);

	bool VaryPauseTime = default (false);
	double PauseMax = default(5);
	double PauseMin = default(1);

}
