#include"Job.h"


namespace job {
	Job::Job() {
		this->field = KindOfFields::Merchant;
		this->job = KindOfJobs::Farmer;
	}
	Job::Job(KindOfFields field = KindOfFields::WhiteCollar, KindOfJobs job = KindOfJobs::Farmer) {
		this->field = field;
		this->job = job;
	}
	Job::~Job() {

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
		}
		else if (this->rate < -200) {
			this->setKindOfFields(KindOfFields::BlackGuard);
			this->setKindOfJobs(KindOfJobs::Hitman);
		}
		else {
			this->setKindOfFields(KindOfFields::Merchant);
			this->setKindOfJobs(KindOfJobs::Farmer);
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
}