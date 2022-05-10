#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int ans = 0;
int limit = 0;
int info[26] = {0,};
int arr[10];
vector<bool> chk(10,false);
vector<bool> usingAlpha(26, false);

void dfs(int cnt, vector<string> &nums){
    if(cnt == limit){
        int sum = 0;
        int idx =0;
        for(int i=0;i<26;i++){
            if(usingAlpha[i] == true){
                info[i]=arr[idx];
                idx++;
            }
            if(idx == limit)
                break;
        }
        for(int i=0;i<nums.size();i++){
            int tmp = 0;
            for(int j=0;j<nums[i].size();j++){
                tmp = tmp*10 + info[nums[i][j]-'A'];
            }
            sum += tmp;
        }
        ans = max(ans, sum);
        return;
    }
    for(int i=0;i<10;i++){
        if(chk[i] == false){
            chk[i] = true;
            arr[cnt] = i;
            dfs(cnt+1, nums);
            chk[i] = false;            
        }
    }
}


int main(){
    cin>>n;
    vector<string> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
        for(int j=0;j<nums[i].size();j++){
            int ascii = nums[i][j]-'A';
            if(usingAlpha[ascii] == false){
                usingAlpha[ascii] = true;
                limit++;
            }
        }
    }
    dfs(0, nums);   
    cout << ans;
    return 0;
}