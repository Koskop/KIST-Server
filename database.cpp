#include "database.h"
#include <QDebug>

DataBase::DataBase(QString dataBasePath) {
  this->sdb.setDatabaseName(dataBasePath);

  if (!this->sdb.open()) {
    qDebug() << this->sdb.lastError().text();
  }
}

DataBase::~DataBase() { this->sdb.close(); }
