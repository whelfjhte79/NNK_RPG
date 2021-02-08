#ifndef QUEST_H
#define QUEST_H
#endif //QUEST_H

#include"Job.h"

namespace quest {
	
	class MainQuest {
	private:
		job::KindOfJobs jobType;
	public:
		MainQuest();
		MainQuest(job::KindOfJobs jobType);


		void setJobType(){}
		job::KindOfJobs getJobType(){}

		//acts
		virtual void contents(){}
		virtual void accept(){}
		void cancel(){}

		// update render
		void update(){}
		void render(){}
	};


	class SubQuestWhiteCollar : public MainQuest {
	private:
	public:
		virtual void contents() override;

	};
	class SubQuestMerchant : public MainQuest {
	private:
	public:
		virtual void contents() override;
	};
	class SubQuestBlackGuard : public MainQuest {
	private:
	public:
		virtual void contents() override;
	};
}