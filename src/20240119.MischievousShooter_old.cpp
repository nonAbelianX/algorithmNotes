#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class solution{
    public:
    int getMaxTargets(){
        int r, c, k;
        char temp;
        int result = 0;
        int totalTarget = 0;
        cin >> r >> c >> k;

        //this->printGrid(&grid[0][0], r+2*k, c+2*k);
        int maxx = max(r,c);

        if ( 2*(maxx-1) > k ){

            int grid[r + 2*k][c + 2*k] = {};
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    cin >> temp;
                    if (temp == '#'){
                        grid[i+k][j+k] = 1;
                        totalTarget+=1;
                    }
                }
            }

            int from_r, from_c; //decide where to
            int convolutionCore[k+1][k+1];
            int maxTargets[4] = {}, countTemp;
            for (int i = 1; i <5; i++){
                maxTargets[i-1] = 0;
                this->createCore(&convolutionCore[0][0], k+1, i, from_r, from_c);

                //cout << "from_r : " << from_r << "\tfrom_c : " << from_c << endl;
                
                for (int dim1 = from_r; dim1 < from_r+r; dim1++){
                    for (int dim2 = from_c; dim2 < from_c+c; dim2++){
                        countTemp = 0;
                        for (int dim3 = 0; dim3 < k+1; dim3++){
                            for (int dim4 = 0; dim4 < k+1; dim4++){
                                countTemp += convolutionCore[dim3][dim4] * grid[dim1+dim3][dim2+dim4];
                            }    
                        }
                        maxTargets[i-1] = max(maxTargets[i-1], countTemp);
                        if (maxTargets[i-1] == totalTarget){ break; }
                    }
                    if (maxTargets[i-1] == totalTarget){ break; }
                }
                //this->printCore(&convolutionCore[0][0], k);
            }
            
            for (int i = 0; i <4; i++){
                result = max(maxTargets[i], result);
            }
        } else {
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    cin >> temp;
                    if (temp == '#'){
                        totalTarget+=1;
                    }
                }
            }
            result = totalTarget;
        }
        return result;
    }
    
    void createCore(int* convolutionCore, int r, int id, int &from_r, int &from_c){
        for (int i = 0; i < r; i++){
                for (int j = 0; j < r; j++){
                    convolutionCore[i*r+j] = 0;
                }
            }
        switch (id)
        {
        case 1:
            from_r = r-1; from_c = r-1;
            for (int i = 0; i < r; i++){
                for (int j = 0; j < r-i; j++){
                    convolutionCore[i*r+j] = 1;
                }
            }
            break;
        case 2:
            from_r = r-1; from_c = 0;
            for (int i = 0; i < r; i++){
                for (int j = i; j < r; j++){
                    convolutionCore[i*r+j] = 1;
                }
            }
            break;
        case 3:
            from_r = 0; from_c = 0;
            for (int i = 0; i < r; i++){
                for (int j = r-i-1; j < r; j++){
                    convolutionCore[i*r+j] = 1;
                }
            }
            break;
        case 4:
            from_r = 0; from_c = r-1;
            for (int i = 0; i < r; i++){
                for (int j = 0; j < i+1; j++){
                    convolutionCore[i*r+j] = 1;
                }
            }
            break;
        default:
            cout << "Undefined behavier";
            break;
        }
    }
    
    void printCore(int* convolutionCore, int k){
        for (int i = 0; i < k; i++){
            for (int j = 0; j < k; j++){
                cout << convolutionCore[i*k+j];
            }
            cout << "\n";
        }
    }
    void printGrid(int* grid, int m, int n){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cout << grid[i*n+j];
            }
            cout << "\n";
        }
    }
};

int main(){
    int n;  // number of test cases
    //int r,c,k;  // rows, columns, power of gun
    cin >> n;
    int result[n] = {};
    solution e;  
    for (int i = 0; i < n; i++){
        result[i] = e.getMaxTargets();
    }
    for (int i = 0; i < n; i++){
        cout << result[i] << endl;
    }
    return 0;
}