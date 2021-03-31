#ifndef QUEST_H
#define QUEST_H
#endif //QUEST_H

#include"Job.h"
#include"stdafx.h"
namespace quest {
	
	class iQuestForm {
	public:
		//acts
		virtual void contents() = 0;
		virtual void accept() = 0;
	};
	class MainQuest {
	private:
		job::KindOfJobs jobType;
		iQuestForm* iQuest = NULL;
	public:
		MainQuest();
		MainQuest(job::KindOfJobs jobType);

		void setJobType(job::KindOfJobs jobType);
		void setQuestForm(iQuestForm* iQuest){}

		job::KindOfJobs getJobType();

		void cancel(){}
		
		//draw
		void update(){}
		void render(sf::RenderTarget* target){}

	};


	class SubQuestWhiteCollar : public iQuestForm {
	private:
	public:
		//acts
		virtual void contents() override{}
		virtual void accept() override{}



	};
	class SubQuestMerchant : public iQuestForm {
	private:
	public:
		virtual void contents() override{}
	};
	class SubQuestBlackGuard : public iQuestForm {
	private:
	public:
		virtual void contents() override{}
	};
}