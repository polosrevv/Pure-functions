#include <iostream>
#include <string>
#include "PaymentMethods.h"

using namespace std;

int main() {
    // Read inputs
    string ccAccountId;
    double feePercentage;
    string bankAccountId;
    string bankName;
    
    getline(cin, ccAccountId);
    cin >> feePercentage;
    cin.ignore();
    getline(cin, bankAccountId);
    getline(cin, bankName);
    PaymentProcessor* arr[2];
    arr[0] = new CreditCardProcessor(ccAccountId, feePercentage);
    arr[1] = new BankTransferProcessor(bankAccountId, bankName);
    for(int i={};i<2;i++){
        std::cout << "Processing with " << arr[i]->getProcessorName() << ":\n";
        arr[i]->processPayment(100.0);
        std::cout << "\n";
        if(i != 1){
            std::cout << "\n";
        }
    }
    for(int i{};i<2;i++){
        delete arr[i];
    }
    return 0;
}
