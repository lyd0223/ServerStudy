#pragma once																									  
#include "CoreMinimal.h"																						  
#include <functional>
#include "../../ClientGameInstance.h"
#include ""
																												  
#include "ThreadHandlerLoginResultMessage.h"
#include "ThreadHandlerServerDestroyMessage.h"
#include "ThreadHandlerMonsterCreateMessage.h"
#include "ThreadHandlerChatMessage.h"
																												  
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
																												  
void CheckHandler(Dispatcher& Dis, class UClientGameInstance* Inst, UWorld* World)								  
{														
	Dis.AddHandler(MessageId::LoginResult, std::bind(&OnMessageProcess<ThreadHandlerLoginResultMessage, LoginResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::ServerDestroy, std::bind(&OnMessageProcess<ThreadHandlerServerDestroyMessage, ServerDestroyMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::MonsterCreate, std::bind(&OnMessageProcess<ThreadHandlerMonsterCreateMessage, MonsterCreateMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(MessageId::Chat, std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, Inst, World));	
}																																													
