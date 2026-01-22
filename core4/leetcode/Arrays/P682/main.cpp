#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(const vector<string>& operations) {
        vector<int> result;

        for (const auto& op : operations) {
            if (op == "C") {
                if (!result.empty()) result.pop_back(); // remove last element
            }
            else if (op == "D") {
                result.push_back(2 * result.back()); // double last score
            }
            else if (op == "+") {
                int last1 = result.back();
                int last2 = result[result.size() - 2];
                result.push_back(last1 + last2); // sum last two scores
            }
            else {
                result.push_back(stoi(op)); // convert string to int and add
            }
        }

        int sum = 0;
        for (auto score : result) sum += score; // sum all scores
        return sum;
    }
};

int main() {
    vector<string> operations = {"5","2","C","D","+"};
    Solution obj;
    cout << "Sum of operations: " << obj.calPoints(operations);
}
