#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>

using namespace std;

struct Voxel {
    float r,g,b; // Colors
    float a;
    // Transparency
    bool isOn; // Included or not
};

class Sculptor
{
protected:
    Voxel ***v;
    // 3D matrix
    int nx,ny,nz; // Dimensions
public:
    float r,g,b,a; // Current drawing color
    Sculptor();
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(string filename);
    bool getisOn(int i,int j,int k);
    float getR(int i, int j, int k);
    float getG(int i, int j, int k);
    float getB(int i, int j, int k);
};

#endif // SCULPTOR_H
