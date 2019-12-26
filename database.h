#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
#include <QString>
#include <QtSql>
#include "tables.h"

class DataBase {
 public:
  DataBase();
  DataBase(QString dataBasePath);
  void openConnection(QString dataBasePath);
  ~DataBase();
  // first query
  QList<Person> getPersonsFullName();
  QList<Violation> getViolationByPersonId(unsigned int personId);
  Orders getOrdersByOrdersId(unsigned int ordersId);
  SViolationKind getSViolationKindById(unsigned int violationKindId);
  SPunishKind getSPunishKindById(unsigned int punishKindId);
  SOrderKind getSOrderKindById(unsigned int orderKindById);
  // second query
  QList<Cathedra> getCathedrs();
  // third query
  QList<Student> getStudents();
  QString getStudentsNameByPersonId(unsigned int personId);
  SMark getSMarkNyId(unsigned int markId);
  QList<StudentMark> getStudentsMarksById(unsigned int personId);
  StudentGroup getStudentGroupByStudentId(unsigned int personId);

 private:
  QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // DATABASE_H
