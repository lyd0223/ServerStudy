#pragma once																									  
#include "CoreMinimal.h"																						  
																												  
#include "ThreadHandlerLoginResultMessage.h"																	  
#include "ThreadHandlerChatMessage.h"																			  
#include "ThreadHandlerServerDestroyMessage.h"																  
																												  
template<class MessageHandler, class EMessageType>															  
void OnMessageProcess(std::shared_ptr<GameServerMessage> _Message, UClientGameInstance* _Inst, UWorld* _World)	  
{																												  
	std::shared_ptr<EMessageType> ConvertMessage = std::static_pointer_cast<EMessageType>(_Message);				  
	if (nullptr == ConvertMessage)																				  
	{																											  
		return;																									  
	}																											  
																												  
	MessageHandler Cmd = MessageHandler(ConvertMessage);														  
	Cmd.Init(_Inst, _World);																					  
	Cmd.Start();																								  
}																												  
																												  
void CheckHandler(Diapatchar& Dis, class UClientGameInstance* Inst, UWorld* World)								  
{														
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::LoginResult), std::bind(&OnMessageProcess<ThreadHandlerLoginResultMessage, LoginResultMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::ServerDestroy), std::bind(&OnMessageProcess<ThreadHandlerServerDestroyMessage, ServerDestroyMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::MonsterCreate), std::bind(&OnMessageProcess<ThreadHandlerMonsterCreateMessage, MonsterCreateMessage>, std::placeholders::_1, std::placeholders::_2));	
	Dis.AddHandler(static_cast<uint32_t>(EMessageType::Chat), std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, std::placeholders::_2));	
}																																													
