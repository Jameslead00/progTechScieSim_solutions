#include <iostream>

int gcd_rec(int a, int b){
    if(a == 0 || b == 0){
        return a + b;
    }
    else if(a<b){return gcd_rec(a, b%a);}
    else return gcd_rec(b, a%b);
}

int gcd_loop(int a , int b){
    int t = 0;
    while(b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(){
    std::cout << "type a and b\n";
    int a, b;
    std::cin >> a >> b;
    std::cout << "\n rec gcd: " << gcd_rec(a,b) << std::endl;
    std::cout << "\n loop gcd: " << gcd_loop(a, b) << std::endl;
    return 0;
}