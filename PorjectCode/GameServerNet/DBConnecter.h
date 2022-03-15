#pragma once

/*
Usage		:  모든 클래스 기본.  
Category	:  Object 
Description :  오브젝트 상속용.
*/

class DBConnecter
{
public: //Default
	DBConnecter();
	~DBConnecter();

	DBConnecter(const DBConnecter& _Other) = delete;
	DBConnecter(DBConnecter&& _Other)		noexcept;

protected:
	DBConnecter& operator=(const DBConnecter& _Other) = delete;
	DBConnecter& operator=(DBConnecter&& _Other)		= delete;

private: //Member Value
	
	
public:  //Member Function
	bool IsValid();
};

