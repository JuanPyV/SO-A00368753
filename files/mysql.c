#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct full_student {
  char firstName[20];
  char lastName[20];
  int prisionerId;
  char semester;
} Student;

void writeStudent(int argc, char **argv) {
  char *fileName = argv[1];
  int fd = open(fileName, O_WRONLY | O_CREAT, 0666);
  for (int i = 0; i < 5; i++) {
    Student myStudent;
    sprintf(myStudent.firstName, "Juanito_%d", i);
    sprintf(myStudent.lastName, "Perez_%d", i);
    myStudent.prisionerId = (i + 1) * 10;
    myStudent.semester = (i + 1);
    write(fd, &myStudent, sizeof(Student));
  }
  close(fd);
}

void readStudent(int argc, char **argv) {
  char *fileName = argv[1];
  int fd = open(fileName, O_RDONLY);
  Student myStudent;
  int element = atoi(argv[2]);
  lseek(fd, element * sizeof(Student), SEEK_SET);
  read(fd, &myStudent, sizeof(Student));
  close(fd);
  printf("Student name: %s %s\n", myStudent.firstName, myStudent.lastName);
  printf("Id: %d, Semester: %d", myStudent.prisionerId, myStudent.semester);
}

int main(int argc, char **argv) {
  char *fileName = argv[1];
  char *lastName = argv[2];
  char *newLastName = argv[3];
  int fd = open(fileName, O_RDONLY);
  int posElement = -1;
  for (int i = 0; i < 5; i++) {
    Student myStudent;
    read(fd, &myStudent, sizeof(Student));
    if (!strcmp(myStudent.lastName, lastName)) {
      posElement = i;
      printf("Ya lo encontre, es: %s %s \n", myStudent.firstName,
             myStudent.lastName);
      break;
    }
  }
  close(fd);
  if (posElement == -1) {
    printf("Valor no encontrado \n");
  } else {
    Student myStudent;
    int lastNameMaxSize = size(myStudent.lastName);
    char trunLastName [20];
    strncpy(trunLastName, newLastName, 20);
    int fd = open(fileName, O_WRONLY);
    lseek(fd, posElement * sizeof(Student) + sizeof(myStudent.firstName),
          SEEK_SET);
    write(fd, newLastName, strlen(trunLastName));
    close(fd);
  }
}