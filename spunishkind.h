#ifndef SPUNISHKIND_H
#define SPUNISHKIND_H

#include <QString>

class SPunishKind
{
 public:
  SPunishKind(unsigned int punishKindId, QString punishKindName);

  unsigned getPunishKindId();
  QString getPunishKindName();

 private:
  unsigned int punishKindId = 0;
  QString punishKindName = "";
};

#endif // SPUNISHKIND_H
