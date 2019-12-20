#include "cathedra.h"

Cathedra::Cathedra(unsigned int cathedraId, QString name,
                   QString abbreviation) {
  this->cathedraId = cathedraId;
  this->name = name;
  this->abbreviation = abbreviation;
}

unsigned int Cathedra::getCathedraId() { return this->cathedraId; }

QString Cathedra::getName() { return this->name; }

QString Cathedra::getAbbreviation() { return this->abbreviation; }
