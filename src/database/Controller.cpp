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
#include "../../include/dto/TeacherDTO.h"
#include "../../include/dao/ClassDAO.h"
#include "../../include/dto/Semester.h"

Controller::Controller() {}

Controller::~Controller() {}

void Controller::start() {
	vector<string> menuItens { "Estudantes", "Professores", "Turmas", "Relatório", "Sai do programa" };
	vector<void (Controller::*)()> functions { &Controller::actionStudents,
			&Controller::actionTeachers, &Controller::actionClasses, 
			&Controller::actionRelatory};
	launchActions("Menu Principal", menuItens, functions);
}

void Controller::actionStudents() {
	vector<string> menuStudents { "Inserir estudante",
			"Visualizar todos os estudantes", "Pesquisar estudante por RA",
			"Alterar estudante", "Remover estudante", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertStudent,
			&Controller::actionVisualizeStudents, &Controller::actionSearchStudent,
			&Controller::actionModifyStudent, &Controller::actionDeleteStudent};
	launchActions("Menu Estudantes", menuStudents, functions);
}

void Controller::actionTeachers() {
	vector<string> menuTeachers { "Inserir professor",
			"Visualizar todos os professores", "Pesquisar professor por ID",
			"Alterar professor", "Remover professor", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertTeacher,
			&Controller::actionVisualizeTeachers, &Controller::actionSearchTeacher,
			&Controller::actionModifyTeacher, &Controller::actionDeleteTeacher };
	launchActions("Menu Professores", menuTeachers, functions);
}

void Controller::actionClasses() {
	vector<string> menuClasses { "Inserir turma",
			"Visualizar todos as turmas", "Adicionar professor à uma turma" ,
			"Adicionar estudante e nota à uma turma", "Procurar turma por código", 
			"Alterar turma", "Remover turma", "Voltar ao menu principal" };
	vector<void (Controller::*)()> functions { &Controller::actionInsertClass,
			&Controller::actionVisualizeClasses, &Controller::actionInsertTeacherToClass,
			&Controller::actionInsertStudentAndGradesToClass, &Controller::actionSearchClass,
			&Controller::actionModifyClass, &Controller::actionDeleteClass};
	launchActions("Menu Turmas", menuClasses, functions);
}

void Controller::actionRelatory() {
	vector<string> menuRelatory { "Mostrar disciplinas matriculadas por um estudante",
			"Mostrar estudantes de uma disciplina e suas notas", 
			"Mostrar disciplinas ministradas por um professor", 
			"Mostrar média das notas de uma disciplina", "Mostrar médias das notas de um estudante", 
			"Voltar ao menu principal"};
	vector<void (Controller::*)()> functions { &Controller::actionShowSubjectsStudent,
			&Controller::actionStudentSubjectInfo, &Controller::actionSubjectsTaughtByTeacher,
			&Controller::actionSubjectAvgGrades, &Controller::actionStudentAvgGrades};
	launchActions("Menu Relatórios", menuRelatory, functions);
}


//Student
void Controller::actionInsertStudent() {

    try {
		string name, phone, ra, course;
    	int age;

    	cout << "Inserir novo estudante:" << endl;;

		while(true) { //Validação para Nome
    		cout << "Nome: ";
			cin.ignore(); 
    		getline(cin, name);

			if(!name.empty()) { //confere se o usuario informou o nome
				break;
			}

			Utils::printMessage("Erro, insira o nome do estudante!");
		}

		while(true) { //Validação da Idade 
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

		while(true) { //Validação do Telefone
    		cout << "Telefone: ";
 			getline(cin, phone);

			if(phone.length() != 11) {
				Utils::printMessage("Erro, o número de telefone deve conter 11 dígitos!"); //DDD + número
			} else {
				break;
			}
		}

		while(true) { //Validação do RA
    		cout << "RA: ";
    		getline(cin, ra);

			if(ra.length() != 6 ) { //caso o usuario insira o RA errado
			Utils::printMessage("Erro, o RA deve conter 6 dígitos!");
			} 
			
			else {

				break;
			}
		}

		while(true) { //Validação do Curso
    		cout << "Curso: ";
    		getline(cin, course);

			if(!course.empty()) { //confere se o usuario informou o curso
				break;
			}

			Utils::printMessage("Erro, insira o curso do estudante!");
		}
 
    	StudentDTO newStudent(name, age, phone, ra, course);
			shared_ptr<StudentDAO> studentDAO = make_shared<StudentDAO>();
        	studentDAO->add(newStudent); 
        	Utils::printMessage("Estudante inserido com sucesso!");

    	} catch (const exception &e) {
         	Utils::printMessage("Erro ao inserir estudante: " + string(e.what()));;
    	}
	
}
void Controller::actionVisualizeStudents() {
	
	try {
		StudentDAO students;
		students.read();
	} catch (const exception &e) {
		Utils::printMessage("Erro ao visualizar estudantes: " + string(e.what()));;
	}
	
}
void Controller::actionSearchStudent() {
	
	try {
		string RA;
		cout << "Digite o RA do estudante que deseja buscar: ";
		cin >> RA;
		StudentDAO studentDAO;
			
		shared_ptr<StudentDTO> studentPtr = studentDAO.search(RA);

		if (!studentPtr) {
			cout << "Estudante não encontrado." << endl;
		} else {
			cout << endl;
			cout << "Estudante encontrado!" << endl;
			cout << "Nome: " << studentPtr->getName() << endl;
			cout << "Idade: " << studentPtr->getAge() << endl;
			cout << "Telefone: " << studentPtr->getPhone() << endl;
			cout << "RA: " << studentPtr->getRa() << endl;
			cout << "Curso: " << studentPtr->getCourse() << endl;
			cout << endl;
		}
	} catch(const exception& e) {
		Utils::printMessage("Erro ao buscar estudante: " + string(e.what()));
	}
}
void Controller::actionModifyStudent() {
	
	try {
		string RA;
		cout << "Digite o RA do estudante que deseja modificar: ";
		cin >> RA;
		
		int opcao;
		cout << endl;
		cout << "Menu de Alterações:" << endl;
		cout << "(1) Nome" << endl;
		cout << "(2) Idade" << endl;
		cout << "(3) Telefone" << endl;
		cout << "(4) Ra" << endl;
		cout << "(5) Cuso" << endl;
		cout << "Escolha uma das opções: ";
		cin >> opcao;

		StudentDAO studentDAO;
		studentDAO.update(opcao, RA);
		Utils::printMessage("Alteração feita com sucesso!");

	} catch(const exception& e) {
		Utils::printMessage("Erro ao modificar estudante: " + string(e.what()));
	}


}
void Controller::actionDeleteStudent() {

	try {
		string RA;

		cout << "Digite o RA do estudante que deseja excluir: " << endl;
		cin >> RA;

		StudentDAO studentDAO;
    	studentDAO.remove(RA);

	} catch(const exception& e) {
		Utils::printMessage("Erro ao excluir estudante: " + string(e.what()));

	}
}


//Teacher 
void Controller::actionInsertTeacher() {
    
	try {
		string name, phone, id;
		int age;
		double salary;

		cout << "Inserir novo professor:" << endl;

		while(true) { //Validação para Nome
			cout << "Nome: ";
			cin.ignore(); 
			getline(cin, name);

			if(!name.empty()) {
				break;
			}
				Utils::printMessage("Erro, insira o nome do professor!");
		}

		while(true) { //Validação para Idade
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

		while(true) { //Validação para Telefone
			cout << "Telefone: ";
			getline(cin, phone);

			if(phone.length() != 11) {
				Utils::printMessage("Erro, o número de telefone deve conter 11 dígitos!"); //DDD + número
			} else {
				break;
			}
		}

		while(true) { //Validação para ID do Professor
			cout << "ID do professor: ";
			getline(cin, id);

			if(!id.empty()) {
				break;
			}
			Utils::printMessage("Erro, insira o ID do professor!");
		}

		while(true) { //Validação para Salário
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
			shared_ptr<TeacherDAO> teacherDAO = make_shared<TeacherDAO>(); 
			teacherDAO->add(newTeacher);
			Utils::printMessage("Professor inserido com sucesso!");

    } catch (const exception& ex) {
        Utils::printMessage("Erro ao inserir professor: " + string(ex.what()));
    }

}
void Controller::actionVisualizeTeachers() {
	
	try {
		TeacherDAO teacher;
		teacher.read();
	} catch (const exception &e) {
		Utils::printMessage("Erro ao visualizar professores: " + string(e.what()));;
	}

}
void Controller::actionSearchTeacher() {

	try {
		string id;
		cout << "Digite o ID do professor que deseja buscar: ";
		cin >> id;

		TeacherDAO teacherDAO;
		shared_ptr<TeacherDTO> teacherPtr = teacherDAO.search(id);

		if(!teacherPtr) {
			Utils::printMessage("Professor não encontrado.");
		} else {
			cout << endl;
			cout << "Professor encontrado!" << endl;
			cout << "Nome: " << teacherPtr->getName() << endl;
			cout << "Idade: " << teacherPtr->getAge() << endl;
			cout << "Telefone: " << teacherPtr->getPhone() << endl;
			cout << "ID: " << teacherPtr->getId() << endl;
			cout << "Salário: " << teacherPtr->getSalary() << endl;
			cout << endl;
		}
	} catch(const exception& e) {
		Utils::printMessage("Erro ao buscar professor:" + string(e.what()));
	}

}
void Controller::actionModifyTeacher() {
	
	try {
		string id;

		cout << "Digite o ID do professor que deseja modificar: ";
		cin >> id;
		
		int opcao;
		cout << endl;
		cout << "Menu de Alterações:" << endl;
		cout << "(1) Nome" << endl;
		cout << "(2) Idade" << endl;
		cout << "(3) Telefone" << endl;
		cout << "(4) ID" << endl;
		cout << "(5) Salário" << endl;
		cout << "Escolha uma das opções: ";
		cin >> opcao;

		TeacherDAO teacherDAO;
		teacherDAO.update(opcao, id);
		Utils::printMessage("Alteração feita com sucesso!");

	} catch(const exception& e) {
		Utils::printMessage("Erro ao modificar professor: " + string(e.what()));
	}

}
void Controller::actionDeleteTeacher() {
	
	try {
		string id;

		cout << "Digite o ID do professor que deseja excluir: " << endl;
		cin >> id;

		TeacherDAO teacherDAO;
		teacherDAO.remove(id);
	} catch(const exception& e) {
		Utils::printMessage("Erro ao excluir professor: " + string(e.what()));

	}
}


//Class
void Controller::actionInsertClass() {

    try {
		string semesterId, subjectCode, subjectName, subjectSyllabus;
		int semesterYear, semesterNumber;
			
		cout << "Inserir nova turma:" << endl;

		while(true) { //Verificação do ID do semestre
			cout << "ID do semestre: ";
			cin.ignore();
			getline(cin, semesterId);

			if(!semesterId.empty()) {
				break;
			}
			Utils::printMessage("Erro, insira o Id do semestre!");
		}

		while(true) { //Verificação do Ano do semestre
			cout << "Ano do semestre: ";
			cin >> semesterYear;

			if (cin.fail()) {
				Utils::printMessage("Erro, insira um ano válido!");
				cin.clear();
				cin.ignore();
			}
			else if(semesterYear < 0) {
				Utils::printMessage("Erro, insira um ano válido!");
				break;
			} else {
				break;
			}
		}
		
		while(true) { //Validação para Número do semestre 
			cout << "Número do semestre: ";
			cin >> semesterNumber;

			if (cin.fail()) {
				Utils::printMessage("Erro, insira um número de semestre válido!");
				cin.clear();
				cin.ignore();
			}
			else if(semesterNumber < 1 || semesterNumber > 2) {
				Utils::printMessage("Erro, o número de semestre deve ser 1 ou 2!"); 
			} else {
				break;
			}
		}

		while(true) { //Validação para Código da disciplina
			cout << "Código da disciplina: ";
			cin.ignore();
			getline(cin, subjectCode);

			if(!subjectCode.empty()) {
				break;
			}
			Utils::printMessage("Erro, insira o código da disciplina!");
		}

		while(true) { //Validação para Nome da disciplina
			cout << "Nome da disciplina: ";
			cin >> subjectName;
			// cin.ignore();
			// getline(cin, subjectName);

			if(!subjectName.empty()) {
				break;
			}
			Utils::printMessage("Erro, insira o nome da disciplina!");
		}

		while(true) { //Validação Ementa da disciplina
			cout << "Ementa da disciplina: ";
			cin.ignore();
			getline(cin, subjectSyllabus);

			if(!subjectSyllabus.empty()) {
				break;
			}
			Utils::printMessage("Erro, insira a ementa da disciplina!");
		}
		

		ClassDTO newClass(semesterId, semesterYear, semesterNumber, subjectCode, subjectName, subjectSyllabus);

		shared_ptr<ClassDAO> classDAO = make_shared<ClassDAO>();
        classDAO->add(newClass); 
        Utils::printMessage("Nova turma adicionada com sucesso!");
    } catch (const exception &ex) {
         Utils::printMessage("Erro ao inserir classe: " + string(ex.what()));;
    }
}
void Controller::actionInsertStudentAndGradesToClass() {
   
	try {
	    string semesterId, subjectCode, studentRA;
    	double studentGrade;

		cout << "Adicionar estudante e nota à uma turma:" << endl;
    	cout << "Digite o ID do semestre: ";
    	cin >> semesterId;
    	cout << "Digite o código da disciplina: ";
    	cin >> subjectCode;
    	cout << "Digite o RA do estudante: ";
    	cin >> studentRA;
    	cout << "Digite a nota do estudante: ";
    	cin >> studentGrade;

    	SemesterSubject subject(semesterId, subjectCode);
    	ClassDAO classDAO;

		classDAO.addStudentAndGradeToClass(subject, studentRA, studentGrade);
    	Utils::printMessage("Estudante e nota adicionados à turma com sucesso!");

	} catch (const exception &e) {
   		Utils::printMessage("Erro ao adicionar estudante e nota à turma: " + string(e.what()));
	}
}   
void Controller::actionInsertTeacherToClass() {

	try {
		string semesterId, subjectCode, teacherId;

		cout << "Adicionar professor à uma turma:" << endl;
		cout << "Digite o ID do semestre: ";
		cin >> semesterId;
		cout << "Digite o código da disciplina: ";
		cin >> subjectCode;
		cout << "Digite o ID do professor: ";
		cin >> teacherId;

		SemesterSubject subject(semesterId, subjectCode);
		ClassDAO classDAO;

		classDAO.addProfessorToClass(subject, teacherId);
		Utils::printMessage("Professor inserido à turma com sucesso!");
		

	} catch (const exception &e) {
    	Utils::printMessage("Erro ao adicionar professor à turma: " + string(e.what()));
	}
 
}	
void Controller::actionVisualizeClasses() {
	try {
		ClassDAO classe;
		classe.read();

	} catch (const exception &e) {
		Utils::printMessage("Erro ao visualizar turmas: " + string(e.what()));;
	}
	
}
void Controller::actionSearchClass() {
	try {
		string subjectCode;
		string semesterID;

		cout << "Digite o código da disciplina da turma que deseja buscar: ";
		cin >> subjectCode;

		cout << endl;

		cout << "Digite o ID do semestre da turma que deseja buscar: ";
		cin >> semesterID;

		SemesterSubject classToFind(semesterID, subjectCode);
		ClassDAO classDAO;
		shared_ptr<ClassDTO> classeDTO = classDAO.search(classToFind); 

		if(!classeDTO) {
			Utils::printMessage("Turma não encontrada.");
		} else {
			cout << endl;
			cout << "Turma encontrada!" << endl;
			cout << "Id do semestre: " << classeDTO->getId() << endl;
			cout << "Ano do semestre:" << classeDTO->getYear() << endl;
			cout << "Número do semestre: " << classeDTO->getSemesterNumber() << endl;
			cout << "Código da disciplina: " << subjectCode << endl;
			cout << "Nome da disciplina: " << classeDTO->getName() << endl;
			cout << "Ementa da disciplina: " << classeDTO->getSyllabus() << endl;
			cout << endl;
		}
	} catch(const exception& e) {
		Utils::printMessage("Erro ao buscar turma:" + string(e.what()));
	}
}
void Controller::actionModifyClass() {
	
	try {
		string subjCode;
		string smsterID;

		cout << "Digite o código da disciplina da turma que deseja modificar: ";
		cin >> subjCode;

		cout << endl;

		cout << "Digite o ID do semestre da turma que deseja modificar: ";
		cin >> smsterID;

		SemesterSubject classToUpdate(smsterID, subjCode);
		
		cout << endl;
		
		int option;

		cout << "Menu de Alterações:" << endl;
		cout << "(1) ID do semestre" << endl;
		cout << "(2) Ano do semestre" << endl;
		cout << "(3) Número do semestre" << endl;
		cout << "(4) Código da disciplina" << endl;
		cout << "(5) Nome da disciplina" << endl;
		cout << "Escolha uma das opções: ";
		cin >> option;

		ClassDAO classe;
		classe.update(option, classToUpdate);
		Utils::printMessage("Alteração feita com sucesso!");

	} catch(const exception& e) {
		Utils::printMessage("Erro ao modificar turma: " + string(e.what()));
	}
	
}
void Controller::actionDeleteClass() {
	try {
		string subjCode;
		string smsterID;

		cout << "Digite o código da disciplina da turma que deseja excluir: ";
		cin >> subjCode;

		cout << endl;

		cout << "Digite o ID do semestre da turma que deseja excluir: ";
		cin >> smsterID;

		SemesterSubject classToDelete(smsterID, subjCode);

		ClassDAO classe;
		classe.remove(classToDelete);
	} catch(const exception& e) {
		Utils::printMessage("Erro ao excluir turma: " + string(e.what()));

	}
}


//Relatory
void Controller::actionShowSubjectsStudent() {
// Disciplinas matriculadas por um estudante em ordem alfabética
    try {

		string RA;
		cout << "Digite o RA do estudante que deseja buscar: ";
		cin >> RA;

        StudentDAO studentDAO;
        shared_ptr<StudentDTO> studentPtr = studentDAO.search(RA);

        if (!studentPtr) {
            Utils::printMessage("Estudante não encontrado.");
        }

        map<string, set<string>>& subjects = studentPtr->getSubjects();

        vector<string> allSubjects;

        for (const auto& semester : subjects) {
            for (const auto& subject : semester.second) {
                allSubjects.push_back(subject);
            }
        }

        sort(allSubjects.begin(), allSubjects.end());

        cout << "Disciplinas matriculadas pelo estudante: " << endl;
		cout << studentPtr->getName() << " (RA: " << RA << ") em ordem alfabética:" << endl;
        for (const string& subject : allSubjects) {
            cout << subject << endl;
        }

    } catch (const exception& e) {
        Utils::printMessage("Erro ao mostrar informações: " + string(e.what()));
    }
}
void Controller::actionStudentSubjectInfo() {
// Estudantes matriculados em uma disciplina e suas respectivas notas
	try {
		string subjectCode;
		string semesterID;

		cout << "Digite o código da disciplina que deseja buscar: ";
		cin >> subjectCode;

		cout << endl;

		cout << "Digite o ID do semestre da disciplina que deseja buscar: ";
		cin >> semesterID;

		// Buscar a classe que tem a disciplina
		SemesterSubject classToFind(semesterID, subjectCode);
		ClassDAO classDAO;

		shared_ptr<ClassDTO> classPtr = classDAO.search(classToFind); 

		if(!classPtr) {
			Utils::printMessage("Classe não encontrada.");
			return;
		}

        map<string, double> studentGrades = classPtr->getStudentGrades();

        vector<pair<string, double>> students;

        for (const auto& entry : studentGrades) {
            students.push_back(entry);
        }

        sort(students.begin(), students.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
            return a.first < b.first;
        });
 
        cout << "Estudantes matriculados na disciplina " << classPtr->getName() << " (" << subjectCode << ") em ordem alfabética:" << endl;
        for (const auto& student : students) {
            cout << "RA: " << student.first << " | Nota: " << student.second << endl;
        }

    } catch (const exception& e) {
        Utils::printMessage("Erro ao mostrar informações: " + string(e.what()));
	}
}
void Controller::actionSubjectsTaughtByTeacher() {
// Disciplinas ministradas por um professor.
    try {
		string teacherId;
		cout << "Digite o ID do professor que deseja buscar: ";
		cin >> teacherId;

		TeacherDAO teacherDAO;
		shared_ptr<TeacherDTO> teacherPtr = teacherDAO.search(teacherId);

		if (!teacherPtr) {
			cout << "Professor com ID " << teacherId << " não encontrado." << endl;
			return;
		}

        vector<shared_ptr<ClassDTO>> classes = College::getClasses();
        vector<string> subjects;

		for (const auto& classPtr : classes) {
            if (classPtr->getTeacherId() == teacherId) {
                subjects.push_back(classPtr->getName());
            }
        }

        if (subjects.empty()) {
            cout << "O professor com ID " << teacherId << " não ministra nenhuma disciplina." << endl;
            return;
        }

        sort(subjects.begin(), subjects.end());

        cout << "Disciplinas ministradas pelo professor com ID " << teacherId << " em ordem alfabética:" << endl;
        for (const auto& subject : subjects) {
            cout << subject << endl;
        }

    } catch (const exception& e) {
        Utils::printMessage("Erro ao mostrar informações: " + string(e.what()));
    }
}
void Controller::actionSubjectAvgGrades() {
// Média de todas as notas de uma disciplina
	try {
		string subjectCode;
		string semesterID;

		cout << "Digite o código da disciplina da turma que deseja buscar: ";
		cin >> subjectCode;

		cout << endl;

		cout << "Digite o ID do semestre da disciplina que deseja buscar: ";
		cin >> semesterID;

		SemesterSubject classToFind(semesterID, subjectCode);
		ClassDAO classDAO;
		shared_ptr<ClassDTO> classeDTO = classDAO.search(classToFind); 

		if(!classeDTO) {
			Utils::printMessage("Classe não encontrada.");
		}
			
		map<string, double> studentGrades = classeDTO->getStudentGrades(); 

		if (studentGrades.empty()) {
			cout << "Nenhuma nota registrada para a disciplina " << subjectCode << "." << endl;
			return;
		}

		double sum = 0.0;
		for (auto& grade : studentGrades) {
			sum += grade.second;
		}

		double average = sum / studentGrades.size();
		
		cout << "A média das notas para a disciplina " << classeDTO->getName() << "é:  " << average << endl;
	} catch (const exception& e) {
        Utils::printMessage("Erro ao mostrar informações: " + string(e.what()));
    }
}
void Controller::actionStudentAvgGrades() {
// Média de todas as notas de um estudante
    try {
		string RA;
		cout << "Digite o RA do estudante que deseja buscar: ";
		cin >> RA;
		
		StudentDAO studentDAO;
		shared_ptr<StudentDTO> studentPtr = studentDAO.search(RA);

		if (!studentPtr) {
			cout << "Estudante não encontrado." << endl;
		}

		vector<double> studentGrades;
		
        auto& classes = College::getClasses();

        double totalSum = 0.0;
        int totalGradesCount = 0;

        for (const auto& classPtr : classes) {
           	map<string, double> grades = classPtr->getStudentGrades();

           	// Verifica se o estudante está matriculado na disciplina
        	if (grades.find(RA) != grades.end()) {
                double grade = grades[RA];
                studentGrades.push_back(grade);
                totalSum += grade;
                totalGradesCount++;
            }
        }

        // Verifica se o estudante possui notas registradas
        if (totalGradesCount == 0) {
            cout << "Nenhuma nota registrada para o estudante com RA " << RA << "." << endl;
            return;
        }

        double average = totalSum / totalGradesCount;

        cout << "A média das notas para o estudante com RA " << RA << " é: " << average << endl;

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

//Extra - Outro professor
/* void Controller::actionHelp(void) {
	Utils::printMessage(SysInfo::getVersion() + " | Help");
	actionToDo();
}

void Controller::actionAbout(void) {
	Utils::printMessage(SysInfo::getVersion() + " | About");
	actionToDo();
}
*/

void Controller::launchActions(string title, vector<string> menuItens,vector<void (Controller::*)()> functions) {
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
