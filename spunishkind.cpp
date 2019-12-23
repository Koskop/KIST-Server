#include "spunishkind.h"

SPunishKind::SPunishKind(unsigned int punishKindId, QString punishKindName) {
  this->punishKindId = punishKindId;
  this->punishKindName = punishKindName;
}

unsigned int SPunishKind::getPunishKindName() { return this->punishKindId; }

QString SPunishKind::getPunishKindName() { return this->punishKindName; }
