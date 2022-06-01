#include <iostream>
#include "sculptor.hpp"
#include <fstream>
#include <string>

int main()
{
    int alt,larg,prof;
    int x,x1,y,y1,z,z1,rx,ry,rz;
    bool escolha = true;
    std::string escol;

    std::cout << "Bem vindo ao programa de desenho 3D.\n";
    std::cout << "Digite as dimensoes da matriz de desenho.\n";
    std::cout << "A profundidade eh a dimensao x;\n";
    std::cout << "A largura eh a dimensao y;\n";
    std::cout << "A altura eh a dimensao z.\n";
    std::cin >> prof;
    std::cout << " de Profundidade\n";
    std::cin >> larg;
    std::cout << " de Largura\n";
    std::cin >> alt;
    std::cout << " de Altura\n";

    Sculptor obj(prof,larg,alt);

    std::string cor;
    std::string forma;
    std::string colocota;

    while(escolha){
        std::cout << "Escolha uma dessas cores\n";
        std::cout << "Vermelho Verde Azul Amarelo Ciano Mageta Branco Cinza Preto\n";
        std::cin.ignore();
        std::getline(std::cin, cor);
        if(cor == "vermelho"){
            obj.setColor(1.0,0,0,1.0);
        }
        if(cor == "verde"){
            obj.setColor(0,1.0,0,1.0);
        }
        if(cor == "azul"){
            obj.setColor(0,0,1.0,1.0);
        }
        if(cor == "amarelo"){
            obj.setColor(1.0,1.0,0,1.0);
        }
        if(cor == "ciano"){
            obj.setColor(0,1.0,1.0,1.0);
        }
        if(cor == "mageta"){
            obj.setColor(1.0,0,1.0,1.0);
        }
        if(cor == "branco"){
            obj.setColor(1.0,1.0,1.0,1.0);
        }
        if(cor == "cinza"){
            obj.setColor(0.75,0.75,0.75,1.0);
        }
        if(cor == "preto"){
            obj.setColor(0,0,0,1.0);
        }
        std::cout << "Digite a forma geometrica para desenhar\n";
        std::cout << "Cubo Esfera Elispoide Ponto\n";
        std::cin.clear();
        std::getline(std::cin,forma);

        if(forma == "cubo"){
            std::cout << "Colocar ou cortar?\n";
            std::cin.clear();
            std::getline(std::cin,colocota);
            if(colocota == "colocar"){
                std::cout << "Digite os pontos x de inicio e fim\n";
                std::cin >> x;
                std::cout << " Inicio\n";
                std::cin >> x1;
                std::cout << " fim\n";
                std::cout << "Digite os pontos y de inicio e fim\n";
                std::cin >> y;
                std::cout << " Inicio\n";
                std::cin >> y1;
                std::cout << " fim\n";
                std::cout << "Digite os pontos z de inicio e fim\n";
                std::cin >> z;
                std::cout << " Inicio\n";
                std::cin >> z1;
                std::cout << " fim\n";
                obj.putBox(x,x1,y,y1,z,z1);
                std::cout << "Colocando Cubo de dimensoes: " << x1 - x << "," << y1 - y << "," << z1 - z << "\n";
            }
            if(colocota == "cortar"){
                std::cout << "Digite os pontos x de inicio e fim\n";
                std::cin >> x;
                std::cout << " Inicio\n";
                std::cin >> x1;
                std::cout << " fim\n";
                std::cout << "Digite os pontos y de inicio e fim\n";
                std::cin >> y;
                std::cout << " Inicio\n";
                std::cin >> y1;
                std::cout << " fim\n";
                std::cout << "Digite os pontos z de inicio e fim\n";
                std::cin >> z;
                std::cout << " Inicio\n";
                std::cin >> z1;
                std::cout << " fim\n";
                obj.cutBox(x,x1,y,y1,z,z1);
                std::cout << "Cortando Cubo de dimensoes: " << x1 - x << "," << y1 - y << "," << z1 - z << "\n";
            }
        }
        if(forma == "esfera"){
            std::cout << "Colocar ou cortar?\n";
            std::cin.clear();
            std::getline(std::cin,colocota);
            if(colocota == "colocar"){
                std::cout << "Digite o centro em x\n";
                std::cin >> x;
                std::cout << " Centro\n";
                std::cout << "Digite o centro em y\n";
                std::cin >> y;
                std::cout << " Centro\n";
                std::cout << "Digite o centro em z\n";
                std::cin >> z;
                std::cout << " Centro\n";
                std::cout << "Digite o raio da esfera\n";
                std::cin >> rx;
                std::cout << " Raio\n";
                obj.putSphere(x,y,z,rx);
                std::cout << "Colocando Esfera de raio: " << rx << " com centro em: " << x << "," << y << "," << z << "\n";
            }
            if(colocota == "cortar"){
                std::cout << "Digite o centro em x\n";
                std::cin >> x;
                std::cout << " Centro\n";
                std::cout << "Digite o centro em y\n";
                std::cin >> y;
                std::cout << " Centro\n";
                std::cout << "Digite o centro em z\n";
                std::cin >> z;
                std::cout << " Centro\n";
                std::cout << "Digite o raio da esfera\n";
                std::cin >> rx;
                std::cout << " Raio\n";
                obj.cutSphere(x,y,z,rx);
                std::cout << "Cortando Esfera de raio: " << rx << " com centro em: " << x << "," << y << "," << z << "\n";
            }
        }
        if(forma == "elipsoide"){
            std::cout << "Colocar ou cortar?\n";
            std::cin.clear();
            std::getline(std::cin,colocota);
            if(colocota == "colocar"){
                std::cout << "Digite o centro em x\n";
                std::cin >> x;
                std::cout << " Centro\n";
                std::cout << "Digite o centro em y\n";
                std::cin >> y;
                std::cout << " Centro\n";
                std::cout << "Digite o centro em z\n";
                std::cin >> z;
                std::cout << " Centro\n";
                std::cout << "Digite o raio em x\n";
                std::cin >> rx;
                std::cout << " Raio\n";
                std::cout << "Digite o raio em y\n";
                std::cin >> ry;
                std::cout << " Raio\n";
                std::cout << "Digite o raio em z\n";
                std::cin >> rz;
                std::cout << " Raio\n";
                obj.putEllipsoid(x,y,z,rx,ry,rz);
                std::cout << "Colocando Elipsoide de raios: " << rx << "," << ry << "," << rz << " com centro em: " << x << "," << y << "," << z << "\n";
            }
            if(colocota == "cortar"){
                std::cout << "Digite o centro em x\n";
                std::cin >> x;
                std::cout << " Centro\n";
                std::cout << "Digite o centro em y\n";
                std::cin >> y;
                std::cout << " Centro\n";
                std::cout << "Digite o centro em z\n";
                std::cin >> z;
                std::cout << " Centro\n";
                std::cout << "Digite o raio em x\n";
                std::cin >> rx;
                std::cout << " Raio\n";
                std::cout << "Digite o raio em y\n";
                std::cin >> ry;
                std::cout << " Raio\n";
                std::cout << "Digite o raio em z\n";
                std::cin >> rz;
                std::cout << " Raio\n";
                obj.cutEllipsoid(x,y,z,rx,ry,rz);
                std::cout << "Cortando Elipsoide de raios: " << rx << "," << ry << "," << rz << " com centro em: " << x << "," << y << "," << z << "\n";
            }
        }
        if(forma == "ponto"){
            std::cout << "Colocar ou cortar?\n";
            std::getline(std::cin,colocota);
            if(colocota == "colocar"){
                std::cout << "Digite o ponto x\n";
                std::cin >> x;
                std::cout << " Ponto\n";
                std::cout << "Digite o ponto y\n";
                std::cin >> y;
                std::cout << " Ponto\n";
                std::cout << "Digite o ponto z\n";
                std::cin >> z;
                std::cout << " Ponto\n";
                obj.putVoxel(x,y,z);
                std::cout << "Colocando ponto em: " << x << "," << y << "," << z << "\n";
            }
            if(colocota == "cortar"){
                std::cout << "Digite o ponto x\n";
                std::cin >> x;
                std::cout << " Ponto\n";
                std::cout << "Digite o ponto y\n";
                std::cin >> y;
                std::cout << " Ponto\n";
                std::cout << "Digite o ponto z\n";
                std::cin >> z;
                std::cout << " Ponto\n";
                obj.cutVoxel(x,y,z);
                std::cout << "Cortando ponto em: " << x << "," << y << "," << z << "\n";
            }
        }
        std::cout << "Deseja continuar?\n";
        std::cin.ignore();
        std::getline(std::cin, escol);
        if(escol == "nao"){
            escolha = false;
        }

    }
    std::cout << "Obrigado por usar o codigo\n";
    std::cout << "Gerando arquivo\n";
    std::cout << "Pode demorar....\n";

    obj.writeOFF("invalido");
    return 0;
}
