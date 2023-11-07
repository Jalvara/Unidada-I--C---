#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Matriz{
protected:
    int n=0;
    int m=0;
    vector <vector<double>> M;
public:
    Matriz(int n,int m);
    void Imprimir(int k);
};
int main(){
    Matriz M1(4,3);
    M1.Imprimir(2);
    return 0;
}
Matriz::Matriz(int n,int m){
    this->n=n;
    this->m=m;
    vector<double> aux(m,0);
    for(int k=0;k<n;k++)
        this->M.push_back(aux);
}
void Matriz::Imprimir(int k){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<setw(k)<<M[i][j];
        cout<<endl;
    }
}