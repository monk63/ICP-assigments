#include "stabbing_line.h"
/* File is created to test whether the function readPoints
*  is reading the points from the file.
*/

int main()
{
    char filename[] = "inPutPointFile.txt";
    struct Point pArray[MAXXARRAYSIZE];
    const int MaxPnsSize = 8;
    readPoints(filename, pArray, MaxPnsSize, 0);

    
    return 0;
}