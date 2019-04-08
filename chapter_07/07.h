class Sales_data {
friend std::istream& read(std::istream&, Sales_data&);
friend std::ostream& print(std::ostream&, Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(std::istream&);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);
    static std::string get_version() { return version; }
    static void set_version(std::string&);
private:
    double avg_price() const {
        return units_sold != 0 ? revenue / units_sold : 0.0;
    }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    static std::string version;
};
