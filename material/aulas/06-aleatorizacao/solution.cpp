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
    return a.peso > b.peso;
}

// Comparison function to sort items by value
bool compareByValue(const Item& a, const Item& b) {
    return a.valor > b.valor;
}

void printer(vector<Item> v);
void knapsack_pusher(vector<Item> v, int W, vector<Item>& knapsack);

int main() {
    std::string file_name = "in1.txt";
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

    vector<Item> selectedItemsWeightFirst;
    vector<Item> selectedItemsCostFirst;


    // Sort selectedItemsWeightFirst by weight
    sort(objects.begin(), objects.end(), compareByWeight);
    cout << "Objects ordered by Weight: \n";
    printer(objects);
    knapsack_pusher(objects, W, selectedItemsWeightFirst);

    cout << "Selected Items (Weight First): \n";
    printer(selectedItemsWeightFirst);

    // Sort selectedItemsCostFirst by value
    sort(objects.begin(), objects.end(),  compareByValue);
    cout << "Objects ordered by Value: \n";
    printer(objects);
    knapsack_pusher(objects, W, selectedItemsCostFirst);

    cout << "Selected Items (Cost First): \n";
    printer(selectedItemsCostFirst);

    return 0;
}

void printer(vector<Item> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "id: " << v[i].id << " peso: " << v[i].peso << " valor: " << v[i].valor << endl;
    }
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