# 20240114 - Least Product

Source: [Problem - 1917A - Codeforces](https://codeforces.com/problemset/problem/1917/A)

## Problem:

You are given an array of integers $\pmb{a_1,a_2,...,a_n}$. You can perform the following operation any number of times (possibly zero):

- Choose any element $\pmb{a_i}$ from the array and change its value to any integer between $\pmb{0}$ and $\pmb{a_i}$ (inclusive). More formally, if $\pmb{a_i<0}$ replace $\pmb{a_i}$ with any inter in $\pmb{[a_i,0]}$, otherwise replace $\pmb{a_i}$ with any integer in $\pmb{[0,a_i]}$.

Let $\pmb{r}$ be the minimum possible product of all the $\pmb{a_i}$ after performing the operation any number of times.

Find the minimum number of operations required to make the product equal to $\pmb{r}$. Also, print one such shorttest squence of operations. If there are mulitiple answers, you can print any of them.

### Input:

Each test consists of multiple test cases. The first line contains a single integer $\pmb{t}$
 ($\pmb{1≤t≤500}$) - the number of test cases. This is followed by their description.

The first line of each test case contains the a single integer $\pmb{n\ (1≤n≤100)}$ — the length of the array.

The second line of each test case contains $\pmb{n}$ integers  $\pmb{a_1,a_2,...,a_n}$ ($-\pmb{10^9\leq a_i\leq10^9}$).

### Output:

For each test case;

- The first line must contain the minimum number of operations $\pmb{k\ (0\leq k\leq n)}$.

- The $\pmb{j}$-th of the next $\pmb{k}$ lines must contain two integers $\pmb{i}$ and $\pmb{x}$, which represent the    $\pmb{j}$-th operation. That operation consists in replacing $\pmb{a_i}$ with $\pmb{x}$.

### Example

input:

```bash
4
1
155
4
2 8 -1 3
4
-1 0 -2 -5
4
-15 -75 -25 -30
```

output

```bash
1
1 0
0
0
1
3 0

```



## Analysis:

- If there exists one or more $\pmb{0}$ in given array, the product of them always equal to $\pmb{0}$. 

- If all nums are positive in an array, change one of them to $\pmb{0}$.

- If there exists even negative  nums and no $\pmb{0}$, change one of them to $\pmb{0}$.

- If there exists odd negative nums and no $\pmb{0}$, do nothing. 

## Complete code

```cpp
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
```
