#include "PreCompile.h"
#include "MessageConverter.h"



MessageConverter::MessageConverter(const std::vector<unsigned char>& _Buffer)
	:m_Buffer(_Buffer)
{
	GameServerSerializer Serializer = GameServerSerializer(m_Buffer);
	
	EMessageType MessageType;
	memcpy_s(&MessageType, sizeof(EMessageType), &m_Buffer[0], sizeof(EMessageType));
	
	switch (MessageType)
	{
	case EMessageType::Login:
		m_Message = std::make_shared<LoginMessage>();
		break;
	case EMessageType::LoginResult:
		m_Message = std::make_shared<LoginResultMessage>();
		break;
	default:
		break;
	}

	m_Message->DeSerialize(Serializer);

}
MessageConverter::~MessageConverter()
{

}