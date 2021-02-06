#ifndef BUILDINGS_H
#define BUILDINGS_H

#include"NNK_RPG.h"
#include<list>

namespace buildings {
	/**
	* �ǹ� ����� ȭ����ȯ ���
	* 
	
	*/
	class Buildings {
	private:

	public:
		Buildings();
		void enter();
		void exit();


		/*
		screen ȭ�� ��� �Ѱ����� ���
		
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
		// �ְ����������� 
		//json file �о�ò� ����
	private:
		std::list<Stock> stockVec;
	public:
		StockCenter();
		~StockCenter(){}
		
		void addStock(Stock stock);
		void deleteStock(std::string name);

		//�ѹ��෮ ���� �Ҳ��� ���.
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