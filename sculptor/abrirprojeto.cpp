#include "abrirprojeto.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "classes.h"

using namespace std;

AbrirProjeto::AbrirProjeto(string arquivo)
{
    int dimx=1,dimy=1,dimz=1;
    vector<FiguraGeometrica*> fig;
    string comando,str;
    ifstream fin;
    fin.open(arquivo);
    if(!fin.is_open())
    {
        cout<<"error ao abrir o arquivo"<<endl;
        exit(0);
    }
    while(1)
    {
        getline(fin,str);
        if(fin.good())
        {
            stringstream ss(str);
            ss>>comando;
            cout<<comando<<endl;
            if(comando.compare("dim")==0){
                ss>>dimx>>dimy>>dimz;
            }else if(comando.compare("putvoxel")==0){
                int x,y,z;
                float r,g,b,a;
                ss>>x>>y>>z>>r>>g>>b>>a;
                fig.push_back(new PutVoxel(x,y,z,r,g,b,a));
            }else if(comando.compare("cutvoxel")==0){
                int x,y,z;
                ss>>x>>y>>z;
                fig.push_back(new CutVoxel(x,y,z));
            }else if (comando.compare("putbox")==0){
                int x0,y0,z0,x1,y1,z1;
                float r,g,b,a;
                ss>>x0>>x1>>y0>>y1>>z0>>z1>>r>>g>>b>>a;
                fig.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
            }else if(comando.compare("cutbox")==0){
                int x0,y0,z0,x1,y1,z1;
                ss>>x0>>x1>>y0>>y1>>z0>>z1;
                fig.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
            }else if(comando.compare("putsphere")==0){
                int x0, y0, z0, raio;
                float r, g, b, a;
                ss>>x0>>y0>>z0>>raio>>r>>g>>b>>a;
                fig.push_back(new PutSphere(x0,y0,z0,raio,r,g,b,a));
            }else if(comando.compare("cutsphere")==0){
                int x0, y0, z0, raio;
                ss>>x0>>y0>>z0>>raio;
                fig.push_back(new CutSphere(x0,y0,z0,raio));
            }else if(comando.compare("putellipsoid")==0){
                int x0, y0, z0, raiox, raioy, raioz;
                float r, g, b, a;
                ss>>x0>>y0>>z0>>raiox>>raioy>>raioz>>r>>g>>b>>a;
                fig.push_back(new PutEllipsoid(x0,y0,z0,raiox,raioy,raioz,r,g,b,a));
            }else if(comando.compare("cutellipsoid")==0){
                int x0, y0, z0, raiox, raioy, raioz;
                ss>>x0>>y0>>z0>>raiox>>raioy>>raioz;
                fig.push_back(new CutEllipsoid(x0,y0,z0,raiox,raioy,raioz));
            }
        }else {
            break;
        }
    }
    Sculptor p(dimx,dimy,dimz);
    for(unsigned int i=0;i<fig.size();i++)
    {
        fig[i]->draw(p);
    }
    p.writeOFF(arquivo + ".off");
    //system("geomview " + arquivo + ".off");

}
