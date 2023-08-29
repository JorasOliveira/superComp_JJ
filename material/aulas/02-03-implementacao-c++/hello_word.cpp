#include <iostream>


//base hello world 
// int main(){
//     std::cout << "Hello World!" << std::endl; // std::cout is c output, std::endl is a new line (end line)
//     // std::cout << "Hello World!\n"; // also works, dont 'need' std::endl
//     return 0; // 0 means correct output, 1 means error
// }

//INPUT:
//now we can read the input with argv[]
int main(int argc, char* argv[]){ // argc is the number of arguments, argv is the arguments

    std::cout << "Hello, " << argv[1] << "!\n"; // 
    return 0; 
}