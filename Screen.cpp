#include"Screen.h"

namespace screen {

	Screen::Screen() {
		this->iScreen = new MainScreen();
	}
	Screen::~Screen() {
		delete this->iScreen;
	}
	void Screen::setScreen(IScreen* screen) {
		this->iScreen = screen;
	}
	void IScreen::exit() {

	}
	void Screen::updateScreen() {
		this->iScreen->update();
	}
	void Screen::renderScreen(sf::RenderWindow* renderWindow) {
		this->iScreen->render(renderWindow);
	}

	// ////////////////////////////////////////////////////
	// MainScreen
	// ////////////////////////////////////////////////////
	MainScreen::MainScreen() {
	}
	void MainScreen::update() {

	}
	void MainScreen::render(sf::RenderWindow* renderWindow) {
		this->img = img::ImageFile(this->imgLink + this->fileName, img::FileExtension::PNG, 0.0f, 0.0f, renderWindow);
		
	}
	
	// ////////////////////////////////////////////////////
	// Company
	// ////////////////////////////////////////////////////
	CompanyScreen::CompanyScreen() {

	}

	// ////////////////////////////////////////////////////
	// Stock & Stock Center
	// ////////////////////////////////////////////////////

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
	void Stock::setStock(std::string name, int current, int open, int close, int high, int low) {
		this->name = name;
		this->currentPrice = current;
		this->openPrice = open;
		this->closePrice = close;
		this->highPrice = high;
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

	StockCenterScreen::StockCenterScreen() {

	}
	StockCenterScreen::~StockCenterScreen() {

	}
	void StockCenterScreen::addStock(Stock stock) {
		this->stockList.push_back(stock);
	}
	void StockCenterScreen::deleteStock(std::string name) {
		for (std::list<Stock>::iterator itr = this->stockList.begin(); itr != this->stockList.end(); ++itr) {
			if ((*itr).getName() == name) {
				this->stockList.erase(itr);
				itr--;
			}
		}
	}
	void StockCenterScreen::exit() {

	}
	void StockCenterScreen::update() {

	}
	void StockCenterScreen::render(sf::RenderWindow* renderWindow) {
		this->img = img::ImageFile(this->imgLink + this->fileName, img::FileExtension::PNG, 0.0f, 0.0f, renderWindow);
	}


}