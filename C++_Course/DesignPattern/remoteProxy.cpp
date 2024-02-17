// #include <iostream>

// using namespace std; 

// class Subject 
// {
// public:
// 	virtual void request() = 0;
// 	virtual ~Subject() {}
// };
 
// class RealSubject : public Subject 
// {
// public:
// 	void request() { 
// 		cout << "RealSubject.request()" << endl; 
// 	}
// };
 
// class Proxy : public Subject 
// {
// private:
// 	Subject* realSubject;
// public:
// 	Proxy() : realSubject (new RealSubject()) 
// 	{}
// 	~Proxy() { 
// 		delete realSubject; 
// 	}
// 	// Forward calls to the RealSubject:
// 	void request() { 
// 		realSubject->request(); 
// 	}
// };
 
// int main() {
// 	Proxy p;
// 	p.request();
//     p.request();

// 	p.request();

// }

#include <iostream>
#include <string>

// Subject interface
class Printer {
public:
    virtual void print(const std::string& document) = 0;
    virtual ~Printer() {}
};

// RealSubject
class RemotePrinter : public Printer {
public:
    void print(const std::string& document) override {
        std::cout << "Printing document: " << document << std::endl;
        // Simulate printing document on remote printer
    }
};

// Proxy
class RemotePrinterProxy : public Printer {
private:
    RemotePrinter* remotePrinter;

public:
    RemotePrinterProxy() : remotePrinter(nullptr) {}

    ~RemotePrinterProxy() {
        delete remotePrinter;
    }

    void print(const std::string& document) override {
        if (!remotePrinter) {
            remotePrinter = new RemotePrinter();
        }
        remotePrinter->print(document);
    }
};

// Client
int main() {
    // Using Proxy
    RemotePrinterProxy proxy;
    proxy.print("SampleDocument.pdf");
        proxy.print("SampleDocument.pdf");

    return 0;
}
