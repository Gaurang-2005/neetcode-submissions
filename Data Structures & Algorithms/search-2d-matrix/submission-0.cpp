class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int sizeX = matrix.size();
        int sizeY = matrix[0].size();
        int right = sizeX * sizeY - 1;
        

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[mid / sizeY][mid % sizeY] == target) return true;
            if (matrix[mid / sizeY][mid % sizeY] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
