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
    float r,g,b,a; // Current drawing color
public:
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);//n
    void cutVoxel(int x, int y, int z);//n
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);//n
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);//n
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);//n
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);//n
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);//n
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);//n
    void writeOFF(string filename);//n
    void writeVECT(string filename);//n
};

#endif // SCULPTOR_H
