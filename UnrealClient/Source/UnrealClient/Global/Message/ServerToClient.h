#pragma once
#include "GameServerMessage.h"

class LoginResultMessage : public GameServerMessage                    
{                                                               
public:                                                         
	ELoginResultType m_LoginResultType;
                                                                
public:                                                         
    LoginResultMessage()                                               
        : GameServerMessage(EMessageType::LoginResult)                    
        , m_LoginResultType()
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~LoginResultMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return DataSizeCheck(m_LoginResultType);
    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              
        _Serializer<<static_cast<int>(m_LoginResultType);

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            
        _Serializer>>static_cast<int>(m_LoginResultType);

    }                                                           
};                                                              

class ServerDestroyMessage : public GameServerMessage                    
{                                                               
public:                                                         
                                                                
public:                                                         
    ServerDestroyMessage()                                               
        : GameServerMessage(EMessageType::ServerDestroy)                    
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~ServerDestroyMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return 0;    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            

    }                                                           
};                                                              

class MonsterCreateMessage : public GameServerMessage                    
{                                                               
public:                                                         
                                                                
public:                                                         
    MonsterCreateMessage()                                               
        : GameServerMessage(EMessageType::MonsterCreate)                    
    {                                                           
                                                                
    }                                                           
                                                                
    virtual ~MonsterCreateMessage() {}                                   
                                                                
    virtual int SizeCheck()                                     
    {                                                           
		return 0;    }                                                           
                                                                
    void Serialize(GameServerSerializer& _Serializer)           
    {                                                           
        GameServerMessage::Serialize(_Serializer);              

    }                                                           
                                                                
    void DeSerialize(GameServerSerializer& _Serializer)         
    {                                                           
        GameServerMessage::DeSerialize(_Serializer);            

    }                                                           
};                                                              

