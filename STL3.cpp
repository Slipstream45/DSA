#include<bits/stdc++.h>
using namespace std;

void p(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

int main() {
    vector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = (i + 1) * (i + 2);
    }
    for (int i = 9; i > 0; i--) {
        v[i] -= v[i - 1];
    }
    p(v);
}
