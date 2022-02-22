#pragma once
#include <string>
#include "GameServerSerializer.h"

enum class MessageType
{
	Login,
};

class UNREALCLIENT_API Message
{
public:
	Message() = delete;
	Message(MessageType _MessageType)
	{
		m_MessageType = _MessageType;
		m_Size = -1;
	}

private:
	MessageType m_MessageType;
	unsigned int m_Size;
	
public:
	virtual int SizeCheck() = 0
	{
		return -1;
	}
	int DataSizeCheck(const std::string& _Value)
	{
		return 4 + _Value.size();
	}

	virtual void Serialize(GameServerSerializer& _Serializer)
	{
		_Serializer << static_cast<unsigned int>(m_MessageType);
		_Serializer << SizeCheck();
	}
	
	virtual void DeSerialize(GameServerSerializer& _Serializer)
	{
		int Type = 0;
		_Serializer >> Type;
		m_MessageType = static_cast<MessageType>(Type);
		_Serializer >> m_Size;
	}
};

class UNREALCLIENT_API LoginMessage : public Message
{
private:
	std::string m_ID;
	std::string m_PW;

public:
	LoginMessage()
		: Message(MessageType::Login) 
	{
		
	}

	public:
	int SizeCheck() override
	{
		int size = DataSizeCheck(m_ID) + DataSizeCheck(m_PW);
		return size;
	}
	
	void SetID(std::string& _ID)
	{
		m_ID = _ID;
	}
	void SetPW(std::string& _PW)
	{
		m_PW = _PW;
	}
	
	void Serialize(class GameServerSerializer& _Serializer) override
	{
		Message::Serialize(_Serializer);
		_Serializer << m_ID;
		_Serializer << m_PW;
	}
	
	void DeSerialize(class GameServerSerializer& _Serializer) override
	{
		Message::DeSerialize(_Serializer);
		_Serializer >> m_ID;
		_Serializer >> m_PW;
	}
};
