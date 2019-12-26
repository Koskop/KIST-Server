#ifndef SERVER_H
#define SERVER_H

#include <database.h>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject {
  Q_OBJECT
 public:
  explicit Server(QObject *parent = nullptr, quint16 serverPort = 6000);

  // methods
  void start();

  // setters
  void setPort(quint16 p);

  QByteArray getPesronsName();

  // getters
  QString getIpAddress();
  quint16 getPort();

 public slots:
  void slotNewConnection();
  void slotServerRead();
  void slotClientDisconnected();

 private:
  QTcpServer *mTcpServer;
  QTcpSocket *mTcpSocket;

  // variables
  QString ipAddress;
  quint16 port;
  DataBase base;
};

#endif  // SERVER_H
