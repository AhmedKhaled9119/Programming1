#include <iostream>
#include <string>

// Subject interface
class Database {
public:
    virtual void query(const std::string& sql) = 0;
    virtual void insert(const std::string& data) = 0;
    virtual ~Database() {}
};

// RealSubject
class RealDatabase : public Database {
public:
    void query(const std::string& sql) override {
        std::cout << "Executing query: " << sql << std::endl;
        // Actual query execution logic
    }

    void insert(const std::string& data) override {
        std::cout << "Inserting data: " << data << std::endl;
        // Actual insert operation
    }
};

// Proxy
class ProtectionProxy : public Database {
private:
    RealDatabase* realDatabase;
    bool isAdmin;

public:
    ProtectionProxy(bool isAdmin) : realDatabase(new RealDatabase()), isAdmin(isAdmin) {}

    ~ProtectionProxy() {
        delete realDatabase;
    }

    void query(const std::string& sql) override {
        if (isAdmin) {
            realDatabase->query(sql);
        } else {
            std::cout << "Access denied. Insufficient privileges to execute query." << std::endl;
        }
    }

    void insert(const std::string& data) override {
        if (isAdmin) {
            realDatabase->insert(data);
        } else {
            std::cout << "Access denied. Insufficient privileges to insert data." << std::endl;
        }
    }
};

// Client
int main() {
    // Using Proxy
    ProtectionProxy proxy(true); // Simulating an admin user
    proxy.query("SELECT * FROM users");
    proxy.insert("John Doe, johndoe@example.com");
    
    ProtectionProxy proxy2(false); // Simulating a non-admin user
    proxy2.query("SELECT * FROM users");
    proxy2.insert("John Doe, johndoe@example.com");
    
    return 0;
}
