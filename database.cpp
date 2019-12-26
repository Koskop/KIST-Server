#include "database.h"
#include <QDebug>

DataBase::DataBase() {}

DataBase::DataBase(QString dataBasePath) {
  this->sdb.setDatabaseName(dataBasePath);

  if (!this->sdb.open()) {
    qDebug() << this->sdb.lastError().text();
  } else {
    qDebug() << "Conected to data base!";
  }
}

void DataBase::openConnection(QString dataBasePath) {
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

Orders DataBase::getOrdersByOrdersId(unsigned int ordersId) {
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM ORDERS WHERE Order_ID = '" +
                       QString::number(ordersId) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();
  Orders queryResult(
      query.value("Order_ID").toUInt(), query.value("Order_kind_ID").toUInt(),
      query.value("Order_date").toString(), query.value("Order_no").toUInt(),
      query.value("Order_text").toString());
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

SPunishKind DataBase::getSPunishKindById(unsigned int punishKindId) {
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM SPUNISH_KIND WHERE Punish_kind_ID = '" +
                       QString::number(punishKindId) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();
  SPunishKind queryResult(query.value("Punish_kind_ID").toUInt(),
                          query.value("Punish_kind_name").toString());
  return queryResult;
}

SOrderKind DataBase::getSOrderKindById(unsigned int orderKindById) {
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM SORDER_KIND WHERE Order_kind_ID = '" +
                       QString::number(orderKindById) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();
  SOrderKind queryResult(query.value("Order_kind_ID").toUInt(),
                         query.value("Order_kind_name").toString());
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

QList<Student> DataBase::getStudents() {
  QList<Student> queryResult;
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM STUDENT");
  if (!ok) qDebug() << query.lastError();

  while (query.next()) {
    Student tmp(query.value("Student_ID").toUInt(),
                query.value("Book_no").toString(),
                query.value("Note").toString());
    queryResult.push_back(tmp);
  }
  return queryResult;
}

QString DataBase::getStudentsNameByPersonId(unsigned int personId) {
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM PERSON WHERE Person_ID = '" +
                       QString::number(personId) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();

  return query.value("Surname").toString() + " " +
         query.value("Name").toString() + " " +
         query.value("Patronymic").toString();
}

SMark DataBase::getSMarkNyId(unsigned int markId) {
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM SMARK WHERE Mark_ID = '" +
                       QString::number(markId) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();
  SMark queryResult(query.value("Mark_ID").toUInt(),
                    query.value("Mark_name").toString());
  return queryResult;
}

QList<StudentMark> DataBase::getStudentsMarksById(unsigned int personId) {
  QList<StudentMark> queryResult;
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT *h FROM STUDENT_MARKS WHERE Student_ID = '" +
                       QString::number(personId) + "'");
  if (!ok) qDebug() << query.lastError();

  while (query.next()) {
    StudentMark tmp(query.value("Student_ID").toUInt(),
                    query.value("Mark_ID").toUInt());
    queryResult.push_back(tmp);
  }
  return queryResult;
}

StudentGroup DataBase::getStudentGroupByStudentId(unsigned int studentId) {
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM STUDENT_GROUP WHERE Student_ID = '" +
                       QString::number(studentId) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();
  StudentGroup queryResult(query.value("Group_ID").toUInt(),
                           query.value("Student_ID").toUInt(),
                           query.value("Putting_date").toString());
  return queryResult;
}

Groups DataBase::getStudentGroup(unsigned int groupID) {
  QSqlQuery query(sdb);
  bool ok = query.exec("SELECT * FROM GROUPS WHERE Group_ID = '" +
                       QString::number(groupID) + "'");
  if (!ok) qDebug() << query.lastError();
  query.next();
  Groups queryResult(query.value("Group_ID").toUInt(),
                     query.value("Speciality_ID").toUInt(),
                     query.value("Group_code").toString(),
                     query.value("Groupe_creat_date").toString());
  return queryResult;
}

DataBase::~DataBase() { this->sdb.close(); }
