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

  QByteArray getPesronsName();                                            // 0
  QByteArray getViolationByPersonId(unsigned int personId);               // 1
  QByteArray getCathedras();                                              // 2
  QByteArray getGroupAndSpecialityByCathedraId(unsigned int cathedraId);  // 3
  QByteArray getStudentsName();                                           // 4
  QByteArray getStudentInfo(unsigned int personId);                       // 5

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
