#include <iostream>
#include <vector>
using namespace std;
vector<int> somarmatriz(vector<int> a,vector<int> b,int coluna){
    vector<int> resultado;
    for (int i = 0; i < coluna; i++){
        resultado.push_back(0);
        resultado[i] = a[i] + b[i];
    }

    return resultado;
}
vector<int> multiplicarmatriz(vector<int> a,vector<vector<int>> b,int linha,int coluna){
    vector<int> resultado;
    for (int i = 0; i < coluna; i++) {
        resultado.push_back(0);
        for (int j = 0; j < linha; j++) {
            resultado[i] += a[j] * b[j][i];
        }
    }
    return resultado;
}
void arvore(int N,vector<vector<int>> A,vector<int> x0){
}

int main() {
    cout << "Hello, World!" << endl;
    vector<vector<int>> A
            {
                   //p1,p2,p3,p4,p5,l1,l2,l3,l4,l5,l6
                   {-1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},//B1
                    {1,-1, 0, 0, 0,-1, 0, 0, 0, 0, 0},//B2a
                    {0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 0},//B2b
                    {0, 0,-1, 0, 0, 0, 0,-1, 0, 0, 0},//B2c
                    {0, 0, 0,-5, 0, 0, 0, 0,-5, 0, 0},//B2d
                    {0, 0, 0, 0,-1, 0, 0, 0, 0,-1, 0},//B2e
                    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},//B3
                    {0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 0},//B4_a
                    {0, 0,-1, 0, 0, 0, 0,-1, 0, 0, 0},//B4_b
                    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},//B5
                    {0, 0, 0,-5, 1, 0, 0, 0,-5, 1, 0},//B6
                    {0, 0, 0, 0, 0, 0,-1, 1, 0, 0, 0},//chave_a
                    {0, 0, 0, 0, 0, 0, 1,-1, 0, 0, 0},//chave-b
                    {0, 0, 0,-5, 0, 0, 0, 0,-5, 0, 0},//reset_a
                    {0, 0, 0, 0,-1, 0, 0, 0, 0,-1, 0},//reset_b
                    {0,-1, 0, 0, 0,-1, 0, 0, 0, 0, 1},//e_a
                    {0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 1},//e_b
                    {0, 0,-1, 0, 0, 0, 0,-1, 0, 0, 1},//e_c
                    {0, 0, 0,-5, 0, 0, 0, 0,-5, 0, 1},//e_d
                    {0, 0, 0, 0,-1, 0, 0, 0, 0,-1, 1},//e_e
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1}//retorno
            };
    int linha = 21,coluna = 11;
    vector<int> x0{1,0,0,0,0,0,0,0,0,0,0};
    vector<int> u{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < A.size(); i++) {//Printar a matriz f na posical certa(coluna char) (se mexer com a memoria vai ter a saida errada)
        for (int j = 0; j < A[i].size(); j++){
                cout << A[i][j] << " ";
        }
        cout <<endl;
    }
    int N;
    cout << "Qual valor de N?" << endl;
    //cin >> N;
    arvore(N,A,x0);
    vector<int> r;
    r = somarmatriz(x0,multiplicarmatriz(u,A,linha,coluna),coluna);
    for (int j = 0; j < r.size(); j++){
        cout << r[j] << " ";
    }
    return 0;
}
