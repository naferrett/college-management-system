#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>
#include <vector>
#include <memory>

using namespace std;

#include "College.h"

class Controller final {
	private:
	    shared_ptr<College> college;
		void actionStudents();
		void actionTeachers();
		void actionClasses();
		void actionRelatory();
		// void actionHelp(void);
		// void actionAbout(void);
		void launchActions(string title, vector<string> menuItens, vector<void (Controller::*)()> functions);
		
		// Add
		void actionInsertStudent();
		void actionInsertTeacher();
		void actionInsertClass();
	
		// Visualize
		void actionVisualizeStudents();
		void actionVisualizeTeachers();
		void actionVisualizeClasses();
	
		// Insert To Class
		void actionInsertStudentAndGradesToClass();
		void actionInsertTeacherToClass();
	
		// Search
		void actionSearchStudent();
		void actionSearchTeacher();
		void actionSearchClass();
	
		// Modify
		void actionModifyStudent();
		void actionModifyTeacher();
		void actionModifyClass();
	
		// Delete
		void actionDeleteStudent();
		void actionDeleteTeacher();
		void actionDeleteClass();
	
		// Relatory
		void actionShowSubjectsStudent();
		void actionStudentSubjectInfo();
		void actionSubjectsTaughtByTeacher();
		void actionSubjectAvgGrades();
		void actionStudentAvgGrades();


	public:
		Controller();
		virtual ~Controller();
		void start();
	
};

#endif /* CONTROLLER_H_ */
