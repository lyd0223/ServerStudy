#include "PreCompile.h"
#include "DBConnecter.h"


DBConnecter::DBConnecter()
{
	m_MYSQL = nullptr;
	m_Host = "";
	m_ID = "";
	m_PW = "";
	m_SchemaName = "";
	m_Port = NULL;
}

DBConnecter::~DBConnecter()
{

}

DBConnecter::DBConnecter(DBConnecter&& _Other) noexcept
{

}

std::unique_ptr<DBStmt> DBConnecter::CreateDBStmt(std::string_view _DBQuery)
{

}


bool DBConnecter::Connect()
{
	if (m_MYSQL != nullptr) // 이미 연결되어있는상태.
	{
		return true;
	}
	
	m_MYSQL = mysql_init(nullptr);
	if (m_MYSQL == nullptr)
	{
		GameServerDebug::AssertDebugMsg("mysql init failed");
		return false;
	}
	
	//mysql 문자 인코딩방식설정
	mysql_options(m_MYSQL, MYSQL_SET_CHARSET_NAME, "utf8");

	//MysqlRealConnect
	MYSQL* MYSQLHandle = mysql_real_connect(m_MYSQL, m_Host.c_str(), m_ID.c_str(), m_PW.c_str(), m_SchemaName.c_str(), m_Port, nullptr, CLIENT_MULTI_RESULTS);
	
	if (m_MYSQL != MYSQLHandle)
	{
		GameServerDebug::AssertDebugMsg("mysql real connect failed" + GetLastError());
		return false;
	}

	//Mysql 자동복구옵션
	bool isConnected = true;
	mysql_options(m_MYSQL, MYSQL_OPT_RECONNECT, &IsConnected);

	return true;
}

bool DBConnecter::Connect(const std::string& _Host, const std::string& _ID,
	const std::string& _PW, const std::string& _SchemaName, unsigned int _Port)
{
	m_Host = _Host;
	m_ID = _ID;
	m_PW = _PW;
	m_SchemaName = _SchemaName;
	m_Port = _Port;

	return Connect();
}

std::string DBConnecter::GetLastErrorStr()
{
	return mysql_error(m_MYSQL);
}