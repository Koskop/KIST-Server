#ifndef SPECIALITY_H
#define SPECIALITY_H

#include <QString>

class Speciality
{
 public:
  Speciality(unsigned int specialityId, unsigned int cathedraId,
             QString specialityName, QString specialityShifr);

  unsigned int getSpecialityId();
  unsigned int getCathedraId();
  QString getSpecialityName();
  QString getSpecialityShifr();

 private:
  unsigned int specialityId = 0;
  unsigned int cathedraId = 0;
  QString specialityName = "";
  QString specialityShifr = "";
};

#endif // SPECIALITY_H
