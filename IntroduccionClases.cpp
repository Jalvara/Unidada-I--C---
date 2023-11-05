#include <iostream>
#include <cmath>
using namespace std;
class Cuaterniones{
protected:
    double w[4]={};
    //n es el numero de cuaterniones en funcionamiento
public:
    double* ObtenerParametro();
    void Imprimir();
    //Seccion de Constructor y Destructor
    Cuaterniones(double a, double b, double c, double d);
    Cuaterniones(double z[]);
    Cuaterniones(Cuaterniones &X);
    ~Cuaterniones();
    //Seccion de sobrecarga de operadores
    Cuaterniones operator+=(Cuaterniones &c);
    Cuaterniones operator+(Cuaterniones &x);
    Cuaterniones operator*(Cuaterniones &x);
    friend ostream& operator<<(ostream& os,Cuaterniones x);
};
class Complejo:public Cuaterniones{
    public:
        Complejo(double a, double b):Cuaterniones(a,b,0,0)
        {};
        Complejo(Cuaterniones &C):Cuaterniones(C)
        {};
        double ObtenerModulo();
};
int main(){
    cout<<"------------------Zona compleja--------------"<<endl;
    Complejo Z1(2,1);
    Z1.Imprimir();
    Complejo Z2(3,1);
    Complejo Z3(0,0);
    Z3.Imprimir();
    cout<<"El modulo de Z1 es: "<<Z1.ObtenerModulo()<<endl;
    Z3.Imprimir();
    //Z3=Z1*Z2;
    cout<<"------------------Zona Cuaterniones--------------"<<endl;

    Cuaterniones X(1,1,1,1);
    Cuaterniones Y(2,2,2,2);
    Cuaterniones Z(X);
    X=(Z+=Y);
    Cuaterniones W(0,0,0,0);
    W=X*Z;
    X.Imprimir();
    Z.Imprimir();
    cout<<W;
    return 0;
}
Cuaterniones::Cuaterniones(double a, double b, double c, double d){
    w[0]=a;w[1]=b;w[2]=c;w[3]=d;
    //n++;
}
Cuaterniones::~Cuaterniones(){
    cout<<"El programa finalizo\n";
    Imprimir();
}
ostream& operator<<(ostream& os,Cuaterniones x){
double *w=x.ObtenerParametro();
char A[]="ijk";
if(w[0]!=0)
    os<<w[0];
for(int i=1;i<4;i++){
    if(w[i]>0 && w[i]!=1)
    {
        int sum=0;
        for(int k=0;k<i;k++)
            sum+=w[k]*w[k];
        if(sum==0)
            os<<w[i]<<A[i-1];
        else
            os<<"+"<<w[i]<<A[i-1];
    }
    else if (w[i]==1)
    {
        int sum=0;
        for(int k=0;k<i;k++)
            sum+=w[k]*w[k];
        if(sum==0)
            os<<A[i-1];
        else
            os<<"+"<<A[i-1];
    }
    else if (w[i]<0 && w[i]!=-1)
    {
        os<<w[i]<<A[i-1];
    }
    else if(w[i]==-1)
    {
        os<<"-"<<A[i-1];
    }
}
if(w[0]==0 && w[1]==0 && w[2]==0 && w[3]==0)
    os<<"0";
os<<endl;    
return os;
}
void Cuaterniones::Imprimir(){
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
Cuaterniones::Cuaterniones(Cuaterniones &X){
    double *w1=X.ObtenerParametro();
    w[0]=w1[0];w[1]=w1[1];w[2]=w1[2];w[3]=w1[3];
    cout<<"Pase por aqui, te lo dije"<<endl;
}
double* Cuaterniones::ObtenerParametro(){
    return w;
}
Cuaterniones::Cuaterniones(double z[]){
    w[0]=z[0];w[1]=z[1];w[2]=z[2];w[3]=z[3];
}
Cuaterniones Cuaterniones::operator+=(Cuaterniones & c){
            for(int k=0;k<4;k++)
                w[k]+=*(c.ObtenerParametro()+k);
        return *this;
    }
Cuaterniones Cuaterniones::operator+(Cuaterniones &x){
    double z[4];
    double *px=x.ObtenerParametro();
    z[0]=w[0]+px[0];z[1]=w[1]+px[1];z[2]=w[2]+px[2];z[3]=w[3]+px[3];
    Cuaterniones aux(z);
    return aux;}
Cuaterniones Cuaterniones::operator*(Cuaterniones &x){
    double z[4];
    double *px=x.ObtenerParametro();
    z[0]=w[0]*px[0]-w[1]*px[1]-w[2]*px[2]-w[3]*px[3];
    z[1]=w[0]*px[1]+w[1]*px[0]+w[2]*px[3]-w[3]*px[2];
    z[2]=w[0]*px[2]-w[1]*px[3]+w[2]*px[0]+w[3]*px[1];
    z[3]=w[0]*px[3]+w[1]*px[2]-w[2]*px[1]+w[3]*px[0];
    Cuaterniones aux(z);
    return aux;
}
double Complejo::ObtenerModulo(){
            return sqrt(w[0]*w[0]+w[1]*w[1]);
        };