#include "sculptor.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = new Voxel**[nx];
    if(v == nullptr){
        std::cout << "Matriz nao alocada";
        exit(0);
    }
    for (int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
        if(v[i] == nullptr){
            std::cout << "Matriz nao alocada";
            exit(0);
        }
        for (int j = 0; j < ny; j++){
            v[i][j] = new Voxel[nz];
            if(v[i][j] == nullptr){
                std::cout << "Matriz nao alocada";
                exit(0);
            }
        }
    }
    std::cout << "Iniciando programa de geracao de arquivo\n";
}
Sculptor::~Sculptor(){
    for (int x = 0; x < nx; x++){
        for(int y = 0; y < ny; y++){
            delete v[x][y];
        }
    }
    for (int x = 0; x < nx; x++){
        delete v[x];
    }
    delete v;
    std::cout << "Programa finalizado\n";
}
void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}
void Sculptor::putVoxel(int x, int y, int z){
    if(x > 0 && x < nx){
        if(y > 0 && y < ny){
            if(z > 0 && z < nz){
                v[x][y][z].r = r;
                v[x][y][z].g = g;
                v[x][y][z].b = b;
                v[x][y][z].a = a;
                v[x][y][z].isOn = true;
            }
        }
    }
}
void Sculptor::cutVoxel(int x, int y, int z){
    if(x > 0 && x < nx){
        if(y > 0 && y < ny){
            if(z > 0 && z < nz){
                v[x][y][z].isOn = false;
            }
        }
    }
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
                putVoxel(i,j,k);
            }
        }
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
                cutVoxel(i,j,k);
            }
        }
    }
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = (xcenter - radius); i < (xcenter + radius); i++){
        for(int j = (ycenter - radius); j < (ycenter + radius); j++){
            for(int k = (zcenter - radius); k < (zcenter + radius); k++){
                int m = pow((i - xcenter),2);
                int n = pow((j - ycenter),2);
                int o = pow((k - zcenter),2);
                int p = pow(radius,2);
                if((m+n+o) < p){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = (xcenter - radius); i < (xcenter + radius); i++){
        for(int j = (ycenter - radius); j < (ycenter + radius); j++){
            for(int k = (zcenter - radius); k < (zcenter + radius); k++){
                int m = pow((i - xcenter),2);
                int n = pow((j - ycenter),2);
                int o = pow((k - zcenter),2);
                int p = pow(radius,2);
                if((m+n+o) < p){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = (xcenter - rx); i < (xcenter + rx); i++){
        for(int j = (ycenter - ry); j < (ycenter + ry); j++){
            for(int k = (zcenter - rz); k < (zcenter + rz); k++){
                float m = pow(((i - xcenter)/(float)rx),2);
                float n = pow(((j - ycenter)/(float)ry),2);
                float o = pow(((k - zcenter)/(float)rz),2);
                if((m+n+o) < 1.0){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = (xcenter - rx); i < (xcenter + rx); i++){
        for(int j = (ycenter - ry); j < (ycenter + ry); j++){
            for(int k = (zcenter - rz); k < (zcenter + rz); k++){
                float m = pow(((i - xcenter)/(float)rx),2);
                float n = pow(((j - ycenter)/(float)ry),2);
                float o = pow(((k - zcenter)/(float)rz),2);
                if((m+n+o) < 1.0){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::writeOFF(const char* filename){
    int contador = 0;
    int valor;
    std::ofstream xfiles;
    std::cout << "Iniciando geracao do arquivo\n";
    xfiles.open("escultura.off");
    if(xfiles.is_open()){
        std::cout << "Arquivo criado com sucesso\n";
        xfiles << "OFF" << "\n";
        for(int i = 0; i < nx; i++){
            for(int j = 0; j < ny; j++){
                for(int k = 0; k < nz; k++){
                    if(v[i][j][k].isOn == true){
                        contador++;
                    }
                }
            }
        }
        xfiles << 8*contador << " " << 6*contador << " " << 0 << "\n";

        for(int i = 0; i < nx; i++){
            for(int j = 0; j < ny; j++){
                for(int k = 0; k < nz; k++){
                    if(v[i][j][k].isOn == true){
                        xfiles << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                        xfiles << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                        xfiles << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                        xfiles << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                        xfiles << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                        xfiles << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                        xfiles << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                        xfiles << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                    }
                }
            }
        }
        contador = 0;
        for(int i = 0; i < nx; i++){
            for(int j = 0; j < ny; j++){
                for(int k = 0; k < nz; k++){
                    if(v[i][j][k].isOn == true){
                        valor = 8*contador;
                        xfiles << 4 << " " << 0 + valor << " " << 3 + valor << " " << 2 + valor << " " << 1 + valor << " " << v[i][j][k].r << ".0 " << v[i][j][k].g << ".0 " << v[i][j][k].b << ".0 " << v[i][j][k].a << "\n";
                        xfiles << 4 << " " << 4 + valor << " " << 5 + valor << " " << 6 + valor << " " << 7 + valor << " " << v[i][j][k].r << ".0 " << v[i][j][k].g << ".0 " << v[i][j][k].b << ".0 " << v[i][j][k].a << "\n";
                        xfiles << 4 << " " << 0 + valor << " " << 1 + valor << " " << 5 + valor << " " << 4 + valor << " " << v[i][j][k].r << ".0 " << v[i][j][k].g << ".0 " << v[i][j][k].b << ".0 " << v[i][j][k].a << "\n";
                        xfiles << 4 << " " << 0 + valor << " " << 4 + valor << " " << 7 + valor << " " << 3 + valor << " " << v[i][j][k].r << ".0 " << v[i][j][k].g << ".0 " << v[i][j][k].b << ".0 " << v[i][j][k].a << "\n";
                        xfiles << 4 << " " << 3 + valor << " " << 7 + valor << " " << 6 + valor << " " << 2 + valor << " " << v[i][j][k].r << ".0 " << v[i][j][k].g << ".0 " << v[i][j][k].b << ".0 " << v[i][j][k].a << "\n";
                        xfiles << 4 << " " << 1 + valor << " " << 2 + valor << " " << 6 + valor << " " << 5 + valor << " " << v[i][j][k].r << ".0 " << v[i][j][k].g << ".0 " << v[i][j][k].b << ".0 " << v[i][j][k].a << "\n";
                        contador++;
                    }
                }
            }
        }

        xfiles.close();
        std::cout << "Arquivo escrito com sucesso!\n";
        std::cout << "Verifique seus arquivos\n";
    }
    else{
        std::cout << "Falha ao criar o arquivo\n";
    }
}
