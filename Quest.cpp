#include"Quest.h"

namespace quest {
	MainQuest::MainQuest() {
		this->jobType = job::KindOfJobs::Farmer;
	}
	MainQuest::MainQuest(job::KindOfJobs jobType) {
		this->jobType = jobType;
		
	}
}