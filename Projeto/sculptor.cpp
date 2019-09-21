#include "sculptor.h"
#include <string>
#include <fstream>
#include <cmath>
Voxel ***v;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx=_nx;
    ny=_ny;
    nz=_nz;
    setColor(1,0,0,1);
    v=new Voxel**[_nz];

    for(int i = 0; i < _nz; i++){
        v[i] = new Voxel*[_nx];
    }
    for(int i = 0; i < _nz; i++){
        for(int j = 0; j <_nx; j++){
            v[i][j] = new Voxel[_ny];
        }
    }
    for(int i=0; i<nz; i++){
        for(int j=0; j<nx; j++){
            for(int k=0; k<ny; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    for(int i = 0; i < nz; i++){
        for(int j = 0; j < nx; j++){
            delete [] **v;
        }
    }
    for(int i = 0; i < nz; i++){
        delete [] *v;
    }
    delete v;

}

void Sculptor::setColor(float r=0, float g=0, float b=0, float alpha=1){
    this->r=r;
    this->g=g;
    this->b=b;
    a=alpha;
}

void Sculptor:: putVoxel(int x, int y, int z)
{
    if(x<nx && y<ny && z<nz && x>=0 && y>=0 && z>=0){
        v[z][x][y].isOn=true;
        v[z][x][y].r=r;
        v[z][x][y].g=g;
        v[z][x][y].b=b;
        v[z][x][y].a=a;
    }
}

void Sculptor:: cutVoxel(int x, int y, int z)
{
    if(x<nx && y<ny && z<nz && x>=0 && y>=0 && z>=0){
        v[z][x][y].isOn=false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=z0; i<z1; i++){
        for(int j=x0; j<x1; j++){
            for(int k=y0; k<y1; k++){
                if(j>=0 && j<nx && k>=0 && k<ny && i>=0 && i<nz){
                    v[i][j][k].isOn=true;
                    v[i][j][k].r=r;
                    v[i][j][k].g=g;
                    v[i][j][k].b=b;
                    v[i][j][k].a=a;
                }
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=z0; i<z1; i++){
        for(int j=x0; j<x1; j++){
            for(int k=y0; k<y1; k++){
                if(j>=0 && j<nx && k>=0 && k<ny && i>=0 && i<nz){
                    v[i][j][k].isOn=false;
                }
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i=0; i<nz; i++){
        for(int j=0; j<nx; j++){
            for(int k=0; k<ny; k++){
                if(pow(i-zcenter,2)+pow(j-xcenter,2)+pow(k-ycenter,2) <= pow(radius,2)){
                    v[i][j][k].isOn=true;
                    v[i][j][k].r=r;
                    v[i][j][k].g=g;
                    v[i][j][k].b=b;
                    v[i][j][k].a=a;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i=0; i<nz; i++){
        for(int j=0; j<nx; j++){
            for(int k=0; k<ny; k++){
                if(pow(i-zcenter,2)+pow(j-xcenter,2)+pow(k-ycenter,2) <= pow(radius,2)){
                    v[i][j][k].isOn=false;
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i=0; i<nz; i++){
        for(int j=0; j<nx; j++){
            for(int k=0; k<ny; k++){
                if(pow(i-zcenter,2)/pow(rz,2) + pow(j-xcenter,2)/pow(rx,2) + pow(k-ycenter,2)/pow(ry,2) <= 1){
                    v[i][j][k].isOn=true;
                    v[i][j][k].r=r;
                    v[i][j][k].g=g;
                    v[i][j][k].b=b;
                    v[i][j][k].a=a;
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i=0; i<nz; i++){
        for(int j=0; j<nx; j++){
            for(int k=0; k<ny; k++){
                if(pow(i-zcenter,2)/pow(rz,2) + pow(j-xcenter,2)/pow(rx,2) + pow(k-ycenter,2)/pow(ry,2) <= 1){
                    v[i][j][k].isOn=false;
                }
            }
        }
    }
}
void Sculptor::writeOFF(string fillename)
{
    int nVertices=0,nFaces=0;
    ofstream fout;
    fout.open(fillename);
    if(!fout.is_open())
    {
        exit(0);
    }
    for (int i=0;i<nz;i++) {
        for (int j=0;j<nx;j++) {
            for (int k=0;k<ny;k++) {
                if(v[i][j][k].isOn)
                {
                    nVertices+=8;
                    nFaces+=6;

                }
            }

        }
    }
    fout<<"OFF\n"<<nVertices<<" "<<nFaces<<" 0"<<endl;
    for (int i=0;i<nz;i++) {
        for (int j=0;j<nx;j++) {
            for (int k=0;k<ny;k++) {
                if(v[i][j][k].isOn)
                {
                    fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                    fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                    fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                    fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                    fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }

        }
    }
    int a[8]={0,1,2,3,4,5,6,7};
    for (int i=0;i<nz;i++) {
        for (int j=0;j<nx;j++) {
            for (int k=0;k<ny;k++) {
                if(v[i][j][k].isOn)
                {
                    fout<<"4 "<<a[0]<<" "<<a[3]<<" "<<a[2]<<" "<<a[1]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[4]<<" "<<a[5]<<" "<<a[6]<<" "<<a[7]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[0]<<" "<<a[1]<<" "<<a[5]<<" "<<a[4]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[0]<<" "<<a[4]<<" "<<a[7]<<" "<<a[3]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[3]<<" "<<a[7]<<" "<<a[6]<<" "<<a[2]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[1]<<" "<<a[2]<<" "<<a[6]<<" "<<a[5]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    for(int l=0;l<8;l++)
                    {
                        a[l]+=8;
                    }

                }
            }

        }
    }
   fout.close();
}
