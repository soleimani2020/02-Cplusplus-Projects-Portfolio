class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n = heights.size();

        int left = 0;
        int right = n - 1;
        int max_area = 0;

        while (left < right) {

            int width = right - left;
            int length = min(heights[left], heights[right]);
            int current_area = width * length;

            if (current_area > max_area) {
                max_area = current_area;
            }

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
