#include <iostream>
#include "07.h"

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
    return;
}

// declear as member function, because we need it to return *this
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream& read(std::istream &is, Sales_data &data) {
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = data.units_sold * price;
    return is;
}

std::ostream& print(std::ostream &os, Sales_data &data) {
    os << data.isbn() << " " << data.units_sold << " "
        << data.revenue << " " << data.avg_price();
    return os;
}

void Sales_data::set_version(std::string &v) {
    version = v;
    return;
}

std::string Sales_data::version = "1.0";

int main(void) {
    Sales_data data1, sum;
    std::string version = "1.1";

    data1.set_version(version);
    std::cout << "version: " << data1.get_version() << std::endl;

    std::cout << "Please enter item1's info:" << std::endl;
    read(std::cin, data1);
    std::cout << "Please enter item2's info:" << std::endl;
    Sales_data data2(std::cin);

    sum = add(data1, data2);

    std::cout << "total:" << std::endl;
    print(std::cout, sum) << std::endl;

    return 0;
}
