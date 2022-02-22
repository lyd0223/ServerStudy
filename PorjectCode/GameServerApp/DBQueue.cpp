#include "PreCompile.h"
#include "DBQueue.h"


GameServerQueue DBQueue::m_JobQueue = GameServerQueue();

DBQueue::DBQueue()
{

}

DBQueue::~DBQueue()
{

}

DBQueue::DBQueue(DBQueue&& _Other) noexcept
{

}

void DBQueue::Initialize()
{
	m_JobQueue.Initialize(GameServerQueue::WORK_TYPE::Default, 20, "DBThread");
}

void DBQueue::EnQueue(const std::function<void()>& _CallBack)
{
	m_JobQueue.EnQueue(_CallBack);
}

void DBQueue::Destroy()
{
	m_JobQueue.Destroy();
}