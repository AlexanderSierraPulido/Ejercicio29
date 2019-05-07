#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;

void PDE(int nt,string filename);
float T=6, c= 0.5,pi=4*atan(1) ;

void PDE(int nt,string filename)
    {
    int N = 101, L=100;
    float U[N][3]={0}, dx = 0.01, dt = 0.01;
    ofstream outfile;
    outfile.open(filename);
        
    // Condicion inicial , t=0
    for (int i=0; i<N;i++)
        {
        U[i][0] = sin(pi*i/L);
        U[i][2] = U[i][0];
        }
    for(int j=0; j<N; j++)
        {
            outfile << U[j][0] << " ";
            if(j==L)
                {
                outfile<<endl;
                }
        }
    //Avance en el tiempo
    for(int i=1; i<L;i++)
        {
        U[i][1]=U[i][0]+(c*c)*(U[i+1][0]+U[i-1][0]-2*U[i][0]);
        }
    
    for(int j=0; j<N; j++)
        {
        outfile<<U[j][1]<<" ";
        if(j==L)
            {
            outfile<<endl;
            }
        }
        
    for(int j=0; j<N; j++)
        {
            outfile<<U[j][2]<<" ";
            if(j==L)
                {
                outfile<<endl;
                }
        } 
    // Reescribo
    for(int i=0;i<N;i++)
        {
            U[i][0] = U[i][1];
            U[i][1] =  U[i][2];
            U[i][2] = 0;
        }
    
    for(int i=1; i<L; i++)
        {
            U[i][2] = 2*U[i][1] - U[i][0] + (c*c)*(U[i+1][1] + U[i-1][1] - 2*U[i][1]);
        }
    
    
    for(int j=0; j<N; j++)
        {
        outfile<<U[j][2]<<" ";
        if(j==L)
            {
            outfile<<endl;
            }
        }
       
}

int main()
    {
        PDE(301, "Solucion.dat");
        return 0;
    }
