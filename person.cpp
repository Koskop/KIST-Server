#include "person.h"

Person::Person(unsigned int personId, QString surname, QString name,
               QString patronymic) {
  this->personId = personId;
  this->surname = surname;
  this->name = name;
  this->patronymic = patronymic;
}

Person::Person(unsigned int personId, QString surname, QString name) {
  this->personId = personId;
  this->surname = surname;
  this->name = name;
  this->patronymic = "";
}

unsigned int Person::getPersonId() { return this->personId; }
QString Person::getSurname() { return this->surname; }
QString Person::getName() { return this->name; }
QString Person::getPatronymic() { return this->patronymic; }

QString Person::getFullName() {
  if (this->patronymic != "")
    return this->surname + " " + this->name + " " + this->patronymic;
  else
    return this->surname + " " + this->name;
}
