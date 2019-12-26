#include "studentmark.h"

StudentMark::StudentMark(unsigned int studentId, unsigned int markId) {
  this->studentId = studentId;
  this->markId = markId;
}

unsigned int StudentMark::getStudentId() { return this->studentId; }

unsigned int StudentMark::getmarkId() { return this->markId; }
