#include <iostream>
#include <cmath>
#include <vector>

using vec = std::vector<double>;

//functions
std::vector<double> generate_seq(unsigned int n);
std::vector<double> merge_sort(const std::vector<double> seq);
std::vector<double> merge(const std::vector<double> left, const std::vector<double> right);

int main(){
    int n;
    std::cout << "input n\n";
    std::cin >> n;
    vec sequence = generate_seq(n);
    std::cout << "original sequence: ";
    for(int i = 0; i < sequence.size(); i++){
        std::cout << sequence.at(i) << " \n";
    }
    std::cout << "\nsorted: ";
    vec sorted = merge_sort(sequence);
    for(int i = 0; i < sorted.size(); i++){
        std::cout << sorted.at(i) << " \n";

    } 

    return 0;
}

std::vector<double> generate_seq(unsigned int n){
    std::vector<double> seq;
    for(int i = 0; i < n; i++){
        seq.push_back(std::sin(i));
    }
    return seq;
}
std::vector<double> merge_sort(const std::vector<double> seq){
    if(seq.size() <= 1) return seq;

    int mid = seq.size() / 2;
    std::vector<double> left(seq.begin(), seq.begin() + mid);
    std::vector<double> right(seq.begin() + mid, seq.end());

    std::vector<double> sorted_left = merge_sort(left);
    std::vector<double> sorted_right = merge_sort(right);

    return merge(sorted_left, sorted_right);
}

vec merge(const vec left, const vec right){
    vec result;
    int left_idx = 0, right_idx = 0;

    while(left_idx < left.size() && right_idx < right.size()){
        if(left.at(left_idx) < right.at(right_idx)){
            result.push_back(left.at(left_idx));
            ++left_idx;
        }else{
            result.push_back(right.at(right_idx));
            ++right_idx;
        }
    }
    while (left_idx < left.size()) {
        result.push_back(left[left_idx]);
        ++left_idx;
    }

    while (right_idx < right.size()) {
        result.push_back(right[right_idx]);
        ++right_idx;
    }

    return result;

}



