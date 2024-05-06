/*
 * Controller.h
 *
 *  Created on: 8 de abr. de 2024
 *      Author: juan
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>
#include <vector>
#include <memory>

using namespace std;

#include "College.h"

class Controller final
{
private:
    shared_ptr<College> college;
	void actionStudents();
	void actionTeachers();
	void actionSubjects();
	void actionReports();
	void actionHelp(void);
	void actionAbout(void);
	void launchActions(string title, vector<string> menuItens, vector<void (Controller::*)()> functions);
	

	//add
	void actionInsertStudent();
	void actionInsertTeacher();
	void actionInsertSubject();

	void actionInsertStudentToClass();
	void actionInsertTeacherToClass();


	void actionToDo(void);
public:
	Controller();
	virtual ~Controller();
	void start();

};


#endif /* CONTROLLER_H_ */
