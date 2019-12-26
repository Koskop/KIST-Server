#ifndef SMARK_H
#define SMARK_H

#include <QString>

class SMark
{
 public:
  SMark(unsigned int markId, QString markName);

  unsigned int getMarkId();
  QString getMarkName();

 private:
  unsigned int markId;
  QString markName;
};

#endif // SMARK_H
