#include "PreCompile.h"																																							
#include "ServerDispatcher.h"																																						
#include <GameServerBase\GameServerDebug.h>																																			
																																													
#include "ThreadHandlerLoginMessage.h"
#include "ThreadHandlerSignInMessage.h"
#include "ThreadHandlerChatMessage.h"
																																													
Dispatcher<TCPSession> gDispatcher;																																							
																																													
template<typename MessageHandler, typename EMessageType>																																
void OnMessageProcess(std::shared_ptr<TCPSession> _Session, std::shared_ptr<GameServerMessage> _Message)																			
{																																													
	std::shared_ptr<EMessageType> ConvertMessage = std::dynamic_pointer_cast<EMessageType>(_Message);																					
	if (nullptr == ConvertMessage)																																					
	{																																												
		GameServerDebug::LogError("ConvertError");																																
		return;																																										
	}																																												
																																													
	std::shared_ptr<MessageHandler> Cmd = std::make_shared<MessageHandler>(_Session, ConvertMessage);																				
	Cmd->Start();																																									
}																																													
																																													
void DispatcherRegistration()																																						
{																																													
	gDispatcher.AddHandler(static_cast<uint32_t>(EMessageType::Login), std::bind(&OnMessageProcess<ThreadHandlerLoginMessage, LoginMessage>, std::placeholders::_1, std::placeholders::_2));	
	gDispatcher.AddHandler(static_cast<uint32_t>(EMessageType::SignIn), std::bind(&OnMessageProcess<ThreadHandlerSignInMessage, SignInMessage>, std::placeholders::_1, std::placeholders::_2));	
	gDispatcher.AddHandler(static_cast<uint32_t>(EMessageType::Chat), std::bind(&OnMessageProcess<ThreadHandlerChatMessage, ChatMessage>, std::placeholders::_1, std::placeholders::_2));	
}																																													
