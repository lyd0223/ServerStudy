
#include "MessageComponent.h"

#include "ClientGameInstance.h"
#include "Message/Dispatcher.h"
#include "Message/Handlers/HandlerHeader.h"

// Sets default values for this component's properties
UMessageComponent::UMessageComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	m_Dispatcher = nullptr;
}
UMessageComponent::~UMessageComponent()
{
	delete(m_Dispatcher);
	m_Dispatcher = nullptr;
}


// Called when the game starts
void UMessageComponent::BeginPlay()
{
	Super::BeginPlay();

	UClientGameInstance* GameInstance = Cast<UClientGameInstance>(GetOwner()->GetGameInstance());

	m_Dispatcher = new Dispatcher();
	CheckHandler(*m_Dispatcher, GameInstance, GetOwner()->GetWorld());
	
}


// Message
void UMessageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(GetOwner() == nullptr)
	{
		return;
	}

	//매 틱마다 GameInstance가 갖고있는 MessageQueue에있는 메시지들을 처리하고, 메시지가 요구하는 실제 동작을시킨다.
	UObject* owner = GetOwner();
	UClientGameInstance* GameInstance = Cast<UClientGameInstance>(GetOwner()->GetGameInstance());
	while(!GameInstance->IsEmptyMessage())
	{
		std::shared_ptr<GameServerMessage> Message = GameInstance->PopMessage();

		if(Message == nullptr)
		{
			continue;
		}

		MessageHandler MSGHandler;
		EMessageType MessageType = Message->GetMessageType();
		m_Dispatcher->GetHandler(MessageType, MSGHandler);
		if(MSGHandler == nullptr)
		{
			return;
		}
		MSGHandler(Message);
	}

}

