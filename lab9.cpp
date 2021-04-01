/*  Michael Ofori
    Dickson Akubia
    Lab 9 Assignment
*/

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define endl "\n"
#define fastIo                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
int A[101][101];
void seachValidEntries(int xl, int yl, int xm, int ym)
{
    int count = 0;
    for (int i = xl; i < xm; i++)
    {
        for (int j = yl; j < ym; j++)
        {
            if (A[i][j] >= 1)

            {
                count++;
                printf("%2d, %2d; %2d \n", i, j, A[i][j]);
            }
        }
    }
    cout << "\nTotal entries in Bounded Box:" << ((xm - xl) * (ym - yl)) << endl;
    cout << "Total valid Entries: " << count << endl
         << endl;
}
void populateArray(int N)
{
    srand((unsigned)time(NULL));
    for (int i{}; i < N; i++)
    {
        int p = 0 + (rand() % 100);
        int q = 0 + (rand() % 100);
        if (A[p][q] == -1)
        {
            A[p][q] = 1;
        }
        else if (A[p][q] >= 1)
        {
            A[p][q] += 1;
        }
       //  cout << p << " " << q << endl;
    }
}
void printArray(int xl, int yl, int xm, int ym)
{
    for (int i = xl; i < xm; i++)
    {
        for (int j = yl; j < ym; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    
    memset(A, -1, sizeof(A));
    int N = 2000;
    populateArray(N);
    int n;
    cout << "Input the no. of Bounded Boxes:";
    cin >> n;
    while (n--)
    {
        int xl, xm, yl, ym;
        //cout << "Input  Lower X axis:";
        cin >> xl;
        //cout << "Input  Lower Y axis:";
        cin >> yl;
        //cout << "Input Higher X axis:";
        cin >> xm;
        //cout << "Input Higher Y axis:";
        cin >> ym;
        if (xm < xl || ym < yl)
        {
            cout << "This box can't be possible" << endl;
            break;
            return 0;
        }
        
         printArray(xl, yl, xm, ym);
          cout<<endl;
        seachValidEntries(xl, yl, xm, ym);
    }
    return 0;
}
//input

/*
5
80 1 100 10
10 20 40 79
1 90 100 100
40 30 70 60
50 50 70 70
*/
