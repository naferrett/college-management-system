#include "../../include/dao/SubjectDAO.h"

using namespace std;

void SubjectDAO::add(const Subject& subject) {

    shared_ptr<Subject> ptrSubject = make_shared<Subject>(subject);

    College::getSubjects().push_back(ptrSubject);
}

void SubjectDAO::read() {

    vector<shared_ptr<Subject>>& subjVector = College::getSubjects();
    for (auto& it : subjVector) {
        cout << "Código: " << it->getCode() << " | Matéria: " << it->getName() << endl;
    }
}

shared_ptr<Subject> SubjectDAO::search(string studentRA) {
    return nullptr;
}
