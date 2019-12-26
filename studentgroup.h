#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H

#include <QString>

class StudentGroup
{
 public:
  StudentGroup(unsigned int groupId, unsigned int studentId,
               QString puttingDate);

  unsigned int getGroupId();
  unsigned int getStudentId();
  QString getPuttingDate();

 private:
  unsigned int groupId = 0;
  unsigned int studentId = 0;
  QString puttingDate = "";
};

#endif // STUDENTGROUP_H
