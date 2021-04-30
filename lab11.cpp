/*
 Michael Nana Kofi ofori
 Dickson Akubia Etornam
 Lab 11/Project
 ICP
 
 */ 

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h>
#define MAXX 1000

using namespace std;


// Rect block class
class RectBlocks
{
public:
      // Dimensions of the rectangle
    int width, length, height;
    RectBlocks()
    {
        // Intializing the dimensions to 0.
        this->length = 0;
        this->width = 0;
        this->height = 0;
    }

    // Printing the assigned shape dimensions.
    void display()
    {
        cout << "Width: " << width << " Height: " << height << " Length: " << length << endl;
    }
   ~RectBlocks() {}  //destructor 
};
// Square base rect block class
class SqrBaseRectBlock : public RectBlocks
{
  
};

// Cuboid blocks

class CuboidBlocks : public SqrBaseRectBlock
{
};

// cylinder blocks class
class CylindricalBlocks : public SqrBaseRectBlock
{
     public:
     float diameter,width,area;
     void display_cylinder()
     {
         cout << "Diameter: "<< diameter << " Width: "<<width<< " Area: " <<area << endl;
     } 
};
// Looping to identify the dimension os square base block.
     void print_sphere_list(list<SqrBaseRectBlock> listParam)
     {
         list<SqrBaseRectBlock>::iterator listItr;
         printf("\nObjects of Sqr base rect blocks are:\n");
          for (listItr = listParam.begin(); listItr != listParam.end(); listItr++)
    {
        (*listItr).display();
    }
}
// Looping to identify the dimension of cylindrical block
     void print_cylinder_list(list<CylindricalBlocks> listParam)
{
    list<CylindricalBlocks>::iterator listItr;
    printf("\nObjects of cylinder blocks are: \n");
    for (listItr = listParam.begin(); listItr != listParam.end(); listItr++)
    {
        (*listItr).display_cylinder(); 
    }
}

// Comparing dimensions to get square base blocks.
bool Compare_width2(SqrBaseRectBlock First, SqrBaseRectBlock Second)
{
    if (First.width = Second.width)
        return false;
    return true;
}
// Comparing dimensions to get cylinderical blocks.
bool Compare_area(CylindricalBlocks First, CylindricalBlocks Second)
{
    if (First.area > Second.area)
        return false;
    return true;
}

// class for spherical blocks
class SphericalBlocks : public CuboidBlocks
{
public:
    float diameter, volume, surface;
    void display_sphere()
    {
        cout << "diameter: "<<diameter<<" surface: " << surface << " volume : " << volume << endl;
    }
};
// looping to indentify cuboid block dimensions
void print_cube_list(list<CuboidBlocks> listParam)
{
    list<CuboidBlocks>::iterator listItr;
    printf("\nObjects of CuboidBlocks are:\n");
    for (listItr = listParam.begin(); listItr != listParam.end(); listItr++)
    {
        (*listItr).display();
    }
}
//looping to identify spherical blocks
void print_sphere_list(list<SphericalBlocks> listParam)
{
    list<SphericalBlocks>::iterator listItr;
    printf("\nObjects of SphericalBlocks are:\n");
    for (listItr = listParam.begin(); listItr != listParam.end(); listItr++)
    {
        (*listItr).display_sphere();
    }
}
// Comparing dimensions to get rect blocks.
bool Compare_width(RectBlocks First, RectBlocks Second)
{
    if (First.width > Second.width)
        return false;
    return true;
}
// Comparing dimensions to get spherical blocks.
bool Compare_surface(SphericalBlocks First, SphericalBlocks Second)
{
    if (First.surface > Second.surface)
        return false;
    return true;
}

int main()
{

    // array for vectors
    RectBlocks rect[MAXX];
    CuboidBlocks cubid[MAXX];
    SphericalBlocks sphere[MAXX];
    CylindricalBlocks cylin[MAXX];
    CuboidBlocks cubes[MAXX];
    

    list<SqrBaseRectBlock> listA;
    list<CylindricalBlocks> listB;
    list<CuboidBlocks> listC;
    list<SphericalBlocks> listS;

    vector<int> v;
    string line, s;
    int lineNum = 0;
    

    // Reading the datablock file
    ifstream myfile("dataBlocks.dat");
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, line);
            istringstream input(line);
            int w,h,l;
            input >> w;
            input >> h;
            input >> l;
            if (w == h && h == l && w == l)
            {
                cubes[lineNum].width = w;
                cubes[lineNum].height = h;
                cubes[lineNum].length = l;
                listC.push_back(cubes[lineNum]);
                float r = (w / 2);
                //formulae for  sphericalBlocks()
                sphere[lineNum].diameter = (w);
                sphere[lineNum].surface = 4 * 3.1416 * pow(r, 2);
                sphere[lineNum].volume = 1.333 * 3.1416 * pow(r, 3);
                listS.push_back(sphere[lineNum]);
            }
            input >> w;
            input >> h;
            if (w == h ){
                sphere[lineNum].width = w;
                sphere[lineNum].height = h;
                listA.push_back(sphere[lineNum]);  
                float r = (w / 2);
                //formulae for cylindricalBlocks()
                cylin[lineNum].diameter=(w);
                cylin[lineNum].area= 2* 3.1416* r* h ;
                listB.push_back(cylin[lineNum]);             

            }
            lineNum++;
        }
        myfile.close();
    }
    else
    {
        cout << "File not found!!!!!";
    }
    listA.sort(Compare_width2);
    print_sphere_list(listA);
    listB.sort(Compare_area);
    print_cylinder_list(listB);
    listC.sort(Compare_width);
    print_cube_list(listC);
    listS.sort(Compare_surface);
    print_sphere_list(listS);
}
