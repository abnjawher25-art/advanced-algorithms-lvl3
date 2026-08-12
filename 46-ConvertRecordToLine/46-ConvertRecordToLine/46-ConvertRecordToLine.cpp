#include <iostream>
#include <string>

using namespace std;

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


int main()
{
    cout << "Enter Client Data:\n\n";

    sClient Client = readNewClient();

    cout << "\n\nThe Client Record for saving is:\n";
    cout << ConvetRecordToLine(Client) << endl;

    cout << "\n\nPress key to exit ...";
    system("pause>0");

    return 0;
}