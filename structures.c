#include <stdio.h>


/* declare and define struct type */

struct database {
  int id_number;
  int age;
  float salary;
};
 
int main()
{
  struct database employee;  /* There is now an employee variable that has
                              modifiable variables inside it.*/
  employee.age = 22;
  employee.id_number = 1;
  employee.salary = 12000.21;


   printf("Employee age: %d\n", employee.age);
   printf("Employee ID: %d\n", employee.id_number);
   printf("Employee salary: %f\n", employee.salary);

}
