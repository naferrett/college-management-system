#include <iostream>
#include <string>

using namespace std;

#ifndef SUBJECT_H_
#define SUBJECT_H_

class Subject {

    protected:
        string code;
        string name;
        string syllabus;

    public:
        Subject(string code, string name, string syllabus);

        string getCode();
        void setCode(string code);

        string getName();
        void setName(string name);

        string getSyllabus();
        void setSyllabus(string syllabus);

};

#endif