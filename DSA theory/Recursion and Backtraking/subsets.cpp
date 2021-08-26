#include<bits/stdc++.h>
using namespace std;

int j = 0;

//Generates all possible subsets of size n from the given array
void generateSubsets(vector<int> array, vector<int> &subset, int n, int i){ //n is the size of the required subsets, i is the current index, initially zero
    if(subset.size() == n) j++; //Process the generated subset
    else{
        if(i<array.size()){
            subset.push_back(array[i]);
            generateSubsets(array,subset,n,i+1);
            subset.pop_back();
            generateSubsets(array,subset,n,i+1);
        }
    }
}

int main(){
    return 0;
}