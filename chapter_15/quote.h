#ifndef _QUOTE_H
#define _QUOTE_H

#include <ostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual ~Quote() = default;
    virtual double net_price(std::size_t n) const
        { return n * price; }
    virtual void debug(std::ostream &os) const
        { os << std::endl << bookNo << ", $" << price; }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote: public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double sales_price,
            std::size_t qty, double disc):
        Quote(book, sales_price), qty(qty), discount(disc) { }
    double net_price(std::size_t) const override = 0;
protected:
    const std::size_t qty = 0;
    const double discount = 0.0;
};

class Bulk_quote: public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    double net_price(std::size_t) const override;
    void debug(std::ostream &os) const override {
        Quote::debug(os);
        os << ", " << qty << ", " << discount * 100.0 << "%";
    }
};

double print_total(std::ostream&, const Quote&, std::size_t);

#endif // _QUOTE_H
