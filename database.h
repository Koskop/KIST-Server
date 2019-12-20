#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QtSql>

class DataBase {
 public:
  DataBase(QString dataBasePath);
  ~DataBase();

 private:
  QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // DATABASE_H
