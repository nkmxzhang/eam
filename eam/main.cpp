// main.cpp
//

#include "stdafx.h"
#include "Concurrency.h"

using namespace eam;

enum TaskState
{
	TS_IDLE = 0,
	TS_SEND = 1,
	TS_RECV = 2,
	TS_RECV_END = 3,
};

static TaskState ts = TS_IDLE;
static int idx = 0;

class TestServiceTask : public ThreadTask
{
public:
	int run()
	{	
		fprintf(stderr, "idx = %d.\n", idx++);
		return 0;
	}
};

class StateServiceTask : public ThreadTask
{
public:
	StateServiceTask(TaskState state)
		: _state(state)
	{

	}
	int run()
	{
		fprintf(stderr, "idx = %d. state = %d.\n", idx++, _state);
		Sleep(10);
		switch(_state)
		{
		case TS_IDLE:
			break;
		case TS_RECV:
			ts = TS_RECV_END;
			break;
		case TS_SEND:
			ts = TS_IDLE;
			break;
		}
		return 0;
	}
protected:
	TaskState _state;
};

int _tmain(int argc, _TCHAR* argv[])
{

// 	SingleThreadExecuter myService;
// 	do 
// 	{
// 		switch(ts)
// 		{
// 		case TS_IDLE:
// 			ts = TS_RECV;
// 			myService.execute(new StateServiceTask(TS_RECV));
// 			break;
// 		case TS_RECV_END:
// 			ts = TS_SEND;
// 			myService.execute(new StateServiceTask(TS_SEND));
// 			break;
// 		}
// 
// 		//Sleep(7);
// 	} while (10000);
// 
// 	myService.shutdown();

	
	ThreadService myThread;
	do 
	{
		switch(ts)
		{
		case TS_IDLE:
			myThread.shutdown();
			myThread.execute(new StateServiceTask(TS_RECV));
			break;
		case TS_RECV_END:
			myThread.shutdown();
			myThread.execute(new StateServiceTask(TS_SEND));
			break;
		}

		//Sleep(7);
	} while (10000);


	getchar();
	return 0;
}

