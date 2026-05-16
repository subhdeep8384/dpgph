#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = INT16_MIN;

int kadane(vector<int>& a) {

    int curr = a[0];
    int best = a[0];

    for(int i = 1; i < a.size(); i++) {

        curr = max(a[i], curr + a[i]);

        best = max(best, curr);
    }

    return best;
}

void solve(vector<int>& a, int k) {

    ans = max(ans, kadane(a));


    if(k == 0)
        return;

    int n = a.size();


    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            swap(a[i], a[j]);

            solve(a, k - 1);

            swap(a[i], a[j]); 
        }
    }
}

int main() {

    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve(a, k);

    cout << ans;
}