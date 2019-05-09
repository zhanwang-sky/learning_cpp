#include <iostream>
#include "sales_data.h"

std::string Sales_data::_version = "1.0";

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
    return;
}

// declear as a member function, because we need it to return *this
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    _units_sold += rhs._units_sold;
    _revenue += rhs._revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream& read(std::istream &is, Sales_data &data) {
    double price = 0;
    is >> data._bookNo >> data._units_sold >> price;
    data._revenue = data._units_sold * price;
    return is;
}

std::ostream& print(std::ostream &os, Sales_data &data) {
    os << data.isbn() << " " << data._units_sold << " "
        << data._revenue << " " << data.avg_price();
    return os;
}

void Sales_data::version(std::string &v) {
    _version = v;
    return;
}
