#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    vector<string> input(n);
    int arr[26] = {0,};
    for(int i=0;i<n;i++){
        cin>>input[i];
        int digit = 1;
        for(int j=input[i].size()-1;j>=0;j--){
            arr[input[i][j] - 'A'] += digit;
            digit *= 10;
        }
    }
    sort(arr, arr+26, cmp);
    int ans =0;
    for(int i=0;i<10;i++){
        ans += (9-i)*arr[i];
    }
    cout << ans;
    return 0;
}