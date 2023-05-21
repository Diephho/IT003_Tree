#include<bits/stdc++.h>

using namespace std;

int main(){
    srand(time(NULL));
    const int NMIN = 1000000 * 5 / 7;
    for (int i = 1; i <= 10; i++){
        string data = "test" + to_string(i) + ".txt";
        ofstream fo;
        fo.open(data);
        int n = NMIN + (rand() % NMIN) * 17;
        fo << n << '\n';
        for (int j = 0; j < n; j++){
            fo << rand() % 1000000 + 1 << ' ';
        }
        fo.close();
    }
    return 0;
}