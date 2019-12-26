#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
 public:
  Student(unsigned int studentId, QString bookNo, QString note);

  unsigned int getStudentId();
  QString getBookNo();
  QString getNote();

 private:
  unsigned int studentId = 0;
  QString bookNo = "";
  QString note = "";
};

#endif // STUDENT_H
