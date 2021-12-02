#include <iostream>
#include <vector>
#include <string>
using namespace std;

int marcado(int posicao,vector<int> xm){
    return xm[posicao];
}

void printar(const vector<string>& matriz){//printar
    for (auto & i : matriz){
        for (char j : i){
            cout << j;
        }
        cout << endl;
    }
}

vector<string> ln(vector<string> vect, int N, int contador, string saida, int posicao,vector<string> saida2,const vector<int>& xm,vector<string>& lm) {
    if (contador == N){
        return saida2;//parada,quando chega no valor escrito pelo usuario
    }
    for (int i = 0; i < vect[posicao].size(); i++){
        if(vect[posicao][i] != '\0') {//so olhar se tiver algo
            saida.push_back(vect[posicao][i]);
            if(marcado(i,xm) == 1){//se estiver marcado colocar no vetor lm,como estou passando ponteiro,esta mudando diretamente na memoria
                lm.push_back(saida);
            }
            saida2.push_back(saida);
            contador++;//contar quantos estados passaram
            saida2 = ln(vect,N,contador,saida,i,saida2,xm,lm);//recursiva
            saida = saida.substr(0, saida.size()-1);//apagar ultimo termo pois saiu da recursividade e ultimo estado salvo eh do for anterior
            contador--;//diminuir 1 pois o ultimo estado salvo eh do for anterior,tem que voltar 1.
        }
    }
    return saida2;
}

int main(){
    vector<string> m{
            {'\0', 'r', '\0'},
            {'p', '\0', 'r'},
            {'\0', 'p', '\0'}
    };//Matriz de Adjacências.
    string vect;
    vector<int> xm{1,0,0};//estado marcado
    vector<string> m2;
    vector<string> lm;
    for (auto & i : m){//printar matriz
        for (char j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    int N;
    cout << endl << "Qual valor de N quer?" << endl;
    cin >> N;
    int contador = 0;
    int posicao = 0;
    cout <<endl <<"LN"<<endl<<endl;
    printar(ln(m,N,contador,vect,posicao,m2,xm,lm));//printar resultado de Ln
    cout <<endl <<"LNm"<<endl<<endl;
    printar(lm);//printar resultado de Lm
}