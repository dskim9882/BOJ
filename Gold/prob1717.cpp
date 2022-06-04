#include <iostream>
using namespace std;

int arr[1000001];

int findSet(int num){
    if(arr[num] == num)
        return arr[num];
    else {
        return arr[num] = findSet(arr[num]);
    }
}

void unionSet(int n1, int n2){
    n1 = findSet(n1);
    n2 = findSet(n2);
    
    if(n1 != n2)
        arr[n2] = n1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    //Make-Set
    for(int i=0;i<1000001;i++)
        arr[i] = i;
    for(int i=0;i<m;i++){
        int op, n1, n2;
        cin >> op >> n1 >> n2;
        if(op == 0){
            unionSet(n1, n2);
        } else {
            if(findSet(n1) == findSet(n2))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
    return 0;
}