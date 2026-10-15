#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include <string>

class PaymentProcessor {
protected:
    std::string accountId;

public:
    PaymentProcessor(std::string accountId) : accountId(accountId){

    }
    virtual void processPayment(double amount) = 0;
    virtual std::string getProcessorName() = 0;

    virtual ~PaymentProcessor() = default;
};

#endif
