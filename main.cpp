/*
Project Name: Bank Management System
Created By: Ankit Kumar
*/


#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<limits>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;


// Function Declarations

void greeting();
void main_menu();
void create_account();
void account_created_message(string an, string pin, string fname, string lname, string balance);
string addBalance(string currBalance, string deposit);
void check_balance();
void close_account();
void widthdraw_balance();
string getDiff(string e, string balance);
bool amountInsufficient(string balance, string e);



// Greeting

void greeting(){
    system("cls");
    cout<<"========================================================\n";
    cout<<"||                                                    ||\n";
    cout<<"||                 WELCOME TO YOLO BANK               ||\n";
    cout<<"||                                                    ||\n";
    cout<<"========================================================\n\n\n";
}




// Account Created

void create_account(){

    greeting();
    cout<<"--------------------------------------------------------\n";
    cout<<"|                     Create Account                   |\n";
    cout<<"--------------------------------------------------------\n\n";

    cout<<"--------------------------------------------------------\n";
    cout<<"Enter Exit To Return To Main Menu Any Time.\n";
    cout<<"--------------------------------------------------------\n\n";

    string account_number, pin, fname, lname, balance;
    
    bool input = true;
    while(input){

        cout<<"Enter Your 3 Digit Account Number: ";
        getline(cin , account_number);

        if(account_number == "Exit" || account_number == "exit" || account_number == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }


        if(account_number.length() != 3){
            cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<3;i++){
            if(!(account_number[i]>='0' && account_number[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }

        ifstream file;
        file.open("Accounts.txt", ios::in);

        string a,b,c,d,e;

        bool exists = false;
        while(file){
            file >> a >> b >> c >> d >> e;
            if(a.empty()) break;
            if(a == account_number){
                cout<<"\033[31m"<<"Error: Account Number Already Exists."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                exists = true;
                break;
            }
        }
        file.close();

        if(exists) continue;

        if(check) break;
    }
    
    
    input = true;
    while(input){

        cout<<"Enter Your 4 Digit Pin: ";
        getline(cin, pin);

        if(pin == "Exit" || pin == "exit" || pin == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(pin.length() != 4){
            cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<4;i++){
            if(!(pin[i]>='0' && pin[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }
        
        if(check) break;
    }
    

    input = true;
    while(input){

        cout<<"Enter Your First Name: ";
        getline(cin, fname);

        if(fname == "Exit" || fname == "exit" || fname == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(fname.empty()){
            cout<<"\033[31m"<<"Error: Invalid Name."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<fname.length();i++){
            if( !((fname[i] >= 'a' && fname[i]<='z') || (fname[i] >= 'A' && fname[i] <= 'Z'))){
                cout<<"\033[31m"<<"Error: Invalid Name."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }
        
        if(check) break;
    }


    input = true;
    while(input){

        cout<<"Enter Your Last Name: ";
        getline(cin, lname);

        if(lname == "Exit" || lname == "exit" || lname == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(lname.empty()){
            cout<<"\033[31m"<<"Error: Invalid Name."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<lname.length();i++){
            if( !((lname[i] >= 'a' && lname[i]<='z') || (lname[i] >= 'A' && lname[i] <= 'Z'))){
                cout<<"\033[31m"<<"Error: Invalid Name."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }
        
        if(check) break;
    }


    input = true;
    while(input){

        cout<<"Enter Your Initial Balance: ";
        getline(cin, balance);

        if(balance == "Exit" || balance == "exit" || balance == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(balance.empty()){
            cout<<"\033[31m"<<"Error: Invalid Balance."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<balance.length();i++){
            if(!(balance[i]>='0' && balance[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Balance."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }

        if(check) break;
    }
    

    ofstream output;
    output.open("Accounts.txt" , ios::app);
    output << account_number << " " << pin << " " << fname << " " << lname << " " << balance << "\n";
    output.close();

    account_created_message(account_number, pin, fname, lname, balance);

}

void account_created_message(string an, string pin, string fname, string lname, string balance){
    greeting();
    cout<<"--------------------------------------------------------\n";
    cout<<"|            Account Created Successfully              |\n";
    cout<<"--------------------------------------------------------\n\n";

    cout<<"Account Number: "<<an<<"\n";
    cout<<"PIN: "<<pin<<"\n";
    cout<<"First Name: "<<fname<<"\n";
    cout<<"Last Name: "<<lname<<"\n";
    cout<<"Balance: "<<balance<<"\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"\033[32m"<<"Account Created Successfully."<<"\033[0m"<<"\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"Press Enter To Continue...\n";

}





// Deposit Money

void deposit_money(){

    greeting();

    cout<<"--------------------------------------------------------\n";
    cout<<"|                     Deposit Money                    |\n";
    cout<<"--------------------------------------------------------\n\n";

    cout<<"--------------------------------------------------------\n";
    cout<<"Enter Exit To Return To Main Menu Any Time.\n";
    cout<<"--------------------------------------------------------\n\n";

    string account_number, pin, balance, newBalance;
    string a,b,c,d,e;

    bool input = true;
    while(input){

        cout<<"Enter Your 3 Digit Account Number: ";
        getline(cin , account_number);

        if(account_number == "Exit" || account_number == "exit" || account_number == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(account_number.length() != 3){
            cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<3;i++){
            if(!(account_number[i]>='0' && account_number[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }
        if(!check) continue;

        ifstream file;
        file.open("Accounts.txt", ios::in);

        bool exists = false;
        while(file){
            file >> a >> b >> c >> d >> e;
            if(a.empty()) break;
            if(a == account_number){ 
                exists = true;
                break;
            }
        }
        file.close();

        if(!exists){
            cout<<"\033[31m"<<"Error: Account Doesn't Exist ."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r"; 
        }

        if(exists) break;
    }


    input = true;
    while(input){

        cout<<"Enter Your 4 Digit Pin: ";
        getline(cin, pin);

        if(pin == "Exit" || pin == "exit" || pin == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(pin.length() != 4){
            cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<4;i++){
            if(!(pin[i]>='0' && pin[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }

        if(!check) continue;
        
        if(pin != b){
            cout<<"\033[31m"<<"Error: Wrong Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            check = false;
        }

        if(check) break;
    }

    input = true;
    while(input){

        cout<<"Enter Balance To Be Deposited: ";
        getline(cin, balance);

        if(balance == "Exit" || balance == "exit" || balance == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(balance.empty()){
            cout<<"\033[31m"<<"Error: Invalid Balance."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<balance.length();i++){
            if(!(balance[i]>='0' && balance[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Balance."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }

        if(check) break;
    }

    cout<<"--------------------------------------------------------\n";

    newBalance = addBalance(e, balance);
    
    cout<< "\033[32m" <<"Amount Added Successfully" << "\033[0m" << endl;
    cout << "New Balance : " << newBalance << endl;
    cout<<"--------------------------------------------------------\n";
    cout<<"Press Enter To Continue.\n";

    vector<string> lines;
    string newLine = a + " " + b + " " + c + " " + d + " " + newBalance;
    
    ifstream file;
    file.open("Accounts.txt", ios::in);

    while(file){
        string a,b,c,d,e;
        file >> a >> b >> c >> d >> e;
        if(a.empty()) break;
        if(a == account_number) lines.push_back(newLine);
        else lines.push_back((a + " " + b + " " + c + " " + d + " " + e));
    }

    file.close();

    ofstream output;
    output.open("Accounts.txt", ios::out);

    for(int i=0;i<lines.size();i++){
        output << lines[i] << '\n';
    }

    output.close();
}



string addBalance(string currBalance, string deposit){
    string newBalance = "";
    
    int n = currBalance.length(), m = deposit.length();
    int i = n-1, j = m-1;

    int carry = 0;

    while(i >= 0 && j >= 0){
        int sum = (currBalance[i] - '0') + (deposit[j] - '0') + carry;
        int digit = sum%10;
        carry = sum/10;
        newBalance += ('0' + digit);
        i--;
        j--;
    }

    while(i >= 0){
        int sum = (currBalance[i] - '0') + carry;
        int digit = sum%10;
        carry = sum/10;
        newBalance += ('0' + digit);
        i--;
    }    

    while(j >= 0){
        int sum = (deposit[j] - '0') + carry;
        int digit = sum%10;
        carry = sum/10;
        newBalance += ('0' + digit);
        j--;
    }

    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        newBalance += ('0' + digit);
    }

    reverse(newBalance.begin(), newBalance.end());

    return newBalance;
}



// Withdraw Balance


void widthdraw_balance(){

    greeting();

    cout<<"--------------------------------------------------------\n";
    cout<<"|                   Withdraw Balance                   |\n";
    cout<<"--------------------------------------------------------\n\n";

    cout<<"--------------------------------------------------------\n";
    cout<<"Enter Exit To Return To Main Menu Any Time.\n";
    cout<<"--------------------------------------------------------\n\n";

    string account_number, pin, balance, newBalance;
    string a,b,c,d,e;

    bool input = true;
    while(input){

        cout<<"Enter Your 3 Digit Account Number: ";
        getline(cin , account_number);

        if(account_number == "Exit" || account_number == "exit" || account_number == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(account_number.length() != 3){
            cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<3;i++){
            if(!(account_number[i]>='0' && account_number[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }
        if(!check) continue;

        ifstream file;
        file.open("Accounts.txt", ios::in);

        bool exists = false;
        while(file){
            file >> a >> b >> c >> d >> e;
            if(a.empty()) break;
            if(a == account_number){ 
                exists = true;
                break;
            }
        }
        file.close();

        if(!exists){
            cout<<"\033[31m"<<"Error: Account Doesn't Exist ."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r"; 
        }

        if(exists) break;
    }


    input = true;
    while(input){

        cout<<"Enter Your 4 Digit Pin: ";
        getline(cin, pin);

        if(pin == "Exit" || pin == "exit" || pin == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(pin.length() != 4){
            cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<4;i++){
            if(!(pin[i]>='0' && pin[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }

        if(!check) continue;
        
        if(pin != b){
            cout<<"\033[31m"<<"Error: Wrong Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            check = false;
        }

        if(check) break;
    }

    input = true;
    while(input){

        cout<<"Enter Balance To Withdraw: ";
        getline(cin, balance);

        if(balance == "Exit" || balance == "exit" || balance == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(balance.empty()){
            cout<<"\033[31m"<<"Error: Invalid Balance."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<balance.length();i++){
            if(!(balance[i]>='0' && balance[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Balance."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }

        if(!check) continue;

        if(amountInsufficient(balance,e)){
            cout<<"\033[31m"<<"Error: Insufficient Balance."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        if(check) break;
    }

    newBalance = getDiff(e,balance);

    cout<<"--------------------------------------------------------\n";
    cout<< "\033[32m" <<"Amount Withdrew Successfully" << "\033[0m" << endl;
    cout << "New Balance : " << newBalance << endl;
    cout<<"--------------------------------------------------------\n";
    cout<<"Press Enter To Continue.\n";

    vector<string> lines;
    string newLine = a + " " + b + " " + c + " " + d + " " + newBalance;
    
    ifstream file;
    file.open("Accounts.txt", ios::in);

    while(file){
        string a,b,c,d,e;
        file >> a >> b >> c >> d >> e;
        if(a.empty()) break;
        if(a == account_number) lines.push_back(newLine);
        else lines.push_back((a + " " + b + " " + c + " " + d + " " + e));
    }

    file.close();

    ofstream output;
    output.open("Accounts.txt", ios::out);

    for(int i=0;i<lines.size();i++){
        output << lines[i] << '\n';
    }

    output.close();

}


bool amountInsufficient(string balance, string e) {
    if (balance.size() > e.size()) return true;
    if (balance.size() < e.size()) return false;

    for (int i = 0; i < balance.size(); i++) {
        if (balance[i] > e[i]) return true;  
        if (balance[i] < e[i]) return false; 
    }

    return false;
}

string getDiff(string e, string balance) {
    string newBalance = "";
    int n1 = e.length(), n2 = balance.length();
    int diff = n1 - n2;
    int carry = 0;

    for (int i = n2 - 1; i >= 0; i--) {
        int sub = ((e[i + diff] - '0') - (balance[i] - '0') - carry);
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        newBalance.push_back(sub + '0');
    }

    for (int i = diff - 1; i >= 0; i--) {
        if (e[i] == '0' && carry) {
            newBalance.push_back('9');
            continue;
        }
        int sub = ((e[i] - '0') - carry);
        if (sub >= 0) {
            newBalance.push_back(sub + '0');
            carry = 0;
        }
    }

    reverse(newBalance.begin(), newBalance.end());

    while (newBalance.length() > 1 && newBalance[0] == '0') {
        newBalance.erase(newBalance.begin());
    }

    return newBalance;
}



// Check Balance

void check_balance(){

    greeting();

    cout<<"--------------------------------------------------------\n";
    cout<<"|                     Check Balance                    |\n";
    cout<<"--------------------------------------------------------\n\n";

    cout<<"--------------------------------------------------------\n";
    cout<<"Enter Exit To Return To Main Menu Any Time.\n";
    cout<<"--------------------------------------------------------\n\n";

    string account_number, pin, balance, newBalance;
    string a,b,c,d,e;

    bool input = true;
    while(input){

        cout<<"Enter Your 3 Digit Account Number: ";
        getline(cin , account_number);

        if(account_number == "Exit" || account_number == "exit" || account_number == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(account_number.length() != 3){
            cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<3;i++){
            if(!(account_number[i]>='0' && account_number[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }
        if(!check) continue;

        ifstream file;
        file.open("Accounts.txt", ios::in);

        bool exists = false;
        while(file){
            file >> a >> b >> c >> d >> e;
            if(a.empty()) break;
            if(a == account_number){ 
                exists = true;
                break;
            }
        }
        file.close();

        if(!exists){
            cout<<"\033[31m"<<"Error: Account Doesn't Exist ."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r"; 
        }

        if(exists) break;
    }


    input = true;
    while(input){

        cout<<"Enter Your 4 Digit Pin: ";
        getline(cin, pin);

        if(pin == "Exit" || pin == "exit" || pin == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(pin.length() != 4){
            cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<4;i++){
            if(!(pin[i]>='0' && pin[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }

        if(!check) continue;
        
        if(pin != b){
            cout<<"\033[31m"<<"Error: Wrong Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            check = false;
        }

        if(check) break;
    }

    cout<<"--------------------------------------------------------\n";
    cout<<"\033[32m";
    cout<<"Account Holder: "<< c + " " + d << "\n";
    cout<<"Current Balance: "<< e << "\n";
    cout<<"\033[0m";
    cout<<"--------------------------------------------------------\n";
    cout<<"Press Enter To Continue.\n";
    


}



// Close Account

void close_account(){

    greeting();

    cout<<"--------------------------------------------------------\n";
    cout<<"|                     Close Account                    |\n";
    cout<<"--------------------------------------------------------\n\n";

    cout<<"--------------------------------------------------------\n";
    cout<<"Enter Exit To Return To Main Menu Any Time.\n";
    cout<<"--------------------------------------------------------\n\n";

    string account_number, pin, balance, newBalance;
    string a,b,c,d,e;

    bool input = true;
    while(input){

        cout<<"Enter Your 3 Digit Account Number: ";
        getline(cin , account_number);

        if(account_number == "Exit" || account_number == "exit" || account_number == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(account_number.length() != 3){
            cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<3;i++){
            if(!(account_number[i]>='0' && account_number[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Account Number."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }
        if(!check) continue;

        ifstream file;
        file.open("Accounts.txt", ios::in);

        bool exists = false;
        while(file){
            file >> a >> b >> c >> d >> e;
            if(a.empty()) break;
            if(a == account_number){ 
                exists = true;
                break;
            }
        }
        file.close();

        if(!exists){
            cout<<"\033[31m"<<"Error: Account Doesn't Exist ."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r"; 
        }

        if(exists) break;
    }


    input = true;
    while(input){

        cout<<"Enter Your 4 Digit Pin: ";
        getline(cin, pin);

        if(pin == "Exit" || pin == "exit" || pin == "EXIT"){
            cout<<"Press Enter To Continue....";
            return;
        }

        if(pin.length() != 4){
            cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            continue;
        }

        bool check = true;
        for(int i=0;i<4;i++){
            if(!(pin[i]>='0' && pin[i]<='9')){
                cout<<"\033[31m"<<"Error: Invalid Pin."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                check = false;
                break;
            }
        }

        if(!check) continue;
        
        if(pin != b){
            cout<<"\033[31m"<<"Error: Wrong Pin."<<"\033[0m";
            getch();
            cout<<"\033[2K\r";
            cout<<"\033[A";
            cout<<"\033[2K\r";
            check = false;
        }

        if(check) break;
    }

    cout<<"--------------------------------------------------------\n";
    cout<<"\033[32m"<<"Account Closed Successfully.\n"<<"\033[0m";

    vector<string> lines;
    string newLine = a + " " + b + " " + c + " " + d + " " + newBalance;
    
    ifstream file;
    file.open("Accounts.txt", ios::in);

    while(file){
        string a,b,c,d,e;
        file >> a >> b >> c >> d >> e;
        if(a.empty()) break;
        if(a == account_number) continue;
        else lines.push_back((a + " " + b + " " + c + " " + d + " " + e));
    }

    file.close();

    ofstream output;
    output.open("Accounts.txt", ios::out);

    for(int i=0;i<lines.size();i++){
        output << lines[i] << '\n';
    }

    output.close();

}



void main_menu(){

    bool loop = true;

    while(loop){
        
        greeting();

        cout<<"--------------------------------------------------------\n";
        cout<<"|                      Main Menu                       |\n";
        cout<<"--------------------------------------------------------\n";
        cout<<"| " << "\033[33m" << "1. " << "\033[0m" << "Create Account                                    |\n";
        cout<<"| " << "\033[33m" << "2. " << "\033[0m" << "Deposit Money                                     |\n";
        cout<<"| " << "\033[33m" << "3. " << "\033[0m" << "Withdraw Money                                    |\n";
        cout<<"| " << "\033[33m" << "4. " << "\033[0m" << "Check Balance                                     |\n";
        cout<<"| " << "\033[33m" << "5. " << "\033[0m" << "Close Account                                     |\n";
        cout<<"| " << "\033[33m" << "6. " << "\033[0m" << "Exit                                              |\n";
        cout<<"--------------------------------------------------------\n";
        
        string choice;
        bool input = true;
        while(input){
            cout<<"Enter your choice: ";
            getline(cin, choice);

            if(choice.size() != 1 || !((choice == "1") || (choice == "2") || (choice == "3") || (choice == "4") || (choice == "5") || (choice == "6"))){
                cout<<"\033[31m"<<"Error: Invalid Choice."<<"\033[0m";
                getch();
                cout<<"\033[2K\r";
                cout<<"\033[A";
                cout<<"\033[2K\r";
                continue;
            }

            else break;
        }


        if(choice == "1")
            create_account(); 
        
        else if(choice == "2")
            deposit_money(); 

        else if(choice == "3")
            widthdraw_balance();

        else if(choice == "4")
            check_balance();

        else if(choice == "5")
            close_account();

        else if(choice == "6"){
            cout<<"--------------------------------------------------------\n";
            cout<<"Thank You For Using The Application.\n";
            loop = false;
            break;
        }

        getch();
    }

}


int main(){
    main_menu();
}