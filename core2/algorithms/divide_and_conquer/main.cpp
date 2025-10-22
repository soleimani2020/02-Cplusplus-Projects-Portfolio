#include <iostream>
#include <vector>
using namespace std;



class MergeSorter {
public:

    void sort(vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
    }

private:

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Divide the array into two halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Conquer by merging the sorted halves
            merge(arr, left, mid, right);
        }
    }

    // Merge two sorted halves
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        // Merge the two halves
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        // Copy any remaining elements
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
};

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}



int main() {
    vector<int> numbers = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    printArray(numbers);

    MergeSorter sorter;
    sorter.sort(numbers);

    cout << "Sorted array: ";
    printArray(numbers);

    return 0;
}

