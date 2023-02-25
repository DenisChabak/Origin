#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Address {
    string city;
    string street;
    int house;
    int apartment;
};

bool compareAddress(const Address& a, const Address& b) {
    return a.city < b.city;
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int N;
    fin >> N;

    vector<Address> addresses(N);
    for (int i = 0; i < N; i++) {
        fin >> addresses[i].city >> addresses[i].street >> addresses[i].house >> addresses[i].apartment;
    }

    sort(addresses.begin(), addresses.end(), compareAddress);

    fout << N << endl;
    for (int i = 0; i < N; i++) {
        fout << addresses[i].city << ", " << addresses[i].street << ", " << addresses[i].house << ", " << addresses[i].apartment << endl;
    }

    fin.close();
    fout.close();

    return 0;
}


/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Address 
{
    string city;
    string street;
    string house_number;
    string apartment_number;
};

bool addressComparator(const Address& a, const Address& b) 
{
    return a.city <= b.city;
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");

    int numAddresses;
    inputFile >> numAddresses;

    vector<Address> addresses(numAddresses);

    for (int i = 0; i < numAddresses; i++) 
    {
        inputFile.ignore();
        getline(inputFile, addresses[i].city);
        getline(inputFile, addresses[i].street);
        getline(inputFile, addresses[i].house_number);
        getline(inputFile, addresses[i].apartment_number);
    }

    sort(addresses.begin(), addresses.end(), addressComparator);

    outputFile << numAddresses << endl;

    for (const Address& addr : addresses) 
    {
        outputFile << addr.city << ", " << addr.street << ", " << addr.house_number << ", " << addr.apartment_number << endl;
    }

    return 0;
}*/


/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Address {
    string city;
    string street;
    string house;
    string apartment;
};

class AddressBook {
public:
    AddressBook(const string& inputFile, const string& outputFile)
        : m_inputFile(inputFile), m_outputFile(outputFile) {}

    void readAddresses() {
        ifstream inputFile(m_inputFile);
        if (!inputFile.is_open()) {
            cerr << "Error opening input file\n";
            return;
        }

        int numAddresses;
        inputFile >> numAddresses;
        for (int i = 0; i < numAddresses; ++i) {
            Address address;
            getline(inputFile >> ws, address.city);
            getline(inputFile, address.street);
            getline(inputFile, address.house);
            getline(inputFile, address.apartment);
            m_addresses.push_back(address);
        }

        inputFile.close();
    }

    void writeAddresses() {
        ofstream outputFile(m_outputFile);
        if (!outputFile.is_open()) {
            cerr << "Error opening output file\n";
            return;
        }

        outputFile << m_addresses.size() << endl;
        for (auto it = m_addresses.rbegin(); it != m_addresses.rend(); ++it) {
            outputFile << it->city << ", " << it->street << ", " << it->house << ", " << it->apartment << endl;
        }

        outputFile.close();
    }

private:
    string m_inputFile;
    string m_outputFile;
    vector<Address> m_addresses;
};

int main() {
    AddressBook addressBook("in.txt", "out.txt");
    addressBook.readAddresses();
    addressBook.writeAddresses();
    return 0;
}*/
