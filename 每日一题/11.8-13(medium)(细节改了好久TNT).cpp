class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size=matrix.size();
        int circal=size/2;//%2==0?size/2:size/2+1;
        for(int i=0;i<circal;i++){
            vector<int> temp;
            for(int j=i;j<size-i;j++)//存储每一圈最左边一列的元素
                temp.push_back(matrix[j][i]);
            for(int j=i;j<size-i;j++)//左列补上
                matrix[j][i]=matrix[size-1-i][j];
            for(int j=i+1;j<size-i;j++)//下行补上
                matrix[size-i-1][j]=matrix[size-j-1][size-i-1];
            for(int j=size-2-i;j>i;j--)//右列补上
                matrix[j][size-i-1]=matrix[i][j];
            int k=0;
            for(int j=size-i-1;j>i;j--)
                matrix[i][j]=temp[k++];
        }
    }
};
