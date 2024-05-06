/*
 * System.h
 *
 *  Created on: 8 de abr. de 2024
 *      Author: juan
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

using namespace std;

#include <string>

class SysInfo final{

private:
	static const string author;
	static const string date;
	static const string department;
	static const string institution;
	static const string systemName;
	static const string version;

public:
	static const string& getAuthor();
	static const string& getDate();
	static const string& getDepartment();
	static const string& getInstitution();
	static const string& getSystemName();
	static const string& getVersion();

	static const string getFullVersion();
};

#endif /* SYSTEM_H_ */
