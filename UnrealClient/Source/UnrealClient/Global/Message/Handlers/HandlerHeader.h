#pragma once																									  
#include "CoreMinimal.h"																						  
#include <functional>																								
#include "../../ClientGameInstance.h"																			
#include "../Dispatcher.h"																						
																												  
#include "ThreadHandlerLoginResultMessage.h"
#include "ThreadHandlerServerDestroyMessage.h"
#include "ThreadHandlerSignInResultMessage.h"
#include "ThreadHandlerChatMessage.h"
																												  
template<class MessageHandler, class MessageType>															  
void OnMessageProcess(std::shared_ptr<GameServerMessage> _Message, UClientGameInstance* _Inst, UWorld* _World)	  
{																												  
	std::shared_ptr<MessageType> ConvertMessage = std::static_pointer_cast<MessageType>(_Message);				  
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
	Dis.AddHandler(EMessageType::LoginResult, std::bind(&OnMessageProcess<ThreadHandlerLoginResultMessage, LoginResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(EMessageType::ServerDestroy, std::bind(&OnMessageProcess<ThreadHandlerServerDestroyMessage, ServerDestroyMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(EMessageType::SignInResult, std::bind(&OnMessageProcess<ThreadHandlerSignInResultMessage, SignInResultMessage>, std::placeholders::_1, Inst, World));	
	Dis.AddHandler(EMessageType::Chat, std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, Inst, World));	
}																																													
