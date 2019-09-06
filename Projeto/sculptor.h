#ifndef SCULPTOR_H
#define SCULPTOR_H

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
    void setColor(float r, float g, float b, float alpha);
};

#endif // SCULPTOR_H
