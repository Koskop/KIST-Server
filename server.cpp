#include "server.h"
#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <QNetworkInterface>

Server::Server(QObject *parent) : QObject(parent) {
  this->port = 6000;
  mTcpServer = new QTcpServer(this);

  connect(mTcpServer, &QTcpServer::newConnection, this,
          &Server::slotNewConnection);

  if (!mTcpServer->listen(QHostAddress::Any, port)) {
    qDebug() << "Server is not started";
  } else {
    qDebug() << "Server is started";
    qDebug() << "Server IP: " << this->getIpAddress();
    qDebug() << "Server port: " << this->port;
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
    qDebug() << "Date: " << QDateTime::currentDateTime().toString() << "\n"
             << "Message:" << array;

    mTcpSocket->write(array);
  }
}

void Server::slotClientDisconnected() { mTcpSocket->close(); }

void Server::setPort(quint16 p) { this->port = p; }

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
