#include <iostream>
using namespace std;
class Cuaterniones{
    double *w;
    //n es el numero de cuaterniones en funcionamiento
public:
    Cuaterniones(){
    w=nullptr;}
    double* ObtenerParametro() const;
    Cuaterniones(double a, double b, double c, double d);
    Cuaterniones(Cuaterniones &X);
    ~Cuaterniones();
    void Imprimir();
    //int NumeroCuaterniones();
};
int main(){
    Cuaterniones X(1,0,0,-1);
    X.Imprimir();
    Cuaterniones Y(0,1,-2,0);
    Y.Imprimir();
    Cuaterniones Z(X);
    Z.Imprimir();
    return 0;
}
Cuaterniones::Cuaterniones(double a, double b, double c, double d){
    w=new double[4];
    w[0]=a;w[1]=b;w[2]=c;w[3]=d;
    //n++;
}
Cuaterniones::~Cuaterniones(){
    delete w;
}
void Cuaterniones::Imprimir(){
if(w!=nullptr){
    char A[]="ijk";
    if(w[0]!=0)
        cout<<w[0];
    for(int i=1;i<4;i++){
        if(w[i]>0 && w[i]!=1)
        {
            int sum=0;
            for(int k=0;k<i;k++)
                sum+=w[k]*w[k];
            if(sum==0)
                cout<<w[i]<<A[i-1];
            else
                cout<<"+"<<w[i]<<A[i-1];
        }
        else if (w[i]==1)
        {
            int sum=0;
            for(int k=0;k<i;k++)
                sum+=w[k]*w[k];
            if(sum==0)
                cout<<A[i-1];
            else
                cout<<"+"<<A[i-1];
        }
        else if (w[i]<0 && w[i]!=-1)
        {
            cout<<w[i]<<A[i-1];
        }
        else if(w[i]==-1)
        {
            cout<<"-"<<A[i-1];
        }
    }
    if(w[0]==0 && w[1]==0 && w[2]==0 && w[3]==0)
        cout<<"0";
    cout<<endl;
}
}
Cuaterniones::Cuaterniones(Cuaterniones &X){
    double *w1=X.ObtenerParametro();
    if(w1!=nullptr){
        w=new double[4];
        w[0]=w1[0];w[1]=w1[1];w[2]=w1[2];w[3]=w1[3];   
    }
    else
        w=nullptr;
}
double* Cuaterniones::ObtenerParametro() const{
    return w;
}