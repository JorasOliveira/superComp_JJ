#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm> // for std::sort

using namespace std;

struct Item {
    int id;
    double peso;
    double valor;
};

// Comparison function to sort items by weight
bool compareByWeight(const Item& a, const Item& b) {
    if (a.peso == b.peso) {
        return a.valor > b.valor;
    };
    return a.peso < b.peso;
}

// Comparison function to sort items by value
bool compareByValue(const Item& a, const Item& b) {
    if (a. valor == b.valor){
        return a.peso < b.peso;
    };
    return a.valor > b.valor;
}

//using recursion to atemp a brute force solution
//vector of itens V, capacity W, number of itens N
int compareByRecusrion(vector<Item> v, int W, int N) {
    // Base case: No more items or no capacity left
    if (N == 0 || W == 0) {
        return 0;
    }

    // Consider the current item
    Item item = v[N - 1]; // Note the N - 1 index
    int pathA = 0;
    int pathB = 0;

    // If the current item can fit in the knapsack
    if (item.peso <= W) {
        // Calculate the value when including the item
        
        pathA = item.valor + compareByRecusrion(v, W - item.peso, N - 1);
    }

    // Calculate the value when excluding the item
    pathB = compareByRecusrion(v, W, N - 1);

    // Return the maximum of the two paths
    return max(pathA, pathB);
}
void printer(vector<Item> v);
void knapsack_pusher(vector<Item> v, int W, vector<Item>& knapsack);


int main() {
    std::string file_name = "in-aula.txt";
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int N, W;
    file >> N >> W;

    std::cerr<< N << std::endl;
    std::cerr<< W << std::endl;

    std::vector<Item> objects(N);
    std::string line;
    getline(file, line); // Read and discard the newline after N and W

    for (int i = 0; i < N; ++i) {
        getline(file, line);
        std::stringstream ss(line);
        ss >> objects[i].peso >> objects[i].valor;
        objects[i].id = i;
    }

    file.close();
    printer(objects);
    int welp;
    welp = compareByRecusrion(objects, W, N);

    cout << "result of recursive brute force: " << welp << "\n";

    vector<Item> selectedItemsWeightFirst;
    vector<Item> selectedItemsCostFirst;

    // Sort selectedItemsWeightFirst by weight
    sort(objects.begin(), objects.end(), compareByWeight);
    // cout << "Objects ordered by Weight: \n";
    // printer(objects);
    knapsack_pusher(objects, W, selectedItemsWeightFirst);

    cout << "Selected Items (Weight First): \n";
    printer(selectedItemsWeightFirst);

    // Sort selectedItemsCostFirst by value
    sort(objects.begin(), objects.end(),  compareByValue);
    // cout << "Objects ordered by Value: \n";
    // printer(objects);
    knapsack_pusher(objects, W, selectedItemsCostFirst);

    cout << "Selected Items (Cost First): \n";
    printer(selectedItemsCostFirst);

    return 0;
}

void printer(vector<Item> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "id: " << v[i].id << " peso: " << v[i].peso << " valor: " << v[i].valor << endl;
    }
    cout << endl;
}

void knapsack_pusher(vector<Item> v, int W, vector<Item>& knapsack) {
    int i = 0;
    int peso = 0;
    int valor = 0;
    while (i < v.size() && peso <= W) {
        if (peso + v[i].peso <= W) {
            peso += v[i].peso;
            valor += v[i].valor;
            knapsack.push_back(v[i]);
        }
        i++;
    }
}