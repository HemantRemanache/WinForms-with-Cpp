#pragma once
#pragma once
using namespace System;
using namespace System::Threading;

ref class ThreadHandler
{
private:
	int sleepTime = 100;

	// constructor to initialize a MessagePrinter object
public:
	bool exitFunction = false;
	bool runCommand = false;
	int printVar = 0;

	ThreadHandler()
	{

	}

	//controls Thread that prints message
	void coreFunction()
	{
		// obtain reference to currently executing thread
		Thread^ current = Thread::CurrentThread;
		
		while (!exitFunction)
		{
			if (runCommand)
			{
				Console::WriteLine("Printing: "+ printVar);
				Thread::Sleep(sleepTime);
			}
		}

	} // end method Print
}; // end class MessagePrinter  