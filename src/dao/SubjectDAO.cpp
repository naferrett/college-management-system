#include "../../include/dao/SubjectDAO.h"

using namespace std;

void SubjectDAO::add(const Subject& subject) {

    shared_ptr<Subject> ptrSubject = make_shared<Subject>(subject);

    College::getSubjects().push_back(ptrSubject);
}