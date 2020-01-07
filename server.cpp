#include "server.h"
#include <database.h>
#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <QJsonDocument>
#include <QNetworkInterface>

Server::Server(QObject *parent, quint16 serverPort) : QObject(parent) {
  this->setPort(serverPort);
  mTcpServer = new QTcpServer(this);

  connect(mTcpServer, &QTcpServer::newConnection, this,
          &Server::slotNewConnection);
  this->base.openConnection("CIST.sqlite3");
}

void Server::start() {
  if (!mTcpServer->listen(QHostAddress::Any, port)) {
    qDebug() << "Server is not started";
  } else {
    qDebug() << "Server is started";
    qDebug() << "Server IP: " << this->getIpAddress();
    qDebug() << "Server port: " << this->getPort();
  }
}

void Server::slotNewConnection() {
  mTcpSocket = mTcpServer->nextPendingConnection();
  qDebug() << "Someone connected";
  connect(mTcpSocket, &QTcpSocket::readyRead, this, &Server::slotServerRead);
  connect(mTcpSocket, &QTcpSocket::disconnected, this,
          &Server::slotClientDisconnected);
}

void Server::slotServerRead() {
  while (mTcpSocket->bytesAvailable() > 0) {
    QJsonDocument array = QJsonDocument::fromBinaryData(mTcpSocket->readAll());

    QByteArray responce;

    if (array[0][0] == "0") responce = this->getPesronsName();
    if (array[0][0] == "1")
      responce = this->getViolationByPersonId(array[0][1].toString().toUInt());
    if (array[0][0] == "2") responce = this->getCathedras();
    if (array[0][0] == "3")
      responce = this->getGroupAndSpecialityByCathedraId(
          array[0][1].toString().toUInt());
    if (array[0][0] == "4") responce = this->getStudentsName();
    if (array[0][0] == "5")
      responce = this->getStudentInfo(array[0][1].toString().toUInt());

    mTcpSocket->write(responce);
  }
}

void Server::slotClientDisconnected() { mTcpSocket->close(); }

void Server::setPort(quint16 p) { this->port = p; }

QByteArray Server::getPesronsName() {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
  int responceType = 0;
  int count = 0;
  for (auto a : base.getPersonsFullName()) {
    QJsonArray jsonArray;
    jsonArray.push_back(QString::number(a.getPersonId()));
    jsonArray.push_back(a.getFullName());
    jsonMainArray.push_back(jsonArray);
    count++;
  }
  jsonMainArray.push_front(count);
  jsonMainArray.push_front(responceType);
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toBinaryData();
}

QByteArray Server::getViolationByPersonId(unsigned int personId) {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
  int responceType = 1;
  int count = 0;
  for (auto a : base.getViolationByPersonId(personId)) {
    QJsonArray jsonArray;
    jsonArray.push_back(QString::number(a.getViolationId()));
    jsonArray.push_back(
        base.getSViolationKindById(a.getViolationId()).getViolationKindName());
    jsonArray.push_back(
        base.getSPunishKindById(a.getPunishKindId()).getPunishKindName());
    jsonArray.push_back(
        base.getSOrderKindById(
                base.getOrdersByOrdersId(a.getOrderId()).getOrderKindId())
            .getOrderKindName());
    jsonMainArray.push_back(jsonArray);
    count++;
  }
  jsonMainArray.push_front(count);
  jsonMainArray.push_front(responceType);
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toBinaryData();
}

QByteArray Server::getCathedras() {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
  int responceType = 2;
  int count = 0;
  for (auto a : base.getCathedrs()) {
    QJsonArray jsonArray;
    jsonArray.push_back(QString::number(a.getCathedraId()));
    jsonArray.push_back(a.getName());
    jsonMainArray.push_back(jsonArray);
    count++;
  }
  jsonMainArray.push_front(count);
  jsonMainArray.push_front(responceType);
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toBinaryData();
}

QByteArray Server::getGroupAndSpecialityByCathedraId(unsigned int cathedraId) {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
  int responceType = 0;
  int count = 0;
  for (auto a : base.getSpecialityByCathedrsId(cathedraId)) {
    for (auto b : base.getGroupsBySpecialityId(a.getSpecialityId())) {
      QJsonArray jsonArray;
      jsonArray.push_back(a.getSpecialityName());
      jsonArray.push_back(b.getGroupCode());
      jsonMainArray.push_back(jsonArray);
      count++;
    }
  }
  jsonMainArray.push_front(count);
  jsonMainArray.push_front(responceType);
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toBinaryData();
}

QByteArray Server::getStudentsName() {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
  int responceType = 4;
  int count = 0;
  for (auto a : base.getStudents()) {
    QJsonArray jsonArray;
    jsonArray.push_back(QString::number(a.getStudentId()));
    jsonArray.push_back(base.getStudentsNameByPersonId(a.getStudentId()));
    jsonMainArray.push_back(jsonArray);
    count++;
  }
  jsonMainArray.push_front(count);
  jsonMainArray.push_front(responceType);
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toBinaryData();
}

QByteArray Server::getStudentInfo(unsigned int personId) {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
  jsonMainArray.push_back(
      base.getStudentGroup(
              base.getStudentGroupByStudentId(personId).getGroupId())
          .getGroupCode());
  int responceType = 5;
  int count = 0;
  QJsonArray jsonArray;
  for (auto a : base.getStudentsMarksById(personId)) {
    jsonArray.push_back(base.getSMarkNyId(a.getmarkId()).getMarkName());
    count++;
  }
  jsonMainArray.push_front(count);
  jsonMainArray.push_front(responceType);
  jsonMainArray.push_back(jsonArray);
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toBinaryData();
}

QString Server::getIpAddress() {
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  // use the first non-localhost IPv4 address
  for (int i = 0; i < ipAddressesList.size(); ++i) {
    if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
        ipAddressesList.at(i).toIPv4Address()) {
      this->ipAddress = ipAddressesList.at(i).toString();
      break;
    }
  }
  // if we did not find one, use IPv4 localhost
  if (this->ipAddress.isEmpty())
    this->ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

  return this->ipAddress;
}

quint16 Server::getPort() { return this->port; }
