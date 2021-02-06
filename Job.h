#ifndef JOB_H
#define JOB_H

namespace job {

	enum class KindOfFields {
		WhiteCollar,
		Merchant,
		BlackGuard
	};
	enum class KindOfJobs {
		//WhiteCollar
		OfficeWorker,
		StockTrader,
		Enterpriser,

		//Merchant
		Farmer,
		Auctioneer,
		Wholesaler,

		//BlackGuard
		Hitman,
		Gambler,
		DrugsDealer
	};

	class Job {
	private:
		KindOfFields field;
		KindOfJobs job;

		int rate = 0;
		int jobLevel = 1;
		float jobExp = 0.0f;
				
	public:
		Job();
		Job(KindOfFields field, KindOfJobs job);
		~Job();

		void setRate(int rate);
		void setKindOfFields(KindOfFields field);
		void setKindOfJobs(KindOfJobs job);
		
		void addRate(int value);
		KindOfFields getKindOfFields();
		KindOfJobs getKindOfJobs();
		int getRate();
		

	};


	/**
	* 문제점: 세부 직업에 퀘스트밖에 기능 넣을게 없음.
	* ex) 트레이더에 buy sell 기능 넣으면
	* 트레이더밖에 못 씀.
	* 
	* 전체적으로 기능 쓸 수 있게하고
	* 세부 분야로 제한 걸기
	*/

	/*
	class WhiteCollar : public Job{
	private:
	public:
		WhiteCollar();
		~WhiteCollar();

		virtual void quest() = 0;

		void update();
		void render();

		 
	};
	class OfficeWorker : public WhiteCollar{
	private:

	public:
		// 퀘스트 수행
		virtual void quest() override;
	};
	class StockTrader : public WhiteCollar{
	private:
	public:

		// 퀘스트 수행
		virtual void quest() override;
	};
	class Enterpriser : public WhiteCollar{
		// 퀘스트 수행
		virtual void quest() override;
	};

	class Merchant : public Job{
	private:
	public:
		void update();
		void render();
	};
	class Farmer : public Merchant {

	};
	class Auctioneer : public Merchant {

	};
	class Wholesaler : public Merchant {

	};

	class BlackGuard : public Job{
	private:
	public:




		void update();
		void render();
	};
	class Hitman : public BlackGuard {
	private:
	public:
		void killing();
	};
	class Gambler : public BlackGuard {

	};
	class DrugsDealer : public BlackGuard {

	};
	*/
}

#endif //JOB_H