#ifndef CreateFile_H
#define CreateFile_H
#include "insert.h"

int ListFile();
void saveToFile(char arr[MAX_ROWS][MAX_COLUMNS]);
int remove_file(char nama_file_temp[30]);
void delete_file();
void rename_file();
int modify(char arr[MAX_ROWS][MAX_COLUMNS]);

int duplicate();
int jumlah_kata();

#endif
