#include <iostream>
#include <vector>

using namespace std;

void printer(vector<int> v);

int main(){
    // int v[] = {1, 2, 3, 4, 5}; //uses the array class to make a 1d array (as a vector) not recommended
    vector<int> v = {1, 2, 3, 4, 5};
    printer(v);


    vector<int> v2; //this syntax uses the vector class, it inherits a few methods from it, that facilitates our usage

    cout << v[0] << endl;

    int x;
    cout << "digite quantos numeros quiser salvar: \n";

    while(cin >> x){
        v2.push_back(x); //push_back is a method from the vector class, it adds an element to the end of the vector
    }

    //for loops:
    // for (int i = 0; i < v.size(); i++){
    //     cout << i << endl;
    // }

    cout << "voce salvou " << v2.size() << "numeros \n";

    

    return 0;
}

void printer(vector<int> v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

//funcao que recebe um vetor por referencia, e um numero t, popula o vertor com t numeros
void populate(vector<int>& v, int t){
    int x;
    for (int i = 0; i < t; i++){
        cin >> x;
        v.push_back(x);
    }
}