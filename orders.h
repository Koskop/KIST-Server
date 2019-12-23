#ifndef ORDERS_H
#define ORDERS_H

#include <QString>

class Orders
{
 public:
  Orders(unsigned int orderId, unsigned int orderKindId, QString orderDate,
         unsigned int orderNo, QString orderText);

  unsigned int getOrderId();
  unsigned int getOrderKindId();
  QString getOrderDate();
  unsigned int getOrderNo();
  QString getOrderText();

 private:
  unsigned int orderId = 0;
  unsigned int orderKindId = 0;
  QString orderDate = "";
  unsigned int orderNo = 0;
  QString orderText = "";
};

#endif // ORDERS_H
