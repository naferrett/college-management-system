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

        string getSemesterId() const;
        void setSemesterId(string semesterId);

        string getSubjectCode() const;
        void setSubjectCode(string subjectCode);
};

#endif