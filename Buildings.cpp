#include"Buildings.h"



namespace buildings {
	Buildings::Buildings(){}
	void Buildings::enter() {}
	void Buildings::exit() {}
	void Buildings::screen() {}
	void Buildings::update() {}
	void Buildings::render() {}

	Company::Company(){}

	Stock::Stock() {
		this->name = "test";
		this->currentPrice = 0;
		this->openPrice = 0;
		this->closePrice = 0;
		this->highPrice = 0;
		this->lowPrice = 0;
		
	}
	Stock::Stock(std::string name, int current, int open, int close, int high, int low) {
		this->name = name;
		this->currentPrice = current;
		this->openPrice = open;
		this->closePrice = close;
		this->highPrice = high;
		this->lowPrice = low;
	}
	void Stock::setName(std::string name) {
		this->name = name;
	}
	void Stock::setCurrentPrice(int current) {
		this->currentPrice = current;
	}
	void Stock::setOpenPrice(int open) {
		this->openPrice = open;
	}
	void Stock::setClosePrice(int close) {
		this->closePrice = close;
	}
	void Stock::setHighPrice(int high) {
		this->highPrice = high;
	}
	void Stock::setLowPrice(int low) {
		this->lowPrice = low;
	}

	std::string Stock::getName() {
		return this->name;
	}
	int Stock::getCurrentPrice() {
		return this->currentPrice;
	}
	int Stock::getOpenPrice() {
		return this->openPrice;
	}
	int Stock::getClosePrice() {
		return this->closePrice;
	}
	int Stock::getHighPrice() {
		return this->highPrice;
	}
	int Stock::getLowPrice() {
		return this->lowPrice;
	}

	StockCenter::StockCenter() {}
	void StockCenter::addStock(Stock stock){
		this->stockVec.push_back(stock);
	}
	void StockCenter::deleteStock(std::string name) {
		for (std::list<Stock>::iterator itr = this->stockVec.begin(); itr != this->stockVec.end(); ++itr) {
			if ((*itr).getName() == name) {
				this->stockVec.erase(itr);
			}
		}
	}

}