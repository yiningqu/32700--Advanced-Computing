#include <string>

struct FinancialProduct {
    std::string symbol;
    double price;
};

FinancialProduct::FinancialProduct(const std::string& sym, double pr)
        : symbol(sym), price(pr) {}

struct Option : public FinancialProduct {
    int expiration_date;

    Option(const std::string& sym, double pr, int expDate)
            : FinancialProduct(sym, pr), expiration_date(expDate) {}
};

struct FixedIncome : public FinancialProduct {
    double interest_rate;
    int term_date;

    FixedIncome(const std::string& sym, double pr, double intRate, int termDate)
            : FinancialProduct(sym, pr), interest_rate(intRate), term_date(termDate) {}
};
