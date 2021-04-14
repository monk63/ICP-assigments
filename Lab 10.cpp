include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#define MAXARRAYSIZE 500
using namespace std ;
typedef int PointId ;
typedef int LineId ;
struct Point { //define a Point struct
PointId Pid; // Point Id
int ... ; // x-coordinate of a point
int ... ; // y-coordinate of a point
};
2”stabbingLines.h.” continued
struct Line { // define a Line by its 2 End points
LineId Lid ; // Line Id
PointId ... ; // first Point
PointId ... ; // second Point
};
// Declaring the prototype functions
void readPoints(ifstream& inPutPointFile, Point pointsArray[],
const int MaxPntsSize, int& numPoints);
void readLines(ifstream& inPutLineFile, Line linesArray[],
const int MaxLnsSize, int& numLines);
void printLineByCoords(LineId lid, Line linesArray[], const
int MaxLnsSize, Point pointsArray[], const int MaxPntsSize);
void getStabbedLines (const int xcoord, Line linesArray[], const
int MaxLnsSize, const int NumLines, Point pointsArray[],
const int MaxPtsSize, Line stabbedLines[],
const int MaxStbSize, int& NumOfStbLines);
