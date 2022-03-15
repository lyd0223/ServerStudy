#pragma once

/*
Usage		:  ��� Ŭ���� �⺻.  
Category	:  Object 
Description :  ������Ʈ ��ӿ�.
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

