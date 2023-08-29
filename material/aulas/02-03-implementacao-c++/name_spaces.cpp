#include <iostream>
#include <string>

using namespace std;

int main(){
    int x; //como C, precisamos tomar cuidado com a declaracao e atribuicao de variavel

    cout << "Digite um numero: ";
    cin >> x; //cin eh a entrada padrao
    cout << "Voce digitou: " << x << "?\n";

    int y;
    string s;

    y = 2 * x;
    x = y * 5;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "Digite uma palavra: ";
    cin >> s;
    cout << "Voce digitou: " << s << endl;
    
    return 0;
}