#include <iostream>
#include <vector>

using namespace std;

void printer(vector<vector<int>> v);

int main(){

    const int i = 3;
    const int j = 3;

    int m[i][j] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; //{{line 1 }, {line 2}, {line 3}}

    vector<vector<int>> m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // {{line 1 }, {line 2}, {line 3}}, inherits from vector class

    vector<int> m3; // empty matrix, with unknown size

    vector<vector<int>> m4(i, vector<int>(j)); //empty matrix, with known size

    populator(m4, i);

    vector<vector<int>> m5(3, vector<int>(3, 0)); //matrix with 0s

    return 0;
}

void printer(vector<vector<int>> v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void populator(vector<vector<int>>& v, int t){
    int x;
    for (int i = 0; i < t; i++){
        for (int j = 0; j < t; j++){
            cout << "digite um numero para popular a posicao: " << v[i][j] << " \n";
            cin >> x;
            v[i][j] = x;
        }
    }

    printer(v);
}