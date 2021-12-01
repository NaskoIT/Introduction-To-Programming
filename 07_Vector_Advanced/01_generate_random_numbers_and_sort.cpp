#include <iostream>
#include<cstdlib>
#include <vector>
#include<ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));

    vector<int> test(100);
    for (int i = 0; i < test.size(); ++i) {
        test[i] = (rand() % 100) + 1;
    }

    for (int i = 0; i < test.size(); ++i) {
        cout << test[i] << " ";
    }
    
    cout << endl;
    
    sort(test.begin(), test.end() - 50);

    for (int i = 0; i < test.size(); ++i) {
        cout << test[i] << " ";
    }
}