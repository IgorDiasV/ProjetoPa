#include "sculptor.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
//Voxel ***v;

/**
 * @brief Sculptor::Sculptor - método construtor que aloca uma matriz tridimensional de tamanho nx por ny por nz
 * @param _nx - parêmetro que se refere a altura
 * @param _ny - parêmetro que se refere a largura
 * @param _nz - parêmetro que se refere a profundidade
 */

Sculptor::Sculptor()
{

}

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
    for(int i=0; i<_nz; i++){
        for(int j=0; j<_nx; j++){
            for(int k=0; k<_ny; k++){
                v[i][j][k].isOn = false;
            }
        }
    }

}


/**
 * @brief Sculptor::~Sculptor - método destrutor que libera a memória da matriz tridimensional alocada
 */

Sculptor::~Sculptor(){
    delete [] **v;
    delete [] *v;
    delete [] v;
}

/**
 * @brief Sculptor::setColor - define uma cor para sua escultura. As cores são normalizadas entre 0 e 1
 * @param r - se refere a quantidade de vermelho
 * @param g - se refere a quantidade de verde
 * @param b - se refere a quantidade de azul
 * @param alpha - se refere a transparencia. 1 é totalmente opaco e 0 e totalmente transparente
 */

void Sculptor::setColor(float r=0, float g=0, float b=0, float alpha=1){
    this->r=r;
    this->g=g;
    this->b=b;
    a=alpha;
}

/**
 * @brief Sculptor::putVoxel - desenha um voxel e um lugar especifico da matriz
 * @param x - parâmetro de altura em relação a origem
 * @param y - parâmetro de largura em relação a origem
 * @param z - parâmetro de profundidade em relação a origem
 */

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

/**
 * @brief Sculptor::cutVoxel - apaga um voxel em um lugar específica da matriz
 * @param x - parâmetro de altura em relação a origem
 * @param y - parâmetro de largura em relação a origem
 * @param z - parâmetro de profundidade em relação a origem
 */

void Sculptor:: cutVoxel(int x, int y, int z)
{
    if(x<nx && y<ny && z<nz && x>=0 && y>=0 && z>=0){
        v[z][x][y].isOn=false;
    }
}

/**
 * @brief Sculptor::writeOFF - método que escreve todas informações de vertice, faces, cor necessários para um arquivo .off,
 * que será lido pelo programa
 * @param fillename - nome do arquivo
 */
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
                 fout<<"4 "<<a[0]<<" "<<a[3]<<" "<<a[2]<<" "<<a[1]<<" "<<fixed<<setprecision(4)<<v[i][j][k].r<<" "<<setprecision(4)<<v[i][j][k].g<<" "<<setprecision(4)<<v[i][j][k].b<<" "<<setprecision(4)<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[4]<<" "<<a[5]<<" "<<a[6]<<" "<<a[7]<<" "<<setprecision(4)<<v[i][j][k].r<<" "<<setprecision(4)<<v[i][j][k].g<<" "<<setprecision(4)<<v[i][j][k].b<<" "<<setprecision(4)<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[0]<<" "<<a[1]<<" "<<a[5]<<" "<<a[4]<<" "<<setprecision(4)<<v[i][j][k].r<<" "<<setprecision(4)<<v[i][j][k].g<<" "<<setprecision(4)<<v[i][j][k].b<<" "<<setprecision(4)<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[0]<<" "<<a[4]<<" "<<a[7]<<" "<<a[3]<<" "<<setprecision(4)<<v[i][j][k].r<<" "<<setprecision(4)<<v[i][j][k].g<<" "<<setprecision(4)<<v[i][j][k].b<<" "<<setprecision(4)<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[3]<<" "<<a[7]<<" "<<a[6]<<" "<<a[2]<<" "<<setprecision(4)<<v[i][j][k].r<<" "<<setprecision(4)<<v[i][j][k].g<<" "<<setprecision(4)<<v[i][j][k].b<<" "<<setprecision(4)<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[1]<<" "<<a[2]<<" "<<a[6]<<" "<<a[5]<<" "<<setprecision(4)<<v[i][j][k].r<<" "<<setprecision(4)<<v[i][j][k].g<<" "<<setprecision(4)<<v[i][j][k].b<<" "<<setprecision(4)<<v[i][j][k].a<<endl;

                    /* fout<<"4 "<<a[4]<<" "<<a[5]<<" "<<a[6]<<" "<<a[7]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[0]<<" "<<a[1]<<" "<<a[5]<<" "<<a[4]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[0]<<" "<<a[4]<<" "<<a[7]<<" "<<a[3]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[3]<<" "<<a[7]<<" "<<a[6]<<" "<<a[2]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    fout<<"4 "<<a[1]<<" "<<a[2]<<" "<<a[6]<<" "<<a[5]<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    */
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

bool Sculptor::getisOn(int x,int y,int z)
{
    return v[z][x][y].isOn;
}

float Sculptor::getR(int i, int j, int k)
{
    return v[k][i][j].r;
}

float Sculptor::getG(int i, int j, int k)
{
    return v[k][i][j].g;
}

float Sculptor::getB(int i, int j, int k)
{
    return v[k][i][j].b;
}
