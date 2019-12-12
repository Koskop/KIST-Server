#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  Server server(nullptr, 4567);

  server.start();

  return a.exec();
}
