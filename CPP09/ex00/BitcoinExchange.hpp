#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string> //getline
#include <stdexcept>
#include <map>

const std::string csvFileName = "data.csv";
class BitcoinExchange
{
	private:
		std::map<std::string, double> _mapExchangeRates;

	public:
		BitcoinExchange();
		~BitcoinExchange();

		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		std::map<std::string, double> getMapExchangeRates(void) const;
		std::map<std::string, double> getMapInputData(void) const;

		void	readDataCSV(void);
		void	readDataTXT(const std::string& fileName);
		void	printBitcoin(const std::string& date, const std::string& rateStr, double rate);
		double	getRate(std::string date);

		bool	isOpenFile(std::ifstream& input, const std::string& fileName) const;
		bool	isValidLine(const std::string& line) const;
		bool	isValidDate(const std::string& date) const;
		bool	isLeapYear(int year) const;
		bool	isValidRate(const std::string& rateStr, double *rate) const;
};


#endif
