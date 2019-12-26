#include "student.h"

Student::Student(unsigned int studentId, QString bookNo, QString note) {
  this->studentId = studentId;
  this->bookNo = bookNo;
  this->note = note;
}

unsigned int Student::getStudentId() { return this->studentId; }

QString Student::getBookNo() { return this->bookNo; }

QString Student::getNote() { return this->note; }
