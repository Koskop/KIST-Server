#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include "database.h"
#include "server.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  Server server(nullptr, 4567);
  server.start();

  return a.exec();
}
