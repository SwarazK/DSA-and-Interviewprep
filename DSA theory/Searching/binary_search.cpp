#include<bits/stdc++.h>
using namespace std;  

int main(){

    vector<int> vec;

    int n;
    cin>>n;

    while(n--){
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    int target;
    cin>>target;
    int l = 0, h = vec.size()-1;
    int m = (l+h)/2;

    while(l<h){
        if(vec[m] ==  target){
            cout<<"found at index"<<" "<<m<<endl;
            break;    
        }
        else if(vec[m] > target) h = m - 1;
        else l = m + 1;
        m = (l+h)/2;
    }
    
    if(vec[m] != target) cout<<"Target isnt in the vector"<<endl;
    return 0;
}