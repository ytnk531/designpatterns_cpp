/*
 * adapter.cpp
 * http://www.techscore.com/tech/DesignPattern/Iterator/Iterator1.html/
 * IteratorパターンのC++による実装
 * 2016/06/02 Y.Tanaka
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum sex_t {male, female};

class Student {
 private:
  string name;
  sex_t sex;

 public:
  Student(){ }
  Student(string n, sex_t s){ name = n; sex = s; }
  string getName() { return name; }
  string getSex() {
    if (sex == male) {
      return "male";
    }
    if(sex == female) {
      return "female";
    }
    return "err";
  }
};

class StudentList {
 private:
  int last;

 protected:
  Student* students;

 public:
  StudentList(){}
  StudentList(int student_count){
    students = new Student[student_count];
    last = 0;
  }

  void add(Student student){
    students[last] = student;
    last++;
  }
  int getLastNum(){
    return last;
  }

  Student* getStudentAt(int n) {
    return &(students[n]);
  }
};

class NewStudentList{
 protected:
  vector<Student> students;
 public:
  void add(Student student){
    students.push_back(student);
  }
  Student* getStudentAt(int index){
    return &(students.at(index));
  }
  int getLastNum(){
    return (int)students.size();
  }
};

class Iterator{
 public:
  virtual ~Iterator(){}
  virtual bool hasNext() = 0;
  virtual void* next() = 0;
};

class Aggregate{
 public:
  virtual ~Aggregate(){}
  virtual Iterator* iterator() = 0;
};


class MyStudentList: public NewStudentList, public Aggregate {
 public:
  Iterator* iterator();
};

class MyStudentListIterator: public Iterator {
 private:
  MyStudentList* my_student_list;
  int index;

 public:
  MyStudentListIterator(MyStudentList* list):
    my_student_list(list),
    index(0)
  {
    my_student_list = list;
  }
  bool hasNext(){
    if(my_student_list->getLastNum() > index){
      return true;
    } else {
      return false;
    }
  }
  void* next(){
    Student* s = my_student_list->getStudentAt(index);
    index++;
    return (void*)s;
  }
};

Iterator* MyStudentList::iterator(){
  return new MyStudentListIterator(this);
}

class Teacher{
 protected:
  MyStudentList *studentlist;

 public:
  virtual ~Teacher(){}
  virtual void createStudentList() =0;
  virtual void callStudents() =0;
};

class MyTeacher: public Teacher {
 public:
  void createStudentList(){
    studentlist = new MyStudentList();
    studentlist->add(Student("赤井亮太", male));
    studentlist->add(Student("赤羽里美", female));
    studentlist->add(Student("岡田美央", female));
    studentlist->add(Student("西森俊介", male));
    studentlist->add(Student("中ノ森玲菜", female));
  }
  void callStudents(){
    Iterator* itr = studentlist->iterator();
    while(itr->hasNext()){
  // nextの返り値(void *)をStudent*にキャストして使う
    cout << ((Student *)itr->next())->getName()
      << endl;
    }
  }
};

int main() {
  Teacher *you = new MyTeacher();
  you->createStudentList();
  you->callStudents();
  delete you;
  return 0;
}
