class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        for(auto it:queries){
            int row1=it[0],col1=it[1],row2=it[2],col2=it[3];
            for(int i=row1;i<=row2;i++){
                for(int j=col1;j<=col2;j++){
                    matrix[i][j]+=1;
                }
            }
        }
        return matrix;
    }
};