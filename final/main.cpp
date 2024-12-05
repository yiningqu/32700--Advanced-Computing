#include <queue>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>
#include <queue>
#include <functional>
#include <numeric>
#include <algorithm> // include for std::find_if

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class TradingStrategy {
private:
    bool long_signal;
    int position;
    double cash;
    double total;
    double holdings;
    deque<double> small_window;
    deque<double> long_window;
    const int small_window_size = 50;
    const int long_window_size = 100;
    vector<string> prev_price_update;
    string start_print_date; // Variable to store the date before the first long position
    bool print_enabled;

    string getPreviousDate(const string& date) {
        tm t = {};
        istringstream ss(date);
        ss >> get_time(&t, "%Y-%m-%d");
        t.tm_mday -= 1;
        mktime(&t);
        ostringstream oss;
        oss << put_time(&t, "%Y-%m-%d");
        return oss.str();
    }

public:
    TradingStrategy() : long_signal(false), position(0), cash(10000), total(0), holdings(0), print_enabled(false) {}

    void checkSignal(const vector<string> &price_update) {
        double adj_price = stod(price_update[6]);
        double prev_holdings = holdings;
        double prev_total = total;
        bool order_executed = false;

        if (long_signal && position == 0) {
            position = 10;
            cash -= position * adj_price;
            holdings = position * adj_price;
            total = holdings + cash;
            printf("%s send buy order for 10 shares price=%.2lf\n", price_update[0].c_str(), adj_price);
            order_executed = true;
            if (start_print_date.empty()) {
                start_print_date = getPreviousDate(price_update[0]); // Set the start print date to the previous day's date
                print_enabled = true;
            }
        } else if (!long_signal && position > 0) {
            cash += position * adj_price;
            position = 0;
            holdings = 0;
            total = holdings + cash;
            printf("%s send sell order for 10 shares price=%.2lf\n", price_update[0].c_str(), adj_price);
            order_executed = true;
        } else {
            holdings = position * adj_price;
            total = holdings + cash;
        }

        // Print the total, holdings, and cash if printing is enabled and the current date is after the start print date
        if (print_enabled && price_update[0] > start_print_date) {
            printf("%s total=%.0lf, holding=%.0lf, cash=%.0lf\n", price_update[0].c_str(), total, holdings, cash);
        }

        prev_price_update = price_update;
    }

    void onUpdate(vector<string> &price_update) {
        double close_price = stod(price_update[4]);

        if (small_window.size() >= small_window_size) {
            small_window.pop_front();
        }
        small_window.push_back(close_price);

        if (long_window.size() >= long_window_size) {
            long_window.pop_front();
        }
        long_window.push_back(close_price);

        double small_window_avg = accumulate(small_window.begin(), small_window.end(), 0.0) / static_cast<double>(small_window.size());
        double long_window_avg = accumulate(long_window.begin(), long_window.end(), 0.0) / static_cast<double>(long_window.size());

        long_signal = (small_window_avg > long_window_avg);

        checkSignal(price_update);
    }
};

int main()
{
    TradingStrategy sebStrategy;
    string data_frame_count_temp;
    getline(cin, data_frame_count_temp);

    int data_frame_count = stoi(ltrim(rtrim(data_frame_count_temp)));

    vector<string> data_frame(data_frame_count);
    bool first_line = true;

    for (int i = 0; i < data_frame_count; i++) {
        string data_frame_item;
        vector<string> row;
        for (int k = 0; k < 6; k++) {
            getline(cin, data_frame_item, ',');
            row.push_back(data_frame_item);
        }
        getline(cin, data_frame_item, '\n');
        row.push_back(data_frame_item);
        if (!first_line)
            sebStrategy.onUpdate(row);
        else
            first_line = false;
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), [](int ch) { return !isspace(ch); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), [](int ch) { return !isspace(ch); }).base(),
            s.end()
    );

    return s;
}
