#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Semester.h"
#include "Subject.h"

using namespace std;

#ifndef CLASSDTO_H_
#define CLASSDTO_H_

class ClassDTO: public Semester, public Subject {

    protected:
        string teacherId;
        vector<string> studentsRAs;
        map<string, double> studentGrades;

    public:
        ClassDTO(string semesterId, int semesterYear, int semesterNumber, string subjCode, string subjName, string subjSyllabus, string teacherId, vector<string>& studentsRAs, map<string, double>& studentGrades);

        string getTeacherId();
        void setTeacherId(string teacherId);

        vector<string> getStudentsRAs();
        void setStudentsRAs(vector<string>& studentsRAs);

        map<string, double> getStudentGrades();
        void setStudentGrades(map<string, double>& studentGrades);

};

#endif