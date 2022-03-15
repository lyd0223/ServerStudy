#pragma once

/*
Usage		:  DB관리용 클래스
Category	:  
Description :  DB관리를 위한 클래스.
			  스레드 하나당 DBManager를 하나씩 갖는다.
*/

class DBManager
{
public: //Default
	DBManager();
	~DBManager();

	DBManager(const DBManager& _Other) = delete;
	DBManager(DBManager&& _Other)		noexcept;

protected:
	DBManager& operator=(const DBManager& _Other) = delete;
	DBManager& operator=(DBManager&& _Other)		= delete;

private: //Member Value
	//				  <thread Order, >
	//std::unordered_map<unsigned int, >
	
public:  //Member Function
	bool IsValid();
};

