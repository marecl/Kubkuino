#include "thready.h"

void thready::DoWork()
{
	while (true) {
		y = PortCOM::PortTemp(y);
		System::Threading::Thread::Sleep(5000);

	}
}