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

#include "MacCom.h"

ofstream MacCom::theFile;
string MacCom::fileName;

MacCom::MacCom(const string & fName)
{
	fileName = fName;
}

void MacCom::setDebugFileName(const string & fName)
{
	fileName = fName;
}

ofstream & MacCom::getStream(void)
{
	if (!theFile.is_open())
		theFile.open(fileName.c_str(), ios::app);
	theFile.setf(ios::left);

	return theFile;
}

void MacCom::closeStream(void)
{
	if (theFile.is_open())
		theFile.close();
}
