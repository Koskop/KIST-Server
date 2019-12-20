#ifndef VIOLATION_H
#define VIOLATION_H

#include <QString>

class Violation
{
 public:
  Violation(unsigned int violationId, unsigned int violationKindId,
            unsigned int punishKindId, QString violationDate,
            unsigned int personId, unsigned int orderId);

  unsigned int getViolationId();
  unsigned int getViolationKindId();
  unsigned int getPunishKindId();
  QString getViolationDate();
  unsigned int getPersonId();
  unsigned int getOrderId();

 private:
  unsigned int violationId = 0;
  unsigned int violationKindId = 0;
  unsigned int punishKindId = 0;
  QString violationDate = "";
  unsigned int personId = 0;
  unsigned int orderId = 0;
};

#endif // VIOLATION_H
