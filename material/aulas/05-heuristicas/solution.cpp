#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream> // file stream

using namespace std;

struct Item {
    int id;
    double peso;
    double valor;
};

void printer(vector<Item> v);
void weight_first(vector<Item> v, int W, vector<Item>& knapsack);
void cost_first(vector<Item> v, int W, vector<Item>& knapsack);

int main(){


    std::string file_name = "in2.txt";
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int N, W;
    file >> N >> W;

    std::vector<Item> objects(N);
    std::string line;

    getline(file, line); // Read and discard the newline after N and W

    for (int i = 0; i < N; ++i) {
        getline(file, line);
        std::stringstream ss(line);
        ss >>objects[i].peso >> objects[i].valor;
    }

    file.close();
    // printer(objects);

    vector<Item> selectedItemsWeightFirst;
    vector<Item> selectedItemsCostFirst;

    weight_first(objects, W, selectedItemsWeightFirst);
    cost_first(objects, W, selectedItemsCostFirst);

    cout << "Selected Items (Weight First): ";
    for (const Item& item : selectedItemsWeightFirst) {
        cout << "id: " << item.id << " peso: " << item.peso << " valor: " << item.valor << " | ";
    }
    cout << endl;

    cout << "Selected Items (Cost First): ";
    for (const Item& item : selectedItemsCostFirst) {
        cout << "id: " << item.id << " peso: " << item.peso << " valor: " << item.valor << " | ";
    }
    cout << endl;
    

    return 0;
}


void printer(vector<Item> v){
    for (int i = 0; i < v.size(); i++){
        cout << "id: " << i << "peso: " << v[i].peso << "valor: "<< v[i].valor << endl;
    }
}


void weight_first(vector<Item> v, int W, vector<Item>& knapsack) {
    int i = 0;
    int peso = 0;
    int valor = 0;
    while (i < v.size() && peso < W) {
        if (peso + v[i].peso < W) {
            peso += v[i].peso;
            valor += v[i].valor;
            knapsack.push_back(v[i]);
        }
        i++;
    }
}

void cost_first(vector<Item> v, int W, vector<Item>& knapsack) {
    int i = 0;
    int peso = 0;
    int valor = 0;
    while (i < v.size() && valor < W) {
        if (peso + v[i].peso < W) {
            peso += v[i].peso;
            valor += v[i].valor;
            knapsack.push_back(v[i]);
        }
        i++;
    }
}