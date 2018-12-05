#include <iostream>
#include "Queue.h"

int main() {
	Queue<int> queue(5);

	queue.Enqueue(4);
	queue.PrintFrontRear();

	queue.Enqueue(43);
	queue.PrintFrontRear();

	queue.Enqueue(24);
	queue.PrintFrontRear();

	queue.Enqueue(87);
	queue.PrintFrontRear();

	queue.Enqueue(22);
	queue.PrintFrontRear();

	queue.Enqueue(11);
	queue.PrintFrontRear();
	queue.PrintQueue();

	std::cout << "Dequeued " << queue.Dequeue() << std::endl;
	queue.PrintFrontRear();
	queue.PrintQueue();

	std::cout << "Dequeued " << queue.Dequeue() << std::endl;
	queue.PrintFrontRear();
	queue.PrintQueue();

	std::cout << "Dequeued " << queue.Dequeue() << std::endl;
	queue.PrintFrontRear();
	queue.PrintQueue();

	std::cout << "Dequeued " << queue.Dequeue() << std::endl;
	queue.PrintFrontRear();
	queue.PrintQueue();

	std::cout << "Dequeued " << queue.Dequeue() << std::endl;
	queue.PrintFrontRear();
	queue.PrintQueue();

	std::cout << "Dequeued " << queue.Dequeue() << std::endl;
	queue.PrintFrontRear();
	queue.PrintQueue();


	int test = queue.Dequeue();
	std::cout << "Dequeued " << queue.Dequeue() << std::endl;
	queue.PrintFrontRear();
	queue.PrintQueue();

	return 0;
}