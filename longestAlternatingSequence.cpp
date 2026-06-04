#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {4, 3, 8, 5, 3, 8};

    int n = arr.size();

    vector<int> inc(n); 
    vector<int> dec(n); 

    for(int i = 0; i < n; i++) {
        inc[i] = arr[i];
        dec[i] = arr[i];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < i; j++) {

            if(arr[i] > arr[j]) {
                inc[i] = max(inc[i], dec[j] + arr[i]);
            }

            if(arr[i] < arr[j]) {
                dec[i] = max(dec[i], inc[j] + arr[i]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max(ans, max(inc[i], dec[i]));
    }

    cout << ans << endl;
}