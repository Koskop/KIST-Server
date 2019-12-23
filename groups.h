#ifndef GROUPS_H
#define GROUPS_H

#include <QString>

class Groups
{
 public:
  Groups(unsigned int groupId, unsigned int specialityId, QString groupCode,
         QString groupCreateDate);

  unsigned int getGroupId();
  unsigned int getSpecialityId();
  QString getGroupCode();
  QString getGroupCreateDate();

 private:
  unsigned int groupId = 0;
  unsigned int specialityId = 0;
  QString groupCode = "";
  QString groupCreateDate = "";
};

#endif // GROUPS_H
