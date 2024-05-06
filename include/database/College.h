#ifndef COLLEGE_H_
#define COLLEGE_H_

#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "../../include/dto/Person.h"
#include "../../include/dto/StudentDTO.h"
#include "../../include/dto/ClassDTO.h"
#include "../../include/dto/Subject.h"

using namespace std;

class College final {
	
	protected:
		static map<string, shared_ptr<Person>> students;
		static map<string, shared_ptr<Person>> teachers;
		static vector<shared_ptr<ClassDTO>> classes;
		static vector<shared_ptr<Subject>> subjects;

	public:
		static map<string, shared_ptr<Person>>& getStudents();
		void setStudents(map<string, shared_ptr<Person>> students);
		static map<string, shared_ptr<Person>>& getTeachers();
		void setTeachers(map<string, shared_ptr<Person>> teachers);
		static vector<shared_ptr<ClassDTO>>& getClasses();
		void setClasses(vector<shared_ptr<ClassDTO> > &classes);
		static vector<shared_ptr<Subject>>& getSubjects();
		void setSubjects(vector<shared_ptr<Subject> > &subjects);
};

#endif 

