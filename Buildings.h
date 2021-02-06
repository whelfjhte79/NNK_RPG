#ifndef BUILDINGS_H
#define BUILDINGS_H

#include"NNK_RPG.h"
#include<list>

namespace buildings {
	/**
	* 건물 입장시 화면전환 고려
	* 
	
	*/
	class Buildings {
	private:

	public:
		Buildings();
		void enter();
		void exit();


		/*
		screen 화면 어떻게 넘겨줄지 고민
		
		*/
		virtual void screen();
		virtual void update();
		virtual void render();
	};

	class Company : public Buildings{
	private:

	public:
		Company();
	};

	class Stock {
	private:
		std::string name;
		int currentPrice;  
		int openPrice;     
		int closePrice;    
		int highPrice;     
		int lowPrice;
	public:
		Stock(){}
		Stock(std::string name,int current, int open, int close, int high, int low);
		~Stock(){}

		void setName(std::string name);
		void setCurrentPrice(int current);
		void setOpenPrice(int open);
		void setClosePrice(int close);
		void setHighPrice(int high);
		void setLowPrice(int low);
		
		std::string getName();
		int getCurrentPrice();
		int getOpenPrice();
		int getClosePrice();
		int getHighPrice();
		int getLowPrice();
	};
	class StockCenter : public Buildings{
		// 주가예측데이터 
		//json file 읽어올꺼 예상
	private:
		std::list<Stock> stockVec;
	public:
		StockCenter();
		~StockCenter(){}
		
		void addStock(Stock stock);
		void deleteStock(std::string name);

		//총발행량 제한 할꺼면 사용.
		//void buy(std::string name, int quantity);
		//void sell(std::string name, int quantity);


		void update(){}
		void render(){}
	};
	class PlaceOfBusiness {

	};

	class Agriculture {

	};
	class AuctionHouse {

	};
	class WholesaleShop {

	};

	class HitmanContractor {
		
	};
	class Casino {

	};
	class DrugsShop {

	};
	
}








#endif //BUILDINGS_H