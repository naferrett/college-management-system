/*
 * Utils.cpp
 *
 *  Created on: 8 de abr. de 2024
 *      Author: juan
 */

#include "../../include/utils/Utils.h"
#include "../../include/system/SysInfo.h"

#include <iostream>

void Utils::printMessage(string text)
{
	cout << "* " << SysInfo::getSystemName() << " message: " << text << endl;
}
