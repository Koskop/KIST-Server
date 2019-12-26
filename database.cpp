#include "database.h"
#include <QDebug>

DataBase::DataBase(QString dataBasePath) {
  this->sdb.setDatabaseName(dataBasePath);

  if (!this->sdb.open()) {
    qDebug() << this->sdb.lastError().text();
  } else {
    qDebug() << "Conected to data base!";
  }
}

QList<Person> DataBase::getPersonsFullName() {
  QList<Person> queryResult;
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM PERSON");
  if (!ok) qDebug() << query.lastError();

  while (query.next()) {
    Person tmp(
        query.value("Person_ID").toUInt(), query.value("Surname").toString(),
        query.value("Name").toString(), query.value("Patronymic").toString());
    queryResult.push_back(tmp);
  }
  return queryResult;
}

QList<Cathedra> DataBase::getCathedrs() {
  QList<Cathedra> queryResult;
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM CAFEDRA");
  if (!ok) qDebug() << query.lastError();

  while (query.next()) {
    Cathedra tmp(query.value("Cafedra_ID").toUInt(),
                 query.value("Cafedra_name").toString(),
                 query.value("Cafedra_shifr").toString());
    queryResult.push_back(tmp);
  }
  return queryResult;
}

DataBase::~DataBase() { this->sdb.close(); }
