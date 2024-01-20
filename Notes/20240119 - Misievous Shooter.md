# 20240119 - Mischievous Shooter

Source:  [Problem - 1921G - Codeforces](https://codeforces.com/problemset/problem/1921/G)

## Problem:

Once the mischievous and wayward shooter named Shel found himself on a rectangular field of size n×m, divided into unit squares. Each cell either contains a target or not.

Shel only had a lucky shotgun with him, with which he can shoot in one of the four directions: right-down, left-down, left-up, or right-up. When fired, the shotgun hits all targets in the chosen direction, the Manhattan distance to which does not exceed a fixed constant $k$. The Manhattan distance between two points $\pmb{(x1,y1)}$ and $\pmb{(x2,y2)}$ is equal to $\pmb{|x1−x2|+|y1−y2|}$.

![](https://espresso.codeforces.com/5be3be0c3da7ceb1e2c5179fd6e050bb67595890.png)

Possible hit areas for $\pmb{k = 3}$.

Shel's goal is to hit as many targets as possible. Please help him find this value.

**Input**

Each test consists of several test cases. The first line contains a single integer $\pmb{t(1≤t≤1000)}$ — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains field dimensions $\pmb{n, m}$, and the constant for the shotgun's power $\pmb{k (1≤n,m,k≤105,1≤n⋅m≤105)}$.

Each of the next $\pmb{n}$ lines contains m characters — the description of the next field row, where the character '**.**' means the cell is empty, and the character '**#**' indicates the presence of a target.

It is guaranteed that the sum of $\pmb{n⋅m}$ over all test cases does not exceed $\pmb{10^5}$.

**Output**

For each test case, output a single integer on a separate line, which is equal to the maximum possible number of hit targets with one shot.

**example**

input:

```shell
4
3 3 1
.#.
###
.#.
2 5 3
###..
...##
4 4 2
..##
###.
#..#
####
2 1 3
#
#
```

output:

```shell
3
4
5
2
```

**note**

Possible optimal shots for the examples in the statement:

![](https://espresso.codeforces.com/68524d36e5aa0806407afb4453f80106e8c01f4f.png)

## Analysis:

- Convolution. 

## Complete code
