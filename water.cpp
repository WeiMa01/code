#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
int stack_m[300], stack_n[300],top = 0;
    void dfs(vector<vector<char>>& grid, int a, int b) {
        int m = grid.size();
        int n = grid[0].size();
        cout << "m,n:  " << m << "  "<< n <<endl;
        top = 0;
        stack_m[top] = a;
        stack_n[top] = b;
        top++;
        while(top-1 >=0){
            int top_m = stack_m[top-1];
            int top_n = stack_n[top-1];
            top--;
            if(top_m-1 >=0 && grid[top_m-1][top_n] == '1'){
                cout << "a-1 >=0 && grid[a-1][b] == 1:  " << top_m-1 << "  "<< top_n <<endl;
                grid[top_m-1][top_n] = '0';
                stack_m[top] = top_m -1;
                stack_n[top] = top_n;
                top++;
            }
            if(top_m+1 <m && grid[top_m+1][top_n] == '1'){
                cout << "a-1 >=0 && grid[a-1][b] == 1:  " << top_m-1 << "  "<< top_n <<endl;
                grid[top_m+1][top_n] = '0';
                stack_m[top] = top_m +1;
                stack_n[top] = top_n;
                top++;
            }

            if(top_n-1 >=0 && grid[top_m][top_n-1] == '1'){
                cout << "a-1 >=0 && grid[a-1][b] == 1:  " << top_m-1 << "  "<< top_n <<endl;
                grid[top_m][top_n-1] = '0';
                stack_m[top] = top_m;
                stack_n[top] = top_n-1;
                top++;
            }

            if(top_n+1 < n && grid[top_m][top_n+1] == '1'){
                cout << "a-1 >=0 && grid[a-1][b] == 1:  " << top_m-1 << "  "<< top_n <<endl;
                grid[top_m][top_n+1] = '0';
                stack_m[top] = top_m;
                stack_n[top] = top_n+1;
                top++;
            }
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
            int m = grid.size();
            if (m == 0){
                return 0;
            }
            int n = grid[0].size();
            int landNum = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == '1'){
                        landNum ++;
                        grid[i][j] = '0';
                        dfs(grid, i, j);
                    }
                }
                
            }
            return landNum;
        }
    };

int main()
{

    vector<vector<char>> grid = {
                                {'1','1','0','0','0'},
                                {'1','1','0','0','0'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}
                                };

    Solution solution;
    int result = solution.numIslands(grid);
    cout << "result: " << result << endl;
    // for (int i = 0; i < result; i++) {
    //     cout << nums[i] << "   ";
    // }
    return 0;
}
