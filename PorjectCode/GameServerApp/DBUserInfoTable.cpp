#include "PreCompile.h"
#include "DBUserInfoTable.h"
#include <GameServerNet/DBConnecter.h>
#include <GameServerBase/GameServerDebug.h>

std::string DBUserInfoTable::m_TableName = "userinfo";
DBUserInfoTable::DBUserInfoTable()
{

}

DBUserInfoTable::~DBUserInfoTable()
{

}


UserInfoTable_SelectIDQuery::UserInfoTable_SelectIDQuery(const std::string& _ID)
	: DBQuery("SELECT Idx, ID, PW FROM unrealserver.userinfo WHERE ID = 'ww' LIMIT 1")
{
	m_ID = _ID;
	m_RowData = nullptr;
}

bool UserInfoTable_SelectIDQuery::DoQuery()
{
	mysql_query(m_DBConnecter->GetMYSQL(), m_QueryText);
	return true;
}


UserInfoTable_InsertUserInfoQuery::UserInfoTable_InsertUserInfoQuery(const std::string& _ID, const std::string& _PW)
	:DBQuery("INSERT INTO unrealserver.userinfo (ID,PW) VALUES (12345, 1234);")
{
	m_ID = _ID;
	m_PW = _PW;
}
bool UserInfoTable_InsertUserInfoQuery::DoQuery()
{
	int __stdcall result = mysql_query(m_DBConnecter->GetMYSQL(), m_QueryText);
	if (result != 0)
	{
		std::string ErrorStr = mysql_error(m_DBConnecter->GetMYSQL());
		GameServerDebug::LogError("QueryError : " + ErrorStr);
	}
	return true;
}