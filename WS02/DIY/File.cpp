//file.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace seneca {
    FILE* fptr;
   //FILE is a struct defined in the C standard library <cstdio> or <stdio.h (for C)>
   //FILE* is a pointer to a file struct and used to interact with files
   //fptr is a variable of type FILE* (points to file being accessed)

   //when a file is opened with fopen() it returns a FILE* that points to the file
        //if fopen() fails to open the file, fptr becomes a nullptr

   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

}