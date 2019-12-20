#include "violation.h"

Violation::Violation(unsigned int violationId, unsigned int violationKindId,
                     unsigned int punishKindId, QString violationDate,
                     unsigned int personId, unsigned int orderId) {
  this->violationId = violationId;
  this->violationKindId = violationKindId;
  this->punishKindId = punishKindId;
  this->violationDate = violationDate;
  this->personId = personId;
  this->orderId = orderId;
}

unsigned int Violation::getViolationId() { return this->violationId; }

unsigned int Violation::getViolationKindId() { return this->violationKindId; }

unsigned int Violation::getPunishKindId() { return this->punishKindId; }

QString Violation::getViolationDate() { return this->violationDate; }

unsigned int Violation::getPersonId() { return this->personId; }

unsigned int Violation::getOrderId() { return this->orderId; }
