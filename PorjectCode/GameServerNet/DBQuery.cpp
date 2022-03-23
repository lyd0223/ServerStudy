#include "PreCompile.h"
#include "DBQuery.h"


DBQuery::DBQuery(const char* _QueryText)
{
	m_DBConnecter = GameServerThread::GetLocalData<DBConnecter>();
	m_QueryText = _QueryText;
}

DBQuery::~DBQuery()
{

}
