#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef SEMESTER_H_
#define SEMESTER_H_

class Semester {

    protected:
        string id;
        int year;
        int semesterNumber;
        vector<string> semestersID = {"24S1", "24S2", "25S1", "25S2", "26S1", "26S2", "27S1", "27S2", "28S1", "28S2"};

    public:
        Semester(string id, int year, int semesterNumber);

        string getId();
        void setId(string id);
        bool isValidSemesterId(string id);

        int getYear();
        void setYear(int year);

        int getSemesterNumber();
        void setSemesterNumber();

};

#endif