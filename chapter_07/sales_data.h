class Sales_data {
friend std::istream& read(std::istream&, Sales_data&);
friend std::ostream& print(std::ostream&, Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
        _bookNo(s), _units_sold(n), _revenue(n * p) {}
    Sales_data(const std::string &s): _bookNo(s) {}
    Sales_data(std::istream&);
    std::string isbn() const { return _bookNo; }
    Sales_data &combine(const Sales_data&);
    static std::string version() { return _version; }
    static void version(std::string&);
private:
    double avg_price() const {
        return _units_sold != 0 ? _revenue / _units_sold : 0.0;
    }
    std::string _bookNo;
    unsigned _units_sold = 0;
    double _revenue = 0.0;
    static std::string _version;
};
