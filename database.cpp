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

QList<Violation> DataBase::getViolationByPersonId(unsigned int personId) {
  QList<Violation> queryResult;
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM VIOLATION WHERE Person_ID = '" +
                       QString::number(personId) + "'");
  if (!ok) qDebug() << query.lastError();

  while (query.next()) {
    Violation tmp(query.value("Violation_ID").toUInt(),
                  query.value("Violation_kind_ID").toUInt(),
                  query.value("Punish_kind_ID").toUInt(),
                  query.value("Violation_date").toString(),
                  query.value("Person_ID").toUInt(),
                  query.value("Order_ID").toUInt());
    queryResult.push_back(tmp);
  }
  return queryResult;
}

SViolationKind DataBase::getSViolationKindById(unsigned int violationKindId) {
  QSqlQuery query(sdb);
  bool ok =
      query.exec("SELECT * FROM SVIOLATION_KIND WHERE Violation_kind_ID = '" +
                 QString::number(violationKindId) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();
  SViolationKind queryResult(query.value("Violation_kind_ID").toUInt(),
                             query.value("Violation_kind_name").toString());
  return queryResult;
}

SPunishKind DataBase::getSPunishKindById(unsigned int violationKindId) {
  QSqlQuery query(sdb);
  bool ok =
      query.exec("SELECT * FROM SVIOLATION_KIND WHERE Punish_kind_ID = '" +
                 QString::number(violationKindId) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();
  SPunishKind queryResult(query.value("Punish_kind_ID").toUInt(),
                          query.value("Punish_kind_name").toString());
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
