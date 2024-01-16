#include<iostream>

using namespace std;

int main() {
    int t;
    bool isExistsZero;
    int numNegative;

    int temp;

    cin >> t;

    bool isExistsZeroArray[t];
    int numNegativeArray[t];

    for (int i=0; i<t; i++){
        int num;
        cin >> num;

        isExistsZero = false;
        numNegative = 0;

        for (int j = 0; j < num; j++){
            cin >> temp;
            if (temp == 0) {
                isExistsZero = true;
            }else if ( temp < 0 ){
                numNegative += 1;
            }
        }

        isExistsZeroArray[i] = isExistsZero;
        numNegativeArray[i] = numNegative;

    }

    for (int i = 0; i < t; i++){
        if ( isExistsZeroArray[i] || numNegativeArray[i]%2 == 1 ){
            cout << 0 << "\n";
        }else {
            cout << 1 << "\n" << 1 << "\t" << 0 << "\n";
        }
    }
} 