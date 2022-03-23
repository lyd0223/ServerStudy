#include "PreCompile.h"
#include "DBUserInfoTable.h"

std::string DBUserInfoTable::m_TableName = "userinfo";
DBUserInfoTable::DBUserInfoTable()
{

}

DBUserInfoTable::~DBUserInfoTable()
{

}


UserTable_SelectIDQuery::UserTable_SelectIDQuery(const std::string& _ID)
	: DBQuery("SELECT Idx, ID, PW FROM unrealserver.userinfo WHERE ID = ? LIMIT 1")
{
	m_ID = _ID;
	m_RowData = nullptr;
}

bool UserTable_SelectIDQuery::DoQuery()
{
	
	return true;
}