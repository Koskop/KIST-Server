#include "studentgroup.h"

StudentGroup::StudentGroup(unsigned int groupId, unsigned int studentId,
                           QString puttingDate) {
  this->groupId = groupId;
  this->studentId = studentId;
  this->puttingDate = puttingDate;
}

unsigned int StudentGroup::getGroupId() { return this->groupId; }

unsigned int StudentGroup::getStudentId() { return this->studentId; }

QString StudentGroup::getPuttingDate() { return this->puttingDate; }
