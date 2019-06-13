#include <iostream>
#include "quote.h"

using namespace std;

Bulk_quote::Bulk_quote(const string &book, double p,
        std::size_t qty, double disc):
    Disc_quote(book, p, qty, disc) { }

double Bulk_quote::net_price(std::size_t n) const {
    if (n >= qty) {
        return n * price * (1 - discount);
    } else {
        return n * price;
    }
}

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << ", #sold: " << n
        << ", total due: " << ret << endl;
    return ret;
}
