   int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        int ans = INT_MIN;
        for(int row =0 ; row < m ; row++){

            for(int col  = 0 ; col < n ; col++){

                if(matrix[row][col] == 1 && row >0){
                    matrix[row][col] += matrix[row-1][col]; // get continuous 1's

                }
            }
            
            vector<int> height = matrix[row];
            sort(begin(height) , end(height) , greater<int>());

            for(int i = 0 ; i < n ; i++){
                int base = i+1;
                int hei = height[i] * base;

                ans = max(ans , hei);
            }
        }
        return ans;
    }
