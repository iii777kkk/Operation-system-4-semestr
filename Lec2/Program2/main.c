#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;

int main() 
{
	int sz; 
	//количество прочитанных байт
  
	char* c = (char*)calloc(100, sizeof(char));
  //динамический массив размером 100 байт
  

	int fd = open("foo.txt", O_RDONLY | O_CREAT);
  // открываем файл для чтения и при необходимости создания

	printf("fd = %d/n", fd);
  // выводим на экран значение дескриптора файла
  
	if (fd == -1)
	{
	
		printf("Error Number % d\n", errno);
   	// выводим код ошибки последнего системного вызова
	
		perror("open file error:");
    // выводим на экран текстовое описание ошибки
	}
	sz = read(fd, c, 10);
  //читаем из файла 10 байт
  
	printf("called read(% d, c, 10). returned that"
		" %d bytes were read.\n", fd, sz);
  //в sz хранится количество байт, которое удалось прочитать из файла

	c[sz] = '\0';
  //записываем в конец массива символ конца строки

	if (close(fd) < 0) 	//закрываем файл
	{
		perror("close file error:");
		exit(1);
	}
	printf("closed the fd.\n");
	return 0;
}
