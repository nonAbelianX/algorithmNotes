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