#include <iostream>

using namespace std;

int sqrt_it(int& x); // assinatura da funcao


int main(){
    int i = 10;
    cout << sqrt_it(i) << endl;
    cout << "o valor de i = " << i << endl;
    return 0;
}
int sqrt_it(int& x){
    x = x * x;
    return x;
}
