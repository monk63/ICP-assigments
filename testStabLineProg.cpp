#include "stabbing_line.h"
int main()
{
    //basic file operation
    ifstream file;
    file.open("mergedFile.txt", ios::in);

    char ch;
    int number_of_lines = 0;
    int MaxLnsSize;
    while (!file.eof())
    {

        file.get(ch);
        if (ch == '\n')
        {
            ++number_of_lines;
        }
        if (ch == 'a')
        {
            MaxLnsSize = number_of_lines;
        }
    }
    cout << "MAX LINE: " << MaxLnsSize << endl;
    int MaxPnsSize = number_of_lines - MaxLnsSize;
    cout << "MAX POINT: " << MaxPnsSize << endl;

    file.close();

    struct Line linesArray[MaxLnsSize];
    int numLines = 0;
    int numPoints = 0;
    struct Point pointsArray[MaxPnsSize];

    FILE *fp = freopen("mergedFile.txt", "r", stdin);
    char cch;
    for (int i = 0; i < MaxLnsSize; i++)
    {
        cin >> linesArray[i].lid;
        cin >> linesArray[i].lx;
        cin >> linesArray[i].ly;
    }
    cin >> cch; 
    for (int i = 0; i < MaxPnsSize; i++)
    {
        cin >> pointsArray[i].pid;
        cin >> pointsArray[i].x;
        cin >> pointsArray[i].y;
    }
    fclose(fp);
    
    for (int i = 0; i < MaxPnsSize; i++)
    {
        cout << pointsArray[i].pid << " ";
        cout << pointsArray[i].x << " ";
        cout << pointsArray[i].y << " \n";
    }
    return 0;
}