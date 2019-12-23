#include "sviolationkind.h"

SViolationKind::SViolationKind(unsigned int violationKindId,
                               QString violationKindName) {
  this->violationKindId = violationKindId;
  this->violationKindName = violationKindName;
}

unsigned int SViolationKind::getViolationKindId() {
  return this->violationKindId;
}

QString SViolationKind::getViolationKindName() {
  return this->violationKindName;
}
