#include <iostream>
#include <Windows.h>

void sh(HANDLE pheap);

int main() {
	HANDLE pheap = GetProcessHeap();
	std::cout << "--Before--\n\n";
	sh(pheap);

	int size = 300000;
	int* m = new int[size];
	std::cout << "-- m = " << std::hex << m << ", size = " << std::dec << size << '\n';

	std::cout << "\n\n--After--\n\n";
	sh(pheap);
	system("pause");
}

void sh(HANDLE pheap) {
	PROCESS_HEAP_ENTRY phe;
	phe.lpData = NULL;
	while (HeapWalk(pheap, &phe)) {
		std::cout << "-- address = " << std::hex << phe.lpData <<
			", size = " << std::dec << phe.cbData <<
			((phe.wFlags & PROCESS_HEAP_REGION) ? " R" : "") <<
			((phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE) ? " U" : "") <<
			((phe.wFlags & PROCESS_HEAP_ENTRY_BUSY) ? " B" : "") << '\n';
	}
	std::cout << "----\n";
}