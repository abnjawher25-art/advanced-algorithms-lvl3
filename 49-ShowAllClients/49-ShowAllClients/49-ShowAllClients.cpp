#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

const string ClientFileName = "Clients.txt";


struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0.0;
};


vector<string> splitString(string str, string delimiter)
{
    vector<string> vecSplitString;
    short position = 0;
    string StringWord;

    while ((position = str.find(delimiter)) != std::string::npos)
    {
        StringWord = str.substr(0, position);

        if (StringWord != "")
        {
            vecSplitString.push_back(StringWord);
        }

        str.erase(0, position + delimiter.length());
    }

    if (str != "")
    {
        vecSplitString.push_back(str);
    }

    return vecSplitString;
}


sClient ConvetLineToRecord(string Line, string seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData = splitString(Line, seperator);

   
    if (vClientData.size() >= 5)
    {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);
    }

    return Client;
}


vector<sClient> LoadClientsDataFromFile(string FileName)
{
    vector<sClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    
    if (!MyFile.is_open())
    {
        MyFile.clear();
        MyFile.open(FileName, ios::out);
        MyFile.close();
        return vClients;
    }

    string Line;
    sClient Client;

    while (getline(MyFile, Line))
    {
        if (Line != "") 
        {
            Client = ConvetLineToRecord(Line);
            vClients.push_back(Client);
        }
    }

    MyFile.close();
    return vClients;
}


void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}


void PrintAllClients(const vector<sClient>& vClients)
{
    cout << "\n\t\t\t\t\tClients List (" << vClients.size() << ") Client(s).\n";
    cout << "____________________________________________________________________________________________________\n\n";

   
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone Number";
    cout << "| " << left << setw(12) << "Balance" << endl;

    cout << "____________________________________________________________________________________________________\n";

    if (vClients.empty())
    {
        cout << "\t\t\t\tNo Clients Available In the System!\n";
    }
    else
    {
        for (const sClient& Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl; 
        }
    }

    cout << "____________________________________________________________________________________________________\n";
}



int main()
{
    vector<sClient> vClients = LoadClientsDataFromFile(ClientFileName);

    PrintAllClients(vClients);

    cout << "\n\nPress key to exit ...";
    system("pause>0");

    return 0;
}