#include "sculptor.h"
#include <string>
#include <fstream>
#include <cmath>
Voxel ***v;

/**
 * @brief Sculptor::Sculptor - método construtor que aloca uma matriz tridimensional de tamanho nx por ny por nz
 * @param _nx - parêmetro que se refere a altura
 * @param _ny - parêmetro que se refere a largura
 * @param _nz - parêmetro que se refere a profundidade
 */

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

/**
 * @brief Sculptor::~Sculptor - método destrutor que libera a memória da matriz tridimensional alocada
 */

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
 * @brief Sculptor::putBox - desenha uma caixa cujas dimensões são definidas pelos parâmetro abaixo
 * @param x0 - parâmetro de onde começa a altura da caixa
 * @param x1 - parâmetro de onde termina a altura da caixa
 * @param y0 - parâmetro de onde começa a largura da caixa
 * @param y1 - parâmetro de onde termina a largura da caixa
 * @param z0 - parâmetro de onde começa a profundidade da caixa
 * @param z1 - parâmetro de onde termina a produndidade da caixa
 */


/**
 * @brief Sculptor::cutBox - apaga uma caixa cujas dimensões são definidas pelos parametros abaixo
 * @param x0 - parâmetro de altura onde começa a apagar a caixa
 * @param x1 - parâmetro de altura onde termina de apagar a apagar a caixa
 * @param y0 - parâmetro de largura onde começa a apagar a caixa
 * @param y1 - parâmetro de largura onde termina a apagar a caixa
 * @param z0 - parâmetro de profundidade onde começa a apagar a caixa
 * @param z1 - parâmetro de profundidade onde termina a apagar a caixa
 */
/*

/**
 * @brief Sculptor::putSphere - desenha uma esfera tal que o centro e o raios são definidos pelos parâmetros abaixo
 * @param xcenter - parâmetro de define a altura do centro da esfera em relação a origem
 * @param ycenter - parâmetro de define a largura do centro da esfera em relação a origem
 * @param zcenter - parâmetro de define a profundidade do centro da esfera em relação a origem
 * @param radius - raio da esfera
 */

/**
 * @brief Sculptor::cutSphere -apaga uma esfera de dimensões definidas pelos parâmetros abaixo
 * @param xcenter - parâmetro de define a altura do centro da esfera em relação a origem
 * @param ycenter - parâmetro de define a largura do centro da esfera em relação a origem
 * @param zcenter - parâmetro de define a profundidade do centro da esfera em relação a origem
 * @param radius - raio da esfera
 */

/**
 * @brief Sculptor::putEllipsoid - desenha um elipsóide cujas dimensões são definidas pelos parâmetros abaixo
 * @param xcenter - parâmetro de define a altura do centro da esfera em relação a origem
 * @param ycenter - parâmetro de define a largura do centro da esfera em relação a origem
 * @param zcenter - parâmetro de define a profundidade do centro da esfera em relação a ori
 * @param rx - raio do elipsóide em relação a altura
 * @param ry - raio do elipsóide em relação a largura
 * @param rz - raio do elipsóide em relação a profundidade
 */
/*
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
*/
/**
 * @brief Sculptor::cutEllipsoid - apaga um elipsóide cujas dimensões são definidas pelos parâmetros abaixo
 * @param xcenter - parâmetro de define a altura do centro da esfera em relação a origem
 * @param ycenter - parâmetro de define a largura do centro da esfera em relação a origem
 * @param zcenter - parâmetro de define a profundidade do centro da esfera em relação a ori
 * @param rx - raio do elipsóide em relação a altura
 * @param ry - raio do elipsóide em relação a largura
 * @param rz - raio do elipsóide em relação a profundidade
 */
/*
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
*/
/**
 * @brief Sculptor::writeOFF - método que escreve todas informações de vertice, faces, cor necessários para um arquivo .off,
 * que será lido pelo programa
 * @param fillename - nome do arquivo
 */

void Sculptor::writeOFF(char* fillename)
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
