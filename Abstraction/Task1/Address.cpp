#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Address {
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;
};

class AddressBook {
public:
    void readFromFile(const string& filename);
    void writeToFile(const string& filename);
private:
    int numAddresses;
    vector<Address> addresses;
};

void AddressBook::readFromFile(const string& filename) {
    ifstream fin(filename);
    fin >> numAddresses;
    for (int i = 0; i < numAddresses; i++) {
        Address addr;
        fin.ignore(); // skip newline after numAddresses
        getline(fin, addr.city);
        getline(fin, addr.street);
        fin >> addr.houseNumber >> addr.apartmentNumber;
        addresses.push_back(addr);
    }
    fin.close();
}

void AddressBook::writeToFile(const string& filename) {
    ofstream fout(filename);
    fout << numAddresses << endl;
    for (int i = numAddresses - 1; i >= 0; i--) {
        Address addr = addresses[i];
        fout << addr.city << ", " << addr.street << ", " << addr.houseNumber << ", " << addr.apartmentNumber << endl;
    }
    fout.close();
}

int main() {
    AddressBook book;
    book.readFromFile("in.txt");
    book.writeToFile("out.txt");
    return 0;
}


/*#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Address {
    string city;
    string street;
    string house_number;
    string apartment_number;
};

class AddressBook {
public:
    AddressBook(string filename);
    void outputToFile(string filename);

private:
    int n;
    vector<Address> addresses;
};

AddressBook::AddressBook(string filename) {
    ifstream infile(filename);
    infile >> n;

    for (int i = 0; i < n; i++) {
        Address address;
        getline(infile, address.city);
        getline(infile, address.street);
        getline(infile, address.house_number);
        getline(infile, address.apartment_number);

        addresses.push_back(address);
    }

    infile.close();
}

void AddressBook::outputToFile(string filename) {
    ofstream outfile(filename);
    outfile << n << endl;

    for (int i = n - 1; i >= 0; i--) {
        outfile << addresses[i].city << ", " << addresses[i].street << ", " << addresses[i].house_number << ", " << addresses[i].apartment_number << endl;
    }

    outfile.close();
}

int main() {
    AddressBook book("in.txt");
    book.outputToFile("out.txt");

    return 0;
}*/
