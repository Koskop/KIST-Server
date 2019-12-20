#ifndef CATHEDRA_H
#define CATHEDRA_H

#include <QString>

class Cathedra
{
 public:
  Cathedra(unsigned int cathedraId, QString name, QString abbreviation);

  unsigned int getCathedraId();
  QString getName();
  QString getAbbreviation();

 private:
  unsigned int cathedraId = 0;
  QString name = "";
  QString abbreviation = "";
};

#endif // CATHEDRA_H
