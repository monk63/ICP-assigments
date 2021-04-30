#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h>
#define MAXX 100

using namespace std;

class RectBlocks
{
public:
    int width, length, height;
    RectBlocks()
    {
        this->length = 0;
        this->width = 0;
        this->height = 0;
    }
    void display()
    {
        cout << "width: " << width << " height: " << height << " length: " << length << endl;
    }
    ~RectBlocks() {} //destrucor
};
class SqrBaseRectBlock : public RectBlocks
{
};
class CuboidBlocks : public SqrBaseRectBlock
{
};
class CylindricalBlocks : public SqrBaseRectBlock
{
};
class SphericalBlocks : public CuboidBlocks
{
public:
    float radius, volume, surface;
    void display_sphere()
    {
        cout << "surface: " << surface << " volume : " << volume << endl;
    }
};

void print_cube_list(list<CuboidBlocks> listParam)
{
    list<CuboidBlocks>::iterator listItr;
    printf("\nObjects of CuboidBlocks are:\n");
    for (listItr = listParam.begin(); listItr != listParam.end(); listItr++)
    {
        (*listItr).display();
    }
}
void print_sphere_list(list<SphericalBlocks> listParam)
{
    list<SphericalBlocks>::iterator listItr;
    printf("\nObjects of SphericalBlocks are:\n");
    for (listItr = listParam.begin(); listItr != listParam.end(); listItr++)
    {
        (*listItr).display_sphere();
    }
}

bool Compare_width(RectBlocks First, RectBlocks Second)
{
    if (First.width > Second.width)
        return false;
    return true;
}
bool Compare_surface(SphericalBlocks First, SphericalBlocks Second)
{
    if (First.surface > Second.surface)
        return false;
    return true;
}

int main()
{
    RectBlocks rect[MAXX];
    CuboidBlocks cubid[MAXX];
    SphericalBlocks sphere[MAXX];
    CylindricalBlocks cylin[MAXX];
    CuboidBlocks cubes[MAXX];

    list<CuboidBlocks> listC;
    list<SphericalBlocks> listS;

    vector<int> v;
    string line, s;
    int lineNum = 0;

    ifstream myfile("input.txt");
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, line);
            istringstream input(line);
            int skip, w, h, l;
            input >> skip;
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
                sphere[lineNum].radius = (w / 2);
                sphere[lineNum].surface = 4 * 3.1416 * pow(r, 2);
                sphere[lineNum].volume = 1.333 * 3.1416 * pow(r, 3);
                listS.push_back(sphere[lineNum]);
            }
            //All you have to do is to: implement Cylendrical objects array and sort it,(i left it intentionally cz it's your homework, bro)
            lineNum++;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    listC.sort(Compare_width);
    print_cube_list(listC);
    listS.sort(Compare_surface);
    print_sphere_list(listS);
}