#ifndef FILEDB_H_
#define FILEDB_H_

struct Person {
  char name[40];
  int age;
  float salary;
};

class BinaryFileIO
{
public:
    bool Import(const char *file_name);
    bool Export(const char *file_name);

    void Display(void);

    void SetPersonName(std::string str, int length);
    void SetAge(int value);
    void SetSalary(float value);

private:
    struct Person person_info;
};

#endif /* FILEDB_H_ */
