#include "reader.h"
#include <fstream>
#include <sstream>

using namespace std;


std::string const Reader::Operator = "Operator";

Reader::Reader(string const& inputFilePath)
    : inputFilePath_(inputFilePath)
{

}

Reader::~Reader()
{

}

void Reader::dump(Common::PriceMap const& priceMap)
{
    for (auto operatorIt : priceMap) {
        std::cout << "==================================\n";
        std::cout << operatorIt.first << std::endl;
        for (auto price : operatorIt.second) {
            std::cout << price.first << "\t" << price.second << std::endl;
        }
        std::cout << "==================================\n";
    }
}

Common::PriceMap Reader::parse()
{
    ifstream fsFile(inputFilePath_);
    if (!fsFile.good()) {
        cout << "No such file\n";
        return Common::PriceMap();
    }

    Common::PriceMap priceMap;
    string strLine;
    string operatorKey;
    while (getline(fsFile, strLine)) {
        if (strLine.find(Operator) != string::npos) {
            operatorKey = strLine;
            priceMap.emplace(strLine, Common::OperatorPrice());
        } else if (!strLine.empty()) {
            if (operatorKey.empty()) continue;

            string prefix, price;
            istringstream iss(strLine);
            iss >> prefix >> price;
            priceMap[operatorKey].emplace(prefix, stod(price));
        }
    }

    return priceMap;
}