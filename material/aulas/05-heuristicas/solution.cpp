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

int main(){


    std::string file_name = "in1.txt";
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

    printer(objects);

    return 0;
}


void printer(vector<Item> v){
    for (int i = 0; i < v.size(); i++){
        cout << "id: " << i << "peso: " << v[i].peso << "valor: "<< v[i].valor << endl;
    }
}
