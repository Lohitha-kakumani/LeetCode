class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstrow=false,firstcol = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    if(i == 0 ) firstrow = true;
                    if(j == 0 ) firstcol = true;
                    matrix[i][0] = 0;  //all i valued index will become 0 like i = 1,j=1 in this case so 1,0),(1,1),(1,2),2,1),(0,1)everything becomes 0 indicates the first example over there
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstrow){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        if(firstcol){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};