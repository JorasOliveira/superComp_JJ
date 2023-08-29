#include <iostream>

using namespace std;

int main(){

    int x;
    cout << "Digite um numero: ";
    cin >> x; //if input is not a number, x will remain unchanged

    if(!x){ //auto detects if input was a nunber, so we can easly check
        cout << "Erro na entrada de dados\n";
        return 1;
    }

    int y;
    cout << "Digite outro numero: ";
    cin >> y;

    if(!y){ //auto detects if input was a nunber, so we can easly check
        cout << "Erro na entrada de dados\n";
        return 1;
    }


    if(y > x){
        cout << "O primeiro numero eh menor que o segund!\n";
    }
    else if (x > y){
        cout << "O segundo numero eh menor que o primeiro!\n";
    }
    else {
        cout << "Os numeros sao iguais!\n";
    }

    cout << "digite 2 numeros: ";
    cin >> x >> y; //we can read multiple inputs in one line
    cout << "x = " << x << " ";
    cout << "y = " << y << "\n";

    return 0;
}