#ifndef SORDERKIND_H
#define SORDERKIND_H

#include <QString>

class SOrderKind
{
 public:
  SOrderKind(unsigned int orderKindId, QString orderKindName);

  unsigned int getOrderKindId();
  QString getOrderKindName();

 private:
  unsigned int orderKindId = 0;
  QString orderKindName = "";
};

#endif // SORDERKIND_H
