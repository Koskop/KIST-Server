#include "sorderkind.h"

SOrderKind::SOrderKind(unsigned int orderKindId, QString orderKindName) {
  this->orderKindId = orderKindId;
  this->orderKindName = orderKindName;
}

unsigned int SOrderKind::getOrderKindId() { return this->orderKindId; }

QString SOrderKind::getOrderKindName() { return this->orderKindName; }
