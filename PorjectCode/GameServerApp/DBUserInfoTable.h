#pragma once
#include <GameServerNet/DBQuery.h>

/*
Usage		:  ��� Ŭ���� �⺻.  
Category	:  Object 
Description :  ������Ʈ ��ӿ�.
*/


//User�� ���� ����������, DBTable�����ؼ��� ���δ�.
class DBUserInfoTableRow
{
public:
	DBUserInfoTableRow()
	{
		m_Index = NULL;
		m_ID = "";
		m_PW = "";
	}
	DBUserInfoTableRow(int _Index, const std::string& _ID, const std::string& _PW)
	{
		m_Index = _Index;
		m_ID = _ID;
		m_PW = _PW;
	}
public:
	int m_Index;
	std::string m_ID;
	std::string m_PW;
	
public:
	
};


class DBUserInfoTable
{
public: //Default
	DBUserInfoTable();
	~DBUserInfoTable();

	DBUserInfoTable(const DBUserInfoTable& _Other) = delete;
	DBUserInfoTable(DBUserInfoTable&& _Other)		noexcept = delete;
	DBUserInfoTable& operator=(const DBUserInfoTable& _Other) = delete;
	DBUserInfoTable& operator=(DBUserInfoTable&& _Other)		= delete;

private: //Member Value
	static std::string m_TableName;
	std::string m_QueryText;
	
public:  //Member Function
};


class UserTable_SelectIDQuery : public DBQuery, DBUserInfoTable
{
	std::string m_ID;
	std::shared_ptr<DBUserInfoTableRow> m_RowData;

	UserTable_SelectIDQuery(const std::string& _ID);
	bool DoQuery() override;
	
};
