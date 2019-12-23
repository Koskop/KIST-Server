#ifndef SVIOLATIONKIND_H
#define SVIOLATIONKIND_H

#include <QString>

class SViolationKind
{
 public:
  SViolationKind(unsigned int violationKindId, QString violationKindName);

  unsigned int getViolationKindId();
  QString getViolationKindName();

 private:
  unsigned int violationKindId = 0;
  QString violationKindName = "";
};

#endif // SVIOLATIONKIND_H
