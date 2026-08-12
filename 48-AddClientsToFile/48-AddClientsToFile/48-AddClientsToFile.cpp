#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0.0;
};


sClient readNewClient()
{
    sClient client;

    cout << "Enter Account Number: ";
   
    getline(cin >> ws, client.AccountNumber);

    cout << "Enter Pin Code: ";
    getline(cin, client.PinCode);

    cout << "Enter Client Name: ";
    getline(cin, client.Name);

    cout << "Enter Client Phone Number: ";
    getline(cin, client.Phone);

    cout << "Enter Account Balance: ";
    cin >> client.AccountBalance;

    return client;
}


string ConvetRecordToLine(sClient client, string seperator = "#//#")
{
    string sClientRecord = "";

    sClientRecord += client.AccountNumber + seperator;
    sClientRecord += client.PinCode + seperator;
    sClientRecord += client.Name + seperator;
    sClientRecord += client.Phone + seperator;
    sClientRecord += to_string(client.AccountBalance);

    return sClientRecord;
}


void AddDataLineToFile(string FileName, string sTDataLine)
{
    fstream MyFile;

   
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << sTDataLine << endl;
        MyFile.close();
    }
}


void AddNewClient()
{
    sClient Client = readNewClient();
    AddDataLineToFile(ClientsFileName, ConvetRecordToLine(Client));
}


void AddClients()
{
    char AddMore = 'Y';
    do
    {
        system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();

        cout << "\nClient Added Successfully, Do you want to add more clients? Y/N: ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}



int main()
{
    AddClients();

    cout << "\n\nPress key to exit ...";
    system("pause>0");

    return 0;
}