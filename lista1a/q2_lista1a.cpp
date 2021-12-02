#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> m{//Matriz de Adjacências.
            {'\0', 'a', '\0','\0','\0'},
            {'\0', '\0', 'b','a','\0'},
            {'g', '\0', '\0','\0','\0'},
            {'\0', '\0', '\0','\0','b'},
            {'\0', '\0', '\0','a','g'}
    };
    vector<vector<int>> f;//Matriz de f
    vector<vector<char>> eventos;//Matriz em que fica salva em cada linhas os eventos da linha.
    int e = 0;
    for (int i = 0; i < m.size(); i++) {//Salvar no vetor eventos para que cada linha fique todos os eventos da linha de m.
        eventos.emplace_back();
        for (int j = 0; j < m[i].size(); j++){
            e = 0;
            for(int z=0; z<eventos[i].size(); z++){
                if(eventos[i][z] == m[i][j]){
                    e = 1;
                }
            }
            if(e == 0){
                eventos[i].push_back(m[i][j]);
            }
        }
    }
    for(int i=0; i<m.size(); i++){//Alocar memoria de f no mesmo tamanho que m colocando valores aleatorios(valor da coluna)
        f.emplace_back();
        for(int j=0; j<m[i].size(); j++)
        {
            f[i].push_back(j);
        }
    }
    for (int i = 0; i < m.size(); i++) {//salvar o valor correto de f em cada posicao, pegando memoria aleatoria pois coluna eh char
        for (int j = 0; j < m[i].size(); j++){
            if(m[i][j] != '\0'){
                f[i][m[i][j]] = j;
            }
        }
    }
    for (int i = 0; i < eventos.size(); i++) {//Printar a matriz f na posical certa(coluna char) (se mexer com a memoria vai ter a saida errada)
        for (int j = 0; j < eventos[i].size(); j++){
            if(eventos[i][j] != '\0'){
                cout << "f[" << i << "]["<< eventos[i][j] << "] = " << f[i][eventos[i][j]] << endl;
            }
        }
    }
}