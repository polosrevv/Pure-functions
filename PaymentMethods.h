#ifndef PAYMENTMETHODS_H
#define PAYMENTMETHODS_H

#include "PaymentProcessor.h"
#include <iostream>
#include <string>

class CreditCardProcessor : public PaymentProcessor {
private:
    double feePercentage;

public:
    CreditCardProcessor(std::string accountId, double feePercentage) : PaymentProcessor(accountId), feePercentage(feePercentage){

    }
    void processPayment(double amount) override {
        std::cout << "Credit Card [" << this->accountId << "]: Charged $" << amount << " (Fee: $" << this->feePercentage << ")"; 
    } 
    std::string getProcessorName() override {
        return "CreditCard";
    }
};

class BankTransferProcessor : public PaymentProcessor {
private:
    std::string bankName;

public:
    BankTransferProcessor(std::string accountId, std::string bankName) : PaymentProcessor(accountId), bankName(bankName){

    }
    void processPayment(double amount){
        std::cout << "Bank Transfer [" << this->accountId << "] via " << this->bankName << ": Transferred $" << amount;
    }
    std::string getProcessorName(){
        return "BankTransfer";
    }
};

#endif
