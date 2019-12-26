#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
#include <QString>
#include <QtSql>
#include "tables.h"

class DataBase {
 public:
  DataBase(QString dataBasePath);
  ~DataBase();
  // first query
  QList<Person> getPersonsFullName();
  QList<Violation> getViolationByPersonId(unsigned int personId);
  SViolationKind getSViolationKindById(unsigned int violationKindId);

  // second query
  QList<Cathedra> getCathedrs();
  // third query

 private:
  QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // DATABASE_H
