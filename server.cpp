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

  mTcpSocket->write("Hello, World!!! I am echo server!\r\n");

  connect(mTcpSocket, &QTcpSocket::readyRead, this, &Server::slotServerRead);
  connect(mTcpSocket, &QTcpSocket::disconnected, this,
          &Server::slotClientDisconnected);
}

void Server::slotServerRead() {
  while (mTcpSocket->bytesAvailable() > 0) {
    QByteArray array = mTcpSocket->readAll();
    qDebug() << array;
    QJsonDocument request;

    QByteArray responce;
    responce = array;
    request.fromJson(array);

    // 1
    //    responce = this->getPesronsName();
    //    responce = this->getViolationByPersonId(9);
    // 2

    // 3
    //    responce = this->getStudentsName();

    //    request = QJsonDocument::fromJson(responce);
    //    qDebug() << request[0][0];
    mTcpSocket->write(responce);
  }
}

void Server::slotClientDisconnected() { mTcpSocket->close(); }

void Server::setPort(quint16 p) { this->port = p; }

QByteArray Server::getPesronsName() {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
  for (auto a : base.getPersonsFullName()) {
    QJsonArray jsonArray;
    jsonArray.push_back(QString::number(a.getPersonId()));
    jsonArray.push_back(a.getFullName());
    jsonMainArray.push_back(jsonArray);
  }
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toJson();
}

QByteArray Server::getViolationByPersonId(unsigned int personId) {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
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
  }
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toJson();
}

QByteArray Server::getStudentsName() {
  QJsonDocument jsonDoc;
  QJsonArray jsonMainArray;
  for (auto a : base.getStudents()) {
    QJsonArray jsonArray;
    jsonArray.push_back(QString::number(a.getStudentId()));
    jsonArray.push_back(base.getStudentsNameByPersonId(a.getStudentId()));
    jsonMainArray.push_back(jsonArray);
  }
  jsonDoc.setArray(jsonMainArray);
  qDebug() << jsonDoc;
  return jsonDoc.toJson();
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
