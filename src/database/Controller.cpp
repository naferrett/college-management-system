/*
 * Controller.cpp
 *
 *  Created on: 8 de abr. de 2024
 *      Author: juan
*/

#include <exception>
#include <iostream>
#include <memory>
#include <string>

#include "../../include/database/Controller.h"
#include "../../include/menu/Menu.h"
#include "../../include/utils/Utils.h"
#include "../../include/system/SysInfo.h"
#include "../../include/dao/StudentDAO.h"
#include "../../include/database/College.h"
#include "../../include/dao/TeacherDAO.h"
#include "../../include/dto/Subject.h"
#include "../../include/dto/StudentDTO.h"
#include "../../include/dao/SubjectDAO.h"
#include "../../include/dto/TeacherDTO.h"
#include "../../include/dao/ClassDAO.h"
#include "../../include/dto/Semester.h"

Controller::Controller() {
}

Controller::~Controller() {
}

void Controller::start() {
	vector<string> menuItens { "Students", "Teachers", "Subjects", "Reports",
			"Ajuda", "Sobre", "Sai do programa" };
	vector<void (Controller::*)()> functions { &Controller::actionStudents,
			&Controller::actionTeachers, &Controller::actionSubjects, 
			 &Controller::actionReports, &Controller::actionHelp, &Controller::actionAbout };
	launchActions("Menu Principal", menuItens, functions);
}

void Controller::actionStudents() {
	vector<string> menuStudents { "Inserir estudante",
			"Visualizar todos os estudantes", "Pesquisar estudante por RA",
			"Alterar estudante", "Inserir estudante na classe", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertStudent,
			&Controller::actionToDo, &Controller::actionToDo,
			&Controller::actionToDo, &Controller::actionInsertStudentToClass };
	launchActions("Menu Estudantes", menuStudents, functions);
}

void Controller::actionTeachers() {
	vector<string> menuTeachers { "Inserir professor",
			"Visualizar todos os professores", "Pesquisar professor por ID",
			"Alterar professor", "Inserir professor na classe", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertTeacher,
			&Controller::actionToDo, &Controller::actionToDo,
			&Controller::actionToDo, &Controller::actionInsertTeacherToClass };
	launchActions("Menu Professores", menuTeachers, functions);
}


void Controller::actionSubjects()
{
	vector<string> menuSubjects { "Inserir matéria",
			"Visualizar todos as disciplinas", "",
			"", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertSubject,
			&Controller::actionToDo, &Controller::actionToDo,
			&Controller::actionToDo };
	launchActions("Menu Matérias", menuSubjects, functions);
}

void Controller::actionReports()
{
	return;
}

//add
void Controller::actionInsertStudent() {
    string name, phone, ra, course;
    int age;

    cout << "Inserir novo estudante:" << endl;;

	while(true) { //while para validação dos dados inseridos
    	cout << "Nome: ";
		cin.ignore(); 
    	getline(cin, name);

		if(!name.empty()) { //confere se o usuario informou o nome
			break;
		}

		Utils::printMessage("Erro, insira o nome do estudante!");
	}

	while(true) { //validação da idade 
    	cout << "Idade: ";
    	cin >> age;
		cin.ignore();

		if (cin.fail()) { 
			Utils::printMessage("Erro, insira uma idade válida!");
            cin.clear(); 
            cin.ignore();
		}
		else if (age > 100 || age <= 0) { 
			Utils::printMessage("Erro, insira uma idade válida!");
		} else {
			break;
		}
	}

	while(true) { //validação do telefone
    	cout << "Telefone: ";
 		getline(cin, phone);

		if(phone.length() != 11) {
			Utils::printMessage("Erro, o número de telefone deve conter 11 dígitos!"); //DDD + número
		} else {
			break;
		}
	}

	while(true) { // validação do RA
    	cout << "RA: ";
    	getline(cin, ra);

		if(ra.length() != 6 ) { //caso o usuario insira o RA errado
			Utils::printMessage("Erro, o RA deve conter 6 dígitos!");
		} else {
			break;
		}
	}

	while(true) {
    	cout << "Curso: ";
    	getline(cin, course);

		if(!course.empty()) { //confere se o usuario informou o curso
			break;
		}

		Utils::printMessage("Erro, insira o curso do estudante!");
	}
 
    StudentDTO newStudent(name, age, phone, ra, course);

    try {
		shared_ptr<StudentDAO> studentDAO = make_shared<StudentDAO>();
        //StudentDAO studentDAO(college); 
        studentDAO->add(newStudent); 
        Utils::printMessage("Estudante inserido com sucesso!");
    } catch (const exception &e) {
         Utils::printMessage("Erro ao inserir estudante: " + string(e.what()));;
    }
}

//add
void Controller::actionInsertTeacher() {
    
    string name, phone, id;
    int age;
	double salary;

    cout << "Inserir novo professor:" << endl;

	while(true) {
    cout << "Nome: ";
	cin.ignore(); 
    getline(cin, name);

	if(!name.empty()) {
		break;
	}
		Utils::printMessage("Erro, insira o nome do professor!");
	}

	while(true) {
    	cout << "Idade: ";
    	cin >> age;
		cin.ignore();

		if (cin.fail()) { 
			Utils::printMessage("Erro, insira uma idade válida!");
           	cin.clear(); 
           	cin.ignore();
		}

		else if (age > 100 || age <= 0) { 
			Utils::printMessage("Erro, insira uma idade válida!");
		} else {
			break;
		}
	}

	while(true) {
    	cout << "Telefone: ";
 		getline(cin, phone);

		if(phone.length() != 11) {
			Utils::printMessage("Erro, o número de telefone deve conter 11 dígitos!"); //DDD + número
		} else {
			break;
		}
	}

	while(true) {
    	cout << "ID do professor: ";
    	getline(cin, id);

		if(!id.empty()) {
			break;
		}
		Utils::printMessage("Erro, insira o ID do professor!");
	}

	while(true) {
		cout << "Salário do professor: ";
		cin >> salary;
		cin.ignore();

		if(cin.fail()) {
			Utils::printMessage("Erro, insira um salário válido!");
			cin.clear();
			cin.ignore();
		}
		else if (salary < 0) {
			Utils::printMessage("Erro, insira um salário válido!");
		}
		else {
			break;
		}
	}

    TeacherDTO newTeacher(name, age, phone, id, salary);

	try {
        shared_ptr<TeacherDAO> teacherDAO = make_shared<TeacherDAO>(); //criar e add ao colleege
        teacherDAO->add(newTeacher);
        Utils::printMessage("Professor inserido com sucesso!");

    } catch (const exception& ex) {
        Utils::printMessage("Erro ao inserir professor: " + string(ex.what()));
    }
}

//add
void Controller::actionInsertSubject() {
    
        string code, name, syllabus;
        
        cout << "Inserir nova disciplina:" << endl;

		while(true) {
        cout << "Código: ";
		cin.ignore();
        getline(cin, code);

		if(!code.empty()) {
			break;
		}
		Utils::printMessage("Erro, insira o código da disciplina!");
		}

		while(true) {
		cout << "Nome: ";
        getline(cin, name);

		if(!name.empty()) {
			break;
		}
		Utils::printMessage("Erro, insira o nome da disciplina!");
		}

		while(true) {
        cout << "Ementa: ";
        getline(cin, syllabus);

		if(!syllabus.empty()) {
			break;
		}
		Utils::printMessage("Erro, insira a ementa da disciplina!");
		}


        Subject newSubject(code, name, syllabus);

    try {
		shared_ptr<SubjectDAO> subject = make_shared<SubjectDAO>();
        subject->add(newSubject); 
        Utils::printMessage("Nova disciplina adicionada com sucesso!");
    } catch (const exception &ex) {
         Utils::printMessage("Erro ao inserir disciplina: " + string(ex.what()));;
    }
}


void Controller::actionHelp(void) {
	Utils::printMessage(SysInfo::getVersion() + " | Help");
	actionToDo();
}

void Controller::actionAbout(void) {
	Utils::printMessage(SysInfo::getVersion() + " | About");
	actionToDo();
}

void Controller::launchActions(string title, vector<string> menuItens,
		vector<void (Controller::*)()> functions) {
	try {
		Menu menu(menuItens, title, "Sua opcao: ");
		menu.setSymbol("*");

		while (int choice = menu.getChoice()) {
			(this->*functions.at(choice - 1))();
		}
	} catch (const exception &myException) {
		Utils::printMessage(
				"Unexpected problem launching actions. "
						+ string(myException.what()));
	}
}

void Controller::actionToDo(void) {
	Utils::printMessage("Place holder function. Code was not written yet!\n");
}

void Controller::actionInsertStudentToClass() {
	string semesterID, subjectCode, studentRA;

	cout << "Inserir estudante na classe:" << endl;

	while(true) {
		cout << "ID do semestre: ";
		getline(cin, semesterID);

		//bool isValidSemester = Semester::isValidSemesterId(semesterID);

		if(!semesterID.empty()) {
			//if(isValidSemester) {
            	break;
        	//}
		}
		Utils::printMessage("Erro, insira o Id do semestre!");
	}

	while(true) {
		cout << "ID da disciplina: ";
		getline(cin, subjectCode);

		if(!subjectCode.empty()) {
			break;
		}
		Utils::printMessage("Erro. Insira o código da disciplina!");
	}

	while(true) {
		cout << "RA do estudante: ";
		getline(cin, studentRA);

		if(studentRA.length() != 6) {
			Utils::printMessage("Erro, o RA deve conter 6 dígitos!");
		} else {
			break;
		}
	}

	try {
		ClassDAO classe;
		classe.addStudentToClass(semesterID, subjectCode, studentRA);
    } catch (const exception &e) {
         Utils::printMessage("Erro ao inserir estudante na classe: " + string(e.what()));
    }
}


void Controller::actionInsertTeacherToClass() {
	string semesterID, subjectCode, teacherID;

	cout << "Inserir professor na classe:" << endl;

	while(true) {
		cout << "ID do semestre: ";
		getline(cin, semesterID);

		//bool isValidSemester = Semester::isValidSemesterId(semesterID);

		if(!semesterID.empty()) {
			//if(isValidSemester) {
            	break;
        	//}
		}
		Utils::printMessage("Erro, insira o Id do semestre!");
	}

	while(true) {
		cout << "ID da disciplina: ";
		getline(cin, subjectCode);

		if(!subjectCode.empty()) {
			break;
		}
		Utils::printMessage("Erro. Insira o código da disciplina!");
	}

	while(true) {
		cout << "ID do professor: ";
		getline(cin, teacherID);

		if(!teacherID.empty()) {
			break;
		}
		Utils::printMessage("Erro. Insira o Id do professor!");
	}

	try {
		ClassDAO classe;
		classe.addProfessorToClass(semesterID, subjectCode, teacherID);
    } catch (const exception &e) {
         Utils::printMessage("Erro ao inserir estudante na classe: " + string(e.what()));
    }

}
