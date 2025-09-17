#include <string>
struct TickerData {
    std::string ticker;
    double open;
    double close;
    double high;
    double low;
    long timestamp;
    bool rising = (close > open);
};