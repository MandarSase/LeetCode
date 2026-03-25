class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;

        vector<long long> rowSum(m, 0), colSum(n, 0);

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        
        if (total % 2 != 0) return false;

        long long target = total / 2;

        
        long long sum = 0;
        for (int i = 0; i < m - 1; i++) {  
            sum += rowSum[i];
            if (sum == target) return true;
        }

        
        sum = 0;
        for (int j = 0; j < n - 1; j++) {  
            sum += colSum[j];
            if (sum == target) return true;
        }

        return false;
    }
};