#include "stabbing_line.h"

/** This file is created to test the function 
readlines to verify if the function is readinfg the texxt from the file
*/

int main()
{
    char filename[] = "inPutLineFile.txt";
    struct Line lArray[MAXXARRAYSIZE];
    const int MaxLnsSize = 8;
    readLines(filename, lArray, MaxLnsSize, 0);
    return 0;
}