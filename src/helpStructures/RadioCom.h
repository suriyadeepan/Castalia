/****************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2010                         *
 *  Developed at the ATP lab, Networked Systems research theme              *
 *  Author(s): Athanassios Boulis, Dimosthenis Pediaditakis                 *
 *  This file is distributed under the terms in the attached LICENSE file.  *
 *  If you do not find this file, copies can be found by writing to:        *
 *                                                                          *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
 *      Attention:  License Inquiry.                                        *
 *                                                                          *  
 ****************************************************************************/

#ifndef RADIOCOM_H_
#define RADIOCOM_H_

#include <iostream>
#include <fstream>
using namespace std;

class RadioCom {
 private:
	static ofstream theFile;
	static string fileName;

 public:
	RadioCom(const string & fName);
	static void setDebugFileName(const string & fName);
	static ofstream & getStream(void);
	static void closeStream(void);
};

#endif				
