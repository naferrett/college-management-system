#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iostream>

using namespace std;

class Person {

	protected:
		string name;
		int age;
		string phone;

	public:
		Person(string name, int age, string phone);
		
		string getName() const;
		int getAge() const;
		string getPhone() const;

		void setName(const string& name);
		void setAge(int age);
		void setPhone(const string& phone);

		virtual	~Person();

};

#endif 
