#ifndef SCREEN_H
#define SCREEN_H

#include"stdafx.h"
#include"Buildings.h"
#include"Cursor.h"
#include"MainMenu.h"


namespace screen {
	class IScreen {
	public:
		//draw
		virtual void exit(); // 맵 나가기
		virtual void update() = 0;
		virtual void render(sf::RenderWindow* renderWindow) = 0;
	};

	class Screen {
	private:
		IScreen* iScreen;
	public:
		Screen();
		~Screen();
		void setScreen(IScreen* iScreen);
		void updateScreen();
		void renderScreen(sf::RenderWindow* renderWindow);
	};

	///////////////////////////////////////////
	///////////////////////////////////////////
	class MainScreen : public IScreen {
	private:
		std::string imgLink = "images/Background/";
		std::string fileName = "MainScreen";
		img::ImageFile img;
		buildings::Buildings company;
		buildings::Buildings stockCenter;
		buildings::Buildings placeOfBusiness;
		buildings::Buildings agriculture;
		buildings::Buildings auctionHouse;
		buildings::Buildings wholesaleShop;
		buildings::Buildings hitmanContractor;
		buildings::Buildings casino;
		buildings::Buildings drugsShop;
	public:
		MainScreen();
		void update() override;
		void render(sf::RenderWindow* renderWindow) override;
	};

	///////////////////////////////////////////
	///////////////////////////////////////////
	class CompanyScreen : public IScreen {
	private:
	public:
		CompanyScreen();
	};
	///////////////////////////////////////////
	///////////////////////////////////////////
	class Stock {
	protected:
		std::string name;
		int currentPrice;
		int openPrice;
		int closePrice;
		int highPrice;
		int lowPrice;
	public:
		Stock();
		Stock(std::string name, int current, int open, int close, int high, int low);
		~Stock() {}

		void setStock(std::string name, int current, int open, int close, int high, int low);

		std::string getName();
		int getCurrentPrice();
		int getOpenPrice();
		int getClosePrice();
		int getHighPrice();
		int getLowPrice();
	};
	class StockCenterScreen : public IScreen {
		// 주가예측데이터 
		//json file 읽어올꺼 예상
	private:
		img::ImageFile img;
		std::string imgLink = "images/Background/";
		std::string fileName = "Building1";
		std::list<Stock> stockList;
	public:
		StockCenterScreen();
		~StockCenterScreen();

		void addStock(Stock stock);
		void deleteStock(std::string name);


		//총발행량 제한 할꺼면 사용.
		//void buy(std::string name, int quantity);
		//void sell(std::string name, int quantity);

		void exit() override;
		void update() override;
		void render(sf::RenderWindow* renderWindow) override;
	};
	class PlaceOfBusinessScreen : public IScreen {

	};

	class AgricultureScreen : public IScreen {

	};
	class AuctionHouseScreen : public IScreen {

	};
	class WholesaleShopScreen : public IScreen {

	};

	class HitmanContractorScreen : public IScreen {

	};
	class CasinoScreen : public IScreen {

	};
	class DrugsShopScreen : public IScreen {

	};







}








#endif// SCREEN_H