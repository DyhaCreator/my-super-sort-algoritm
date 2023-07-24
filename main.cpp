#include <iostream>
#include <vector>
#include <random>
#include <cmath>

std::vector<int> del(std::vector<int>vec1, int index){
    std::vector<int>vec2 = std::vector<int>();
    for(int i = 0; i < vec1.size(); i ++){
        if(i != index){
            vec2.push_back(vec1[i]);
        }
    }
    return vec2;
}

bool isSort(std::vector<int>arr){
    for(int i = 0; i < arr.size() - 1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

bool s(std::vector<int>arr1, std::vector<int>arr2){
    std::vector<int>arr3 = arr2;
    int sum = 0;
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr3.size(); j++){
            if(arr1[i] == arr3[j]){
                sum++;
                arr3 = del(arr3, j);
                break;
            }
        }
    }
    if(sum == arr1.size() && isSort(arr1))return true;
    return false;
}

int main(){
    std::vector<int>arr = {7,2,4,1,2};
    //for(int i = 0; i < arr.size(); i++)arr[i] = i + 1;
    std::vector<int>arr2 = std::vector<int>(arr.size());
    int max = arr[0];

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > max)max = arr[i];
    }

    for(int i = 0; i < pow(max + 1, arr2.size()); i++){
        for(int j = 0; j < arr2.size(); j++){
            if(arr2[j] > max){
                arr2[j] = 0;
                arr2[j+1]++;
            }
        }
        if(s(arr2,arr))break;
        arr2[0]++;
    }

    for(int j = 0; j < arr2.size(); j++){
        std::cout << arr2[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}