#ifndef BUILDINGS_H
#define BUILDINGS_H

#include"stdafx.h"
#include"Image.h"

namespace buildings {
	class IBuildings {
	private:
	public:
		virtual void update() = 0;
		virtual void render(sf::RenderTarget* target) = 0;
	};
	class Buildings {
	private:
		bool entryFlags = false;
		IBuildings* building;
	public:
		void enter();
		bool getEntryFlags();
		void setBuilding(IBuildings* building);
		IBuildings* getBuilding();
	};
	class Company : public IBuildings{
	private:
		std::string linkName;
		std::string fileName;
		img::ImageFile img;
	public:
		Company();
		
		void update() override;
		void render(sf::RenderTarget* target) override;

	};
	class StockCenter : public IBuildings{
	private:
		img::ImageFile img;
	public:
		StockCenter();
		~StockCenter();
		

		void update() override;
		void render(sf::RenderTarget* target) override;
	};
	class PlaceOfBusiness : public IBuildings {
	private:
		img::ImageFile img;
	public:
		
		void update() override;
		void render(sf::RenderTarget* target) override;

	};

	class Agriculture : public IBuildings {
	public:

		void update() override;
		void render(sf::RenderTarget* target) override;

	};
	class AuctionHouse : public IBuildings {
	public:
		void update() override;
		void render(sf::RenderTarget* target) override;

	};
	class WholesaleShop : public IBuildings {
	public:
		void update() override;
		void render(sf::RenderTarget* target) override;

	};

	class HitmanContractor : public IBuildings {
		
	};
	class Casino : public IBuildings {

	};
	class DrugsShop : public IBuildings {

	};
	
}








#endif //BUILDINGS_H