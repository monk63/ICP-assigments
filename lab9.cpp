#include <iostream>
#include<iomanip>
#include <ctime> // For time()
#include <cstdlib>  // For srand() and rand() 
using namespace std;


/*void populateArray(){

    int i,j;
    int A[101][101];
int **ptr = new int *[i];
      for(int i = 0; i<101; i++)
    {
        ptr[i] = new int[101];
    }
    srand(time(0));

    for(int j = 0; j<101; j++)
    {
        for(int k = 0; k<101; k++)
        {
            int a = rand()%10;
            ptr[j][k] = a;
            cout<<ptr[j][k]<<" ";
        }
    
        cout<<endl; 
    }   

}

*/
int main(){
    int i,j;
    int A[101][101];
   // int count=0;

    // populateArray();
      //return 0;
    

  //
 int populateArray(int i);
int **ptr = new int *[i];
      for(int i = 0; i<101; i++)
    {
        ptr[i] = new int[101];
    }
    srand(time(0));

    for(int j = 0; j<101; j++)
    {
        for(int k = 0; k<101; k++)
        {
            // rand()%10 restricts the random number to a range of 0-10.
            int a = rand()%10;
            ptr[j][k] = a;
            cout<<ptr[j][k]<<" ";
        }

  /*  int searchValidEntries()  {
        
    }  
    */
        cout<<endl; 
    }   

    
}
