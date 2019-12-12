#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject {
  Q_OBJECT
 public:
  explicit Server(QObject *parent = nullptr);

  // setters
  void setPort(quint16 p);

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
};

#endif  // SERVER_H
