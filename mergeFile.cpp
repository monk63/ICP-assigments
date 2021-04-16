#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
int main()
{
    char ch;
    fstream fpsOne, fpsTwo, fpTarget;
    char fileOne[] = "inPutLineFile.txt";
    char fileTwo[] = "inPutPointFile.txt";
    fpsOne.open(fileOne, fstream::in);
    fpsTwo.open(fileTwo, fstream::in);
    if ((!fpsOne) || (!fpsTwo))
    {
        cout << "Error";
        return 0;
    }
    else
    {
        char fileTarget[] = "mergedFile.txt";
        fpTarget.open(fileTarget, fstream::out);
        if (!fpTarget)
            printf("Error");
        else
        {
            while (fpsOne >> noskipws >> ch)
                fpTarget << ch;
            fpTarget << "\na\n";
            while (fpsTwo >> noskipws >> ch)
                fpTarget << ch;
            cout << "File Merged Successfully";
        }
    }
    fpsOne.close();
    fpsTwo.close();
    fpTarget.close();
    cout << endl;
    return 0;
}