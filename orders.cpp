#include "orders.h"

Orders::Orders(unsigned int orderId, unsigned int orderKindId,
               QString orderDate, unsigned int orderNo, QString orderText) {
  this->orderId = orderId;
  this->orderKindId = orderKindId;
  this->orderDate = orderDate;
  this->orderNo = orderNo;
  this->orderText = orderText;
}

unsigned int Orders::getOrderId() { return this->orderId; }

unsigned int Orders::getOrderKindId() { return this->orderKindId; }

QString Orders::getOrderDate() { return this->orderDate; }

unsigned int Orders::getOrderNo() { return this->orderNo; }

QString Orders::getOrderText() { return this->orderText; }
