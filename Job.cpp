#include"Job.h"


namespace job {
	Job::Job() {
		this->field = KindOfFields::WhiteCollar;
		this->job = KindOfJobs::OfficeWorker;
		this->iJob = new WhiteCollar();
	}
	Job::~Job() {
		delete this->iJob;
	}
	void Job::setSwitchJob(IJobSwitch* iJob) {
		this->iJob = iJob;
	}
	
	void Job::addRate(int value) {
		if (this->rate + value < -1000) 
			this->rate = -1000;
		else if (this->rate + value > 1000) 
			this->rate = 1000;
		else 
			this->rate += value;

		if (this->rate > 200) {
			this->setKindOfFields(KindOfFields::WhiteCollar);
			this->setKindOfJobs(KindOfJobs::OfficeWorker);
			this->setSwitchJob(new WhiteCollar());
		}
		else if (this->rate < -200) {
			this->setKindOfFields(KindOfFields::BlackGuard);
			this->setKindOfJobs(KindOfJobs::Hitman);
			this->setSwitchJob(new Merchant());
		}
		else {
			this->setKindOfFields(KindOfFields::Merchant);
			this->setKindOfJobs(KindOfJobs::Farmer);
			this->setSwitchJob(new BlackGuard());
		}
	}
	void Job::setRate(int rate) {
		this->rate = rate;
	}
	void Job::setKindOfFields(KindOfFields field) {
		this->field = field;
	}
	void Job::setKindOfJobs(KindOfJobs job) {
		this->job = job;
	}
	
	KindOfFields Job::getKindOfFields() {
		return this->field;
	}
	KindOfJobs Job::getKindOfJobs() {
		return this->job;
	}
	int Job::getRate() {
		return this->rate;
	}

///////////////////////////////////////////  
///////////////////////////////////////////

	void WhiteCollar::addTax(float tax) {
		this->tax.total += tax;
	}
	void WhiteCollar::clearTax() {
		this->tax.total = 0.0f;
	}
	Tax WhiteCollar::getTax() {
		return this->tax;
	}
	void WhiteCollar::setTaxRate(float rate) {
		this->tax.rate = rate;
	}
	void WhiteCollar::quest() {

	}

	///////////////////////////////////////////  
	///////////////////////////////////////////

	void Merchant::addTax(float tax) {
		this->tax.total += tax;
	}
	void Merchant::clearTax() {
		this->tax.total = 0.0f;
	}
	Tax Merchant::getTax() {
		return this->tax;
	}
	void Merchant::setTaxRate(float rate) {
		this->tax.rate = rate;
	}


}