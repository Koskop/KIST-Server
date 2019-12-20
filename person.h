#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
 public:
  Person(unsigned int personId, QString surname, QString name,
         QString patronymic);
  Person(unsigned int personId, QString surname, QString name);

  unsigned int getPersonId();
  QString getSurname();
  QString getName();
  QString getPatronymic();

  QString getFullName();

 private:
  unsigned int personId = 0;
  QString surname = "";
  QString name = "";
  QString patronymic = "";
};

#endif // PERSON_H
