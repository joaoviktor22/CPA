#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> q3(int i, vector<int>& s,vector<string> m){
    int igual = 0;
    for (int j = 0; j < m[i].size(); j++){//percorrer as colunas dos eventos para saber quais eventos apontam para o marcado,como eh recursivo ele vai indo o contrario da seta que esta apontando pro evento marcado e pegando todos os eventos que passam para chegar no marcado
        igual = 0;
        if(m[j][i] != '\0'){
            for(int k = 0; k < s.size();k++){
                if(s[k] == j){//ja esta no vetor de eventos inclusos
                    igual = 1;
                }
            }
            if(igual == 0){//ainda nao esta no vetor de eventos
                s.push_back(j);
                q3(j,s,m);//recursivo
            }
        }
    }
    return s;
}

int main(){
    vector<string> m{//Matriz de Adjacências.
            {'\0', 'a', '\0','\0','\0','\0'},
            {'\0', '\0', 'b','a','\0','g'},
            {'g', '\0', '\0','\0','\0','\0'},
            {'\0', '\0', '\0','\0','b','\0'},
            {'\0', '\0', '\0','a','g','\0'},
            {'\0', '\0','\0','\0','\0','\0'}
    };

    vector<string> m2;
    vector<int> xm{0,0,1,0,0,0};//Matriz de marcados.
    vector<int> s;
    cout << "Matriz Antiga" << endl;//printar a Matriz de Adjacências.
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[i].size(); j++){
            cout << m[i][j] << " ";
        }
        cout << "!" << endl ;
    }

    int olho;
    for (int i = 0; i < xm.size(); i++) {
        olho = 0;
        if (xm[i] == 1) {
            for(int k = 0; k < s.size();k++){
                if(s[k] == i){
                    olho = 1;
                }
            }
            if(olho != 1){
                s.push_back(i);
            }
            s = q3(i,s,m);
            cout << endl;
        }
    }
    cout << "Matriz Nova" << endl;
    int tem = 0;
    for (int i = m.size(); i > 0; i--){
        tem = 0;
        for (int j = 0; j < s.size(); j++){
            if(s[j]==i){
                tem = 1;
            }
        }
        if(tem == 0){
            if (m.size() > i){
                m.erase(m.begin() + i);
                for(auto& row:m) row.erase(next(row.begin(), i));
            }
        }
    }
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[i].size(); j++){
            cout << m[i][j] << " ";
        }
        cout << "!" << endl ;
    }
}