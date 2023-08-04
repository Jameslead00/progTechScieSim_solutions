#include <iostream>
#include <vector>

using vec = std::vector<double>;

int main(){
    vec vector;
    std::cout << "enter your values. End with -1\n";
    double sum = 0;
    while(true){
        double n;
        std::cin >> n;
        if(n == -1) break;
        vector.push_back(n);
        sum += n;
    }

    for(int i = vector.size()-1; i >= 0; i--){
        std::cout << vector.at(i)/sum << std::endl;
    }
    return 0;

}