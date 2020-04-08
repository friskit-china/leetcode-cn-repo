#include <iostream>
#include <vector>
using namespace std;

// 这个方法才符合题目对时间复杂度的要求
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0){
            return 0;
        }
        int k = costs[0].size();
        if (k == 0){
            return 0;
        }

        int f[n][k];

        for (int j = 0; j < k; ++j){
            f[0][j] = costs[0][j];
        }

        for (int i = 1; i < n; ++i){
            int last_cost = INT32_MAX;
            int last_color = -1;
            int second_to_last_cost = INT32_MAX;
            int second_to_last_color = -1;

            for (int j = 0; j < k; ++j){
                if (f[i - 1][j] < last_cost){
                    second_to_last_cost = last_cost;
                    second_to_last_color = last_color;
                    last_cost = f[i - 1][j];
                    last_color = j;
                }else{
                    if (f[i - 1][j] < second_to_last_cost){
                        second_to_last_cost = f[i - 1][j];
                        second_to_last_color = j;
                    }
                }
            }

            for (int j = 0; j < k; ++j){

                if (j != last_color){
                    f[i][j] = last_cost + costs[i][j];
                }else{
                    f[i][j] = second_to_last_cost + costs[i][j];
                }
            }
            
        }

        int current_min = f[n - 1][0];
        for (int i = 1; i < k; ++i){
            current_min = min(current_min, f[n - 1][i]);
        }
        return current_min;
    }
};

int main(){
    Solution sl;
    // vector<vector<int>> costs = {
    //     {1, 5, 3},
    //     {2, 9, 4}
    // };
    
    // vector<vector<int>> costs = {
    //     {15, 17, 15, 20, 7, 16, 6, 10, 4, 20, 7, 3, 4},
    //     {11, 3, 9, 13, 7, 12, 6, 7, 5, 1, 7, 18, 9},
    // };

    vector<vector<int>> costs{
        {19,3,18,4,13,1,12,6,3,12,3,3,9},
        {11,5,9,16,2,19,15,10,13,20,15,2,13},
        {19,6,18,7,6,10,11,13,8,19,4,14,18},
        {3,18,18,9,3,6,18,11,7,4,13,3,12}
    };
    cout<<sl.minCostII(costs)<<endl;
    return 0;
}