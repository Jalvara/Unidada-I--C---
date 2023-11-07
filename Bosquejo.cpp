#include <iostream>
//Este programa demuestra que cuando se usa el igual
//se esta usando un tipo de copiado.
using namespace std;
class A{
public:
    int x[2];
    A(int a,int b);
    A(A& X);
    void Imprimir();
    //Prefija
    A& operator++();
    A operator+(A& z);
};
class B:public A{
public: 
    int y;
    B():A(0,0)
    {};
    B(int s):A(0,0)
    {y=s;};
    B(int a,int b,int c):A(a,b){
        y=c;
    };
    void Imprimir();
    void operator++();
};
int main(){
    A z(1,2);
    A w(1,1);
    A u(2,2);
    u=z+w+u;
    u.Imprimir();
    w=++z;
    z.Imprimir();
    w.Imprimir();
    B z1(3,41,-1);
    B* ptr;
    z1.Imprimir();
    z=z1;
    ++z1;
    z1.Imprimir();
    z.Imprimir();
    return 0;
}
void A::Imprimir(){
    cout<<"a: "<<x[0]<<endl;
    cout<<"b: "<<x[1]<<endl;
    cout<<"Direccion: "<<x<<endl;
}
void B::Imprimir(){
    A::Imprimir();
    cout<<"y: "<<y<<endl;

}
A::A(int a,int b){
    x[0]=a;x[1]=b;   
}
A::A(A& X){
    this->x[0]=X.x[0]+1;
    this->x[1]=X.x[1]+2;
}
A& A::operator++(){
    this->x[0]++;
    this->x[1]++;
    return *this;
}
void B::operator++(){
    this->x[0]++;
    this->x[1]++;
    this->y++;
}
A A::operator+(A& z){
    A aux(0,0);
    aux.x[0]=this->x[0]+z.x[0];
    aux.x[1]=this->x[1]+z.x[1];
    return aux;
}