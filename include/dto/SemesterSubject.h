#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef SEMESTERSUBJECT_H_
#define SEMESTERSUBJECT_H_

class SemesterSubject {

    protected:
        string semesterId;
        string subjectCode;
        
    public:
        SemesterSubject(string semesterId, string subjectCode);

        string getSemesterId();
        void setSemesterId(string semesterId);

        string getSubjectCode();
        void setSubjectCode(string subjectCode);
};

#endif