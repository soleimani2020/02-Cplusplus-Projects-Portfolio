#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// ========================================
// MODERNIZED CODE - XYZ Software Solutions
// SOLUTION: Refactored using smart pointers and modern C++
// ========================================

// Modern Resource Classes with RAII
class DatabaseConnection {
private:
    int connectionId;
    bool connected;
    bool inUse = false;
   
public:
    DatabaseConnection(int ID){
        connectionId = ID;
        connected = true;
        cout << "Connection with ID " << connectionId << " opened.";
    }
    
    
    void connect(){
        if (connected) return;  // Already connected
       
        connected = true;
        cout << "DatabaseConnection " << connectionId << " connected." << endl;
    }
   
    void disconnect(){
        if (!connected) return;  // Already disconnected
       
        connected = false;
        cout << "DatabaseConnection " << connectionId << " disconnected." << endl;
    }
   
    void query(const string& sql) {
        if (connected) {
            cout << "Executing query on DatabaseConnection " << connectionId
                 << ": " << sql << endl;
        } else {
            cout << "Cannot execute query: DatabaseConnection " << connectionId
                 << " is disconnected." << endl;
        }
    }
   
    ~DatabaseConnection(){
        // connected = false;
        disconnect();
        cout << "Connection with ID " << connectionId << " closed.";
    }
};



class ConnectionManager{
public:
    vector<shared_ptr<DatabaseConnection>> connectionPool;
    
    
    ConnectionManager(){
        int N=10;
        // create N connections
        for(int i=0; i < N ; i++){
            // Creates real DatabaseConnection objects
            shared_ptr<DatabaseConnection> ptr = make_shared<DatabaseConnection>(i+1);
            // Stores them in connectionPool
            connectionPool.push_back(ptr);
        }
    }
    
    shared_ptr<DatabaseConnection> getConnection(){
        for(const auto& connection: connectionPool){
            if(!connection->inUse){       // if available
                connection->inUse = true; // mark as in use
                return connection;        // return it
            }
        }
        return nullptr; // all busy
    }
    
    void releaseConnection(shared_ptr<DatabaseConnection> connection){
        connection->inUse = false;
    }
    
    
    
};

    



int main(){
   
    shared_ptr<DatabaseConnection> ptr1 = make_shared<DatabaseConnection>(42);
    cout << "Reference count : " << ptr1.use_count() << endl;
   
    shared_ptr<DatabaseConnection> ptr2 = ptr1;
    cout << "Reference count : " << ptr2.use_count() << endl;
   
    // ===== Task 1.2: unique_ptr with custom deleter =====
    FILE* file = fopen("example.txt", "w");
    unique_ptr<FILE, decltype(&fclose)> filePtr(file, &fclose);
    fprintf(filePtr.get(), "Hello World\n");
   

   
    weak_ptr <DatabaseConnection> wptr  = ptr1; // Observe, but don't own
    if(auto locked = wptr.lock()){
        cout << "Reference count: " << locked.use_count() << endl;
    } else {
        cout << "Resource no longer exists." << endl;
    }
   
   
    // TEST
    ptr1->disconnect();
    ptr1->query("SELECT * FROM users");
   
    ptr1->connect();  // reconnect
    ptr1->query("SELECT * FROM users");  // now executes
   
   
   // TEST: CONNECTION POOL 
   shared_ptr<ConnectionManager> manager = make_shared<ConnectionManager>();
   // Get a connection from the pool : acquire → use → release
    shared_ptr<DatabaseConnection> conn = manager->getConnection();
    
    if (conn) {
        // Simulate using the connection
        conn->query("SELECT * FROM users");
        
        // Release the connection back to the pool
        manager->releaseConnection(conn);
    } else {
        cout << "No available connections in the pool." << endl;
    }
   
   // Release the connection back to the pool

    auto conn = manager->getConnection();
    if (conn) {
        conn->query("SELECT * FROM users");
        manager->releaseConnection(conn);
    } else {
        cout << "No available connections in the pool." << endl;
    }
   
   
}
