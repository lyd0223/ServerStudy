#pragma once

/*
Usage		:  DB������ Ŭ����
Category	:  
Description :  DB������ ���� Ŭ����.
			  ������ �ϳ��� DBManager�� �ϳ��� ���´�.
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

