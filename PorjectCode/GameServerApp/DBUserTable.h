#pragma once

/*
Usage		:  모든 클래스 기본.  
Category	:  Object 
Description :  오브젝트 상속용.
*/

class DBUserTable
{
public: //Default
	DBUserTable();
	~DBUserTable();

	DBUserTable(const DBUserTable& _Other) = delete;
	DBUserTable(DBUserTable&& _Other)		noexcept = delete;
	DBUserTable& operator=(const DBUserTable& _Other) = delete;
	DBUserTable& operator=(DBUserTable&& _Other)		= delete;

private: //Member Value
	static std::string m_TableName;
	std::string m_QueryText;
	
public:  //Member Function
};

