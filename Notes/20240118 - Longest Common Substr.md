# 20240118 - 最长公共子序列

Source: [1143. 最长公共子序列 - 力扣（LeetCode）](https://leetcode.cn/problems/longest-common-subsequence/description/)

## Problem:

给定两个字符串 `text1` 和 `text2`，返回这两个字符串的最长 **公共子序列** 的长度。如果不存在 **公共子序列** ，返回 `0` 。

一个字符串的 **子序列** 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

- 例如，`"ace"` 是 `"abcde"` 的子序列，但 `"aec"` 不是 `"abcde"` 的子序列。

两个字符串的 **公共子序列** 是这两个字符串所共同拥有的子序列。

**示例 1：**

**输入：** text1 = "abcde", text2 = "ace" 
**输出：** 3  
**解释：** 最长公共子序列是 "ace" ，它的长度为 3 。

**示例 2：**

**输入：** text1 = "abc", text2 = "abc"
**输出：** 3
**解释：** 最长公共子序列是 "abc" ，它的长度为 3 。

**示例 3：**

**输入：** text1 = "abc", text2 = "def"
**输出：** 0
**解释：** 两个字符串没有公共子序列，返回 0 。

## Analysis:

- 将问题划分为子问题，最小子问题是判断一个字符串中一个长度为1的字符串是否重叠

- 使用一个数组保存与字符串重叠的结果，例如两个字符串分别为``ababcdas`` 和 ``a`` 那么创建一个长度为 **8** 的数组用于保存本次匹配结果。匹配结果为：``[1,0,1,0,0,0，1,0]`` .  

- 假设下一个字符为``b``, 即找出`ababcdas` 和 ``ab``的最长公共子串，我们已经知道``a``的匹配结果，可以用来生成下一个联合的匹配结果。分析可知我们需要的操作为：当当前字符与待匹配字符不匹配时，将当前数组设置为上一个数组对应位置的值，前进匹配下一个字符，当匹配时，将前面最大的数加1复制到当前数组相应位置，当前位置为1时，之前最大结果计为0. 这样下一个匹配结果的数组状态即为：``[1,2,1,2,0,0,1,0]``。同理当下一个字符为``c`` 时，下一个数组状态为``[1,2,1,2,3,0,1,0]``. 最长公共字串即位3，题目仅要求最长公共子串长度，没有要求输出其中一个或全部最长子串，因此仅需使用两个数组即可，可减少空间复杂度。

## Complete code

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class longestCommonSubstr{
    public:
    int getLongestCommonSubstr( string text1, string text2 ){
        int m, n;
        m = text1.size();
        n = text2.size();
        int result = 0;
        if ( m == 0 || n == 0){
            return result;
        } else if ( m > n ){
            result = this->core( text1, text2 );
        } else {
            result = this->core( text2, text1 );
        }
        return result;
    }
    int core( string text1, string text2 ){
        int m, n;   // m >= n
        m = text1.size();
        n = text2.size();
        int status_array[m+1][n] = {}; // initial it with 0
        int current_max;
        for (int i = 1; i < m+1; i++ ){
            current_max = 0;
            for (int j = 0; j < n; j++ ){
                if ( text1.at(i-1) == text2.at(j) ) {
                    status_array[i][j] = current_max + 1;
                } else {
                    status_array[i][j] = status_array[i-1][j];
                }
                current_max = max( current_max, status_array[i-1][j] );
            }
        }
        for (int i = 0; i < n; i++){
            current_max = max( current_max, status_array[m][i] );
        }
        return current_max;
    }
};
int main(){

    string text1, text2;
    cin >> text1 >> text2;

    int lcs;
    longestCommonSubstr e;
    lcs = e.getLongestCommonSubstr( text1, text2 );

    cout << "longest common substr: " << lcs << endl;

    return 0;
}
```




