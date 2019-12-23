#include "groups.h"

Groups::Groups(unsigned int groupId, unsigned int specialityId,
               QString groupCode, QString groupCreateDate) {
  this->groupId = groupId;
  this->specialityId = specialityId;
  this->groupCode = groupCode;
  this->groupCreateDate = groupCreateDate;
}

unsigned int Groups::getGroupId() { return this->groupId; }

unsigned int Groups::getSpecialityId() { return this->specialityId; }

QString Groups::getGroupCode() { return this->groupCode; }

QString Groups::getGroupCreateDate() { return this->groupCreateDate; }
