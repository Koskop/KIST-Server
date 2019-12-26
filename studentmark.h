#ifndef STUDENTMARK_H
#define STUDENTMARK_H


class StudentMark
{
 public:
  StudentMark(unsigned int studentId, unsigned int markId);

  unsigned int getStudentId();
  unsigned int getmarkId();

 private:
  unsigned int studentId = 0;
  unsigned int markId = 0;
};

#endif // STUDENTMARK_H
