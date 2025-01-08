// Include iostream header
#include <iostream>

// Include fstream header
#include <fstream>

// Include unordered_map header
#include <unordered_map>

// Include string header
#include <string>

// Include vector header
#include <vector>

// Start using namespace std
using namespace std;

// Define File struct
struct File {
    string name;
    string content;
};

// Start CloudStorage class
class CloudStorage {
private:
    unordered_map<string, File> storage;
    
public:
    // Add uploadFile method
    void uploadFile(const string& fileName, const string& content) {
        if (storage.find(fileName) != storage.end()) {
            cout << "Error: File already exists.\n";
            return;
        }
        File file = {fileName, content};
        storage[fileName] = file;
        cout << "File '" << fileName << "' uploaded successfully.\n";
    }
    
    // Add retrieveFile method
    void retrieveFile(const string& fileName) {
        if (storage.find(fileName) == storage.end()) {
            cout << "Error: File not found.\n";
            return;
        }
        cout << "File Content of '" << fileName << "':\n";
        cout << storage[fileName].content << endl;
    }
    
    // Add deleteFile method
    void deleteFile(const string& fileName) {
        if (storage.find(fileName) == storage.end()) {
            cout << "Error: File not found.\n";
            return;
        }
        storage.erase(fileName);
        cout << "File '" << fileName << "' deleted successfully.\n";
    }
    
    // Add listFiles method
    void listFiles() {
        if (storage.empty()) {
            cout << "No files found in storage.\n";
            return;
        }
        cout << "Files in storage:\n";
        for (const auto& pair : storage) {
            cout << "- " << pair.first << endl;
        }
    }
};

// Start main function
int main() {
    CloudStorage cloud;
    int choice;
    string fileName, content;
    
    // Add menu loop
    do {
        cout << "\nCloud Storage Simulation\n";
        cout << "1. Upload File\n";
        cout << "2. Retrieve File\n";
        cout << "3. Delete File\n";
        cout << "4. List Files\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();