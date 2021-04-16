#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#define MAXXARRAYSIZE 500
#define endl "\n"
#define fastIo                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

typedef int PointId;
typedef int LineId;

struct Point
{
    PointId pid;
    int x;
    int y;
};
struct Line
{
    LineId lid;
    PointId lx;
    PointId ly;
};
using namespace std;

// Declaring the prototype functions

void readPoints(char *inPutPointFile, Point pointsArray[], const int MaxPntsSize, int numPoints)
{
  
    cout << "Reading Points from File..." << endl;
    FILE *fp = freopen(inPutPointFile, "r", stdin);
    while (!feof(fp))
    {
        cin >> pointsArray[numPoints].pid;
        cout << pointsArray[numPoints].pid << " ";
        cin >> pointsArray[numPoints].x;
        cout << pointsArray[numPoints].x << " ";
        cin >> pointsArray[numPoints].y;
        cout << pointsArray[numPoints].y << " \n";
        numPoints++;
    }
    fclose(fp);
    cout << endl;
}

void readLines(char *inPutLineFile, Line linesArray[], const int MaxLnsSize, int numLines)
{
    
    cout << "Reading Lines from File..." << endl;
    FILE *fp = freopen(inPutLineFile, "r", stdin);
    while (!feof(fp))
    {
        cin >> linesArray[numLines].lid;
        cout << linesArray[numLines].lid << " ";
        cin >> linesArray[numLines].lx;
        cout << linesArray[numLines].lx << " ";
        cin >> linesArray[numLines].ly;
        cout << linesArray[numLines].ly << " \n";
        numLines++;
    }
    fclose(fp);
    cout << endl;
}