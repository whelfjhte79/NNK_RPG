#ifndef ABILITY_H
#define ABILITY_H

namespace ability {
	class Ability {
	private:
		// OfficeWorkerAbility
		float documentProcessingSpeed;
		float increaseResearchResults;
		float salesSupportingAbility;

		//	StockTraderAbility
		float transactionTaxDiscountRate;

		//	EnterpriserAbility
		float increaseProbabilityOfFindInvestor;
		float increaseProbabilityOfDisclosureInformation;

		//  FarmerAbility
		float harvestingSpeed;
		int landExpansion;

		//  AuctioneerAbility
		float auctiontaxDiscountRate;

		//  WholesalerAbility
		

		//  HitmanAbility
		 

		//  GamblerAbility
		float CommissionDiscountRate = 0.0f;

		//  DrugsDealerAbility
		float dealDiscountRate = 0.0f;

	public:
		Ability();
		~Ability();
	};
}








#endif //ABILITY_H