#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class Person {

	protected:
		string name;
		int age;
		string phone;
		map<string, set<string>> subjects;

	public:
		Person(string name, int age, string phone);
		
		string getName() const;
		int getAge() const;
		string getPhone() const;
		map<string, set<string>>& getSubjects();


		void setName(const string& name);
		void setAge(int age);
		void setPhone(const string& phone);
        void addSubject(const string semesterId, const string subjectCode);
		void removeSubject(const string semesterId, const string subjectCode);
        set<string> findSubjects(const string semesterId);

		virtual	~Person();

};

#endif 
