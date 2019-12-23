#include "speciality.h"

Speciality::Speciality(unsigned int specialityId, unsigned int cathedraId,
                       QString specialityName, QString specialityShifr) {
  this->specialityId = specialityId;
  this->cathedraId = cathedraId;
  this->specialityName = specialityName;
  this->specialityShifr = specialityShifr;
}

unsigned int Speciality::getSpecialityId() { return this->specialityId; }

unsigned int Speciality::getCathedraId() { return this->cathedraId; }

QString Speciality::getSpecialityName() { return this->specialityName; }

QString Speciality::getSpecialityShifr() { return specialityShifr; }
