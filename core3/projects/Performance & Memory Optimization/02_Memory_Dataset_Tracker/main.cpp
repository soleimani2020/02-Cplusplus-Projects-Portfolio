#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

// -------------------------------
// Task 1: DataSet Structure
// -------------------------------
struct DataSet {
    string name;   // Name of the dataset
    int* data;     // Pointer to dynamically allocated integer array
    int size;      // Number of elements in the dataset
    chrono::time_point<chrono::steady_clock> creationTime; // Timestamp when created

    // Constructor
    DataSet(const string& n, int s) : name(n), size(s), data(nullptr) {
        creationTime = chrono::steady_clock::now(); // Record creation time
    }
};

// -------------------------------
// Task 2: MemoryTracker Class
// -------------------------------
class MemoryTracker {
private:
    vector<DataSet*> activeSets; // Stores all active datasets
    int totalAllocations;        // Count of allocated datasets
    int totalDeallocations;      // Count of deallocated datasets

public:
    // Constructor
    MemoryTracker() : totalAllocations(0), totalDeallocations(0) {
        cout << "Memory tracker initialized." << endl;
    }

    // -------------------------------
    // Task 3: Allocate a Dataset
    // -------------------------------
    bool allocateDataSet(const string& name, int size) {
        if (size <= 0) {
            cout << "Error: Cannot allocate dataset '" << name << "' with size " << size << endl;
            return false;
        }

        // Check for duplicate dataset
        for (DataSet* set : activeSets) {
            if (set->name == name) {
                cout << "Error: Dataset '" << name << "' already exists!" << endl;
                return false;
            }
        }

        try {
            // Allocate DataSet object
            DataSet* newSet = new DataSet(name, size);

            // Allocate array
            newSet->data = new int[size];

            // Initialize array with sample data (0, 5, 10, ...)
            for (int i = 0; i < size; i++) {
                newSet->data[i] = i * 5;
            }

            // Add to active sets and update counter
            activeSets.push_back(newSet);
            totalAllocations++;

            cout << "✓ Allocated dataset '" << name << "' with " << size << " elements" << endl;
            return true;
        } catch (const bad_alloc& e) {
            cout << "✗ Allocation failed for dataset '" << name << "': " << e.what() << endl;
            return false;
        }
    }

    // -------------------------------
    // Task 4: Deallocate a Dataset
    // -------------------------------
    bool deallocateDataSet(const string& name) {
        for (auto it = activeSets.begin(); it != activeSets.end(); ++it) {
            if ((*it)->name == name) {
                DataSet* set = *it;

                cout << "Deallocating dataset '" << name << "'..." << endl;

                delete[] set->data;  // Delete the data array
                delete set;          // Delete the DataSet object

                activeSets.erase(it); // Remove from vector
                totalDeallocations++;

                cout << "✓ Dataset '" << name << "' deallocated successfully" << endl;
                return true;
            }
        }

        cout << "✗ Error: Dataset '" << name << "' not found for deallocation!" << endl;
        return false;
    }

    // -------------------------------
    // Task 5: Display Active Datasets
    // -------------------------------
    void displayActiveDataSets() {
        cout << "\n=== Active DataSets ===" << endl;
        if (activeSets.empty()) {
            cout << "No active datasets." << endl;
            return;
        }

        for (DataSet* set : activeSets) {
            auto duration = chrono::steady_clock::now() - set->creationTime;
            auto seconds = chrono::duration_cast<chrono::seconds>(duration).count();

            cout << "Dataset: " << set->name
                 << " | Size: " << set->size
                 << " | Age: " << seconds << "s"
                 << " | Address: " << set->data << endl;
        }
    }

    // -------------------------------
    // Task 6: Detect Memory Leaks
    // -------------------------------
    void detectMemoryLeaks() {
        cout << "\n=== Memory Leak Detection ===" << endl;
        cout << "Total allocations: " << totalAllocations << endl;
        cout << "Total deallocations: " << totalDeallocations << endl;
        cout << "Active datasets: " << activeSets.size() << endl;

        if (!activeSets.empty()) {
            cout << "⚠ WARNING: Memory leaks detected!" << endl;
            cout << "Datasets not deallocated:" << endl;
            for (DataSet* set : activeSets) {
                cout << "  - " << set->name << " (" << set->size << " elements)" << endl;
            }
        } else {
            cout << "✓ No memory leaks detected - all datasets cleaned up!" << endl;
        }
    }

    // -------------------------------
    // Task 7: Destructor
    // -------------------------------
    ~MemoryTracker() {
        cout << "\nMemoryTracker destructor called - cleaning up remaining datasets..." << endl;
        for (DataSet* set : activeSets) {
            cout << "Force cleaning dataset: " << set->name << endl;
            delete[] set->data;
            delete set;
        }
        activeSets.clear();
    }
};

// -------------------------------
// Task 8: Main Function
// -------------------------------
int main() {
    cout << "=== Memory Error Detection System ===" << endl;

    MemoryTracker tracker;

    // Allocate datasets
    cout << "\n--- Creating DataSets ---" << endl;
    tracker.allocateDataSet("Temperature", 100);
    tracker.allocateDataSet("Humidity", 50);
    tracker.allocateDataSet("Pressure", 75);

    tracker.displayActiveDataSets();

    // Test error detection
    cout << "\n--- Testing Error Detection ---" << endl;
    tracker.allocateDataSet("Temperature", 200); // duplicate
    tracker.allocateDataSet("InvalidSet", -10);  // invalid size
    tracker.deallocateDataSet("NonExistent");    // non-existent

    // Proper cleanup
    cout << "\n--- Proper Cleanup ---" << endl;
    tracker.deallocateDataSet("Humidity");
    tracker.deallocateDataSet("Pressure");

    tracker.displayActiveDataSets();

    // Memory leak check
    tracker.detectMemoryLeaks();

    cout << "\n--- Program Ending (remaining datasets will be cleaned by destructor) ---" << endl;
    return 0;
}
