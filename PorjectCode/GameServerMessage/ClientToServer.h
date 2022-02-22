#pragma once
#include "GameServerMessage.h"

class LoginMessage : public GameServerMessage                    
{                                                               
public:                                                         
	std::string m_ID;
	std::string m_PW;
                                                                
public:                                                         
    LoginMessage()                                               
        : GameServerMessage(MessageType::Login)                    
        , m_ID()
        , m_PW()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~LoginMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(m_ID) + DataSizeCheck(m_PW);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer << m_ID;
        _Serializer << m_PW;

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer >> m_ID;
        _Serializer >> m_PW;

    }                                                           
};                                                              
