#include "smark.h"

SMark::SMark(unsigned int markId, QString markName) {
  this->markId = markId;
  this->markName = markName;
}

unsigned int SMark::getMarkId() { return this->markId; }

QString SMark::getMarkName() { return this->markName; }
