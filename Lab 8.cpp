/* Michael Nana Kofi Ofori
   ICP Lab 8 C++
   Problem Description: Mapping a lower-triangular array onto consecutive linear
storage

*/
#include <iostream>
#include <tuple>
using namespace std;

int B[25];

int A[5][5];

int tempArray[2];

//LinearIndx() Function
int LinearIndx(int i, int j){
      int index = (((i*i)+i)/2) + j;
      return index;
}
// InverseIndx() Function
tuple<int, int> InverseIndx(int A[5][5], int I, int B[25]){
  for(int i = 0; i <6; i++ ){
    for(int j = 0; j < 6; j++){
        if (j<=i){
        int SeI = (((i*i)+i)/2) + j;
        if (SeI == I){
          tempArray[0] = i;
          tempArray[1] = j;
           return {tempArray[0], tempArray[1]};
          }
       }
    }
 }
  return {tempArray[0], tempArray[1]};
 }
int main()
     {
     for(int i = 0; i<6; i++){
      for(int j = 0; j < 6; j++){
      if(j <= i){
        A[i][j] = rand()%70;
      }
        else{
        A[i][j] = -1;
          }
       }
 }
      for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                    cout << A[i][j] << endl;
            }

          }
// first lower triangle first_lower[8][8]
int lowerArray1[8][8];
  for(int i = 0; i<8; i++){
    for(int j = 0; j < 8; j++){
       if(j <= i){
         lowerArray1[i][j] = rand()%1000;
     }
       else{
    lowerArray1[i][j] = -1;
     }
 }
  for(int t = 0; t < 1; t++){
     cout<< "Print out the first twenty elements of A[8][8] /n"<<endl;
  for(int l = 0; l < 20; l++){
  cout << A[t][l]<< endl;
   }
   }
  }
     for(int i = 0; i < 8; i++){
   for(int j = 0; j < 8; j++){
   cout << lowerArray1[i][j] << endl;
 }
}
// second_lower triangle second_lower[32][32]
int lowerArray2[32][32];
  for(int i = 0; i<32; i++){
    for(int j = 0; j < 32; j++){
     if(j <= i){
lowerArray2[i][j] = rand()%1000;
  }
else{
    lowerArray2[i][j] = -1;
   }
     }
    for(int t = 0; t < 1; t++){
   cout<< "Print out the first twenty elements of A[32][32]"<<endl;
     for(int l = 0; l < 20; l++){
        cout << A[t][l]<< endl;
          }
    }
   }
for(int i = 0; i < 32; i++){
  for(int j = 0; j < 32; j++){
    cout << lowerArray2[i][j] << endl;
      }
   }
 int lowerArray3[128][128];
    for(int i = 0; i<128; i++){
       for(int j = 0; j < 128; j++){
       if(j <= i){
           lowerArray3[i][j] = rand()%1000;
    }
else{
      lowerArray3[i][j] = -1;
     }
     }
     // to print out the first 20 elements of A[128][128]
     for(int t = 0; t < 1; t++){
     cout<< "Print out the first twenty elements of A[128][128]"<<endl;
  for(int l = 0; l < 20; l++){
      cout << A[t][l]<< endl;
      }
     }
    }
for(int i = 0; i < 128; i++){
   for(int j = 0; j < 128; j++){
    cout << lowerArray3[i][j] << endl;
    }
 }
      int m = 0;
    for ( int i = 0; i < 4; i++ )
      for ( int j = 0; j < i+1; j++ ) {
        B[m] = A[i][j];
         m++;

 }
      cout << "Linear Index function:"<<endl;
      cout << B[LinearIndx(3,2)] <<endl;
      cout << "Printing out the first 20 elements of B[]"<<endl;
      for(int i=0; i<20; i++)
       {
               cout<<B[i]<< " :   Indices ("<< i << ")" << endl;
       }


    return 0;
}
