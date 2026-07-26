#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <memory>

using namespace std;


struct DataSet {

    string name;
    int* data;
    int size;
    chrono::time_point<chrono::steady_clock> creationTime;


    DataSet(const string& n, int s)
        : name(n), size(s), data(nullptr)
    {
        creationTime = chrono::steady_clock::now();
    }
};



class MemoryTracker {

private:

    vector<unique_ptr<DataSet>> activeSets;

    int totalAllocations;
    int totalDeallocations;


public:

    MemoryTracker()
        : totalAllocations(0), totalDeallocations(0)
    {
        cout << "Memory tracker initialized." << endl;
    }



    bool allocateDataSet(const string& name, int size)
    {

        if (size <= 0) {

            cout << "Error: Cannot allocate dataset '"
                 << name
                 << "' with size "
                 << size
                 << endl;

            return false;
        }


        for (auto& set : activeSets) {

            if (set->name == name) {

                cout << "Error: Dataset '"
                     << name
                     << "' already exists!"
                     << endl;

                return false;
            }
        }



        try {

            auto newSet = make_unique<DataSet>(name, size);

            newSet->data = new int[size];


            for (int i = 0; i < size; i++) {

                newSet->data[i] = i * 5;
            }


            activeSets.push_back(move(newSet));

            totalAllocations++;


            cout << "✓ Allocated dataset '"
                 << name
                 << "' with "
                 << size
                 << " elements"
                 << endl;


            return true;


        }
        catch (const bad_alloc& e) {


            cout << "✗ Allocation failed for dataset '"
                 << name
                 << "': "
                 << e.what()
                 << endl;


            return false;
        }
    }





    bool deallocateDataSet(const string& name)
    {

        for (auto it = activeSets.begin();
             it != activeSets.end();
             ++it) {


            if ((*it)->name == name) {


                cout << "Deallocating dataset '"
                     << name
                     << "'..."
                     << endl;


                delete[] (*it)->data;


                activeSets.erase(it);


                totalDeallocations++;


                cout << "✓ Dataset '"
                     << name
                     << "' deallocated successfully"
                     << endl;


                return true;
            }
        }


        cout << "✗ Error: Dataset '"
             << name
             << "' not found for deallocation!"
             << endl;


        return false;
    }





    void displayActiveDataSets()
    {

        cout << "\n=== Active DataSets ===" << endl;


        if (activeSets.empty()) {

            cout << "No active datasets." << endl;
            return;
        }



        for (auto& set : activeSets) {


            auto duration =
                chrono::steady_clock::now()
                - set->creationTime;


            auto seconds =
                chrono::duration_cast<chrono::seconds>(duration)
                .count();



            cout << "Dataset: "
                 << set->name
                 << " | Size: "
                 << set->size
                 << " | Age: "
                 << seconds
                 << "s"
                 << " | Address: "
                 << set->data
                 << endl;
        }
    }





    void detectMemoryLeaks()
    {

        cout << "\n=== Memory Leak Detection ===" << endl;


        cout << "Total allocations: "
             << totalAllocations
             << endl;


        cout << "Total deallocations: "
             << totalDeallocations
             << endl;


        cout << "Active datasets: "
             << activeSets.size()
             << endl;



        if (!activeSets.empty()) {


            cout << "⚠ WARNING: Memory leaks detected!"
                 << endl;


            cout << "Datasets not deallocated:"
                 << endl;



            for (auto& set : activeSets) {


                cout << "  - "
                     << set->name
                     << " ("
                     << set->size
                     << " elements)"
                     << endl;
            }

        }
        else {

            cout << "✓ No memory leaks detected - all datasets cleaned up!"
                 << endl;
        }
    }





    ~MemoryTracker()
    {

        cout << "\nMemoryTracker destructor called - cleaning up remaining datasets..."
             << endl;


        for (auto& set : activeSets) {

            cout << "Force cleaning dataset: "
                 << set->name
                 << endl;


            delete[] set->data;
        }


        activeSets.clear();
    }

};





int main()
{

    cout << "=== Memory Error Detection System ==="
         << endl;


    MemoryTracker tracker;



    cout << "\n--- Creating DataSets ---"
         << endl;


    tracker.allocateDataSet("Temperature", 100);
    tracker.allocateDataSet("Humidity", 50);
    tracker.allocateDataSet("Pressure", 75);



    tracker.displayActiveDataSets();



    cout << "\n--- Testing Error Detection ---"
         << endl;


    tracker.allocateDataSet("Temperature", 200);
    tracker.allocateDataSet("InvalidSet", -10);
    tracker.deallocateDataSet("NonExistent");



    cout << "\n--- Proper Cleanup ---"
         << endl;


    tracker.deallocateDataSet("Humidity");
    tracker.deallocateDataSet("Pressure");



    tracker.displayActiveDataSets();



    tracker.detectMemoryLeaks();



    cout << "\n--- Program Ending (remaining datasets will be cleaned by destructor) ---"
         << endl;


    return 0;
}
