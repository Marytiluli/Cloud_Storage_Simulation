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
