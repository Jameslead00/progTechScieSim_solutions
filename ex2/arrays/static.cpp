#include <iostream>


int main(){
    const int max = 20;
    double array[max];
    int n;

    std::cout << "how many values?\n";
    std::cin >> n;
    while(true){
        if(n <= 0 || n > max){
            std::cout << "\n invalid n, try again: \n";
            std::cin >> n;
        } else break;
    }
    double sum = 0;

    std::cout << "enter " << n << " values: \n";
    for(int i = 0; i < n; i++){
        std::cin >> array[i];
        sum += array[i];
    }
    for(int i = n - 1; i >= 0; i--){
        std::cout << array[i]/sum << std::endl;
    }
    return 0;
}