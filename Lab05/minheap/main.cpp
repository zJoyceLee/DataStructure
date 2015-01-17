#include "MinHeap.hpp"

int main()
{
	int a[12]={80,57,99,35,23,11,74,29,62,16};
	MinHeap<int> ha(a,20,10);
	int e;
	char c = 'x';
	std::cout<<std::endl;

	std::cout << "the sequence of minHeap£º" << std::endl;
	ha.Traverse(Write<int>);
	std::cout << std::endl << std::endl;

    while (c != '0')	{
        std::cout << std::endl << "1. insert element.";
        std::cout << std::endl << "2. É¾³ı¶Ñ¶¥ÔªËØ.";
        std::cout << std::endl << "3. display heap.";
		std::cout << std::endl << "0. exit.";
		std::cout << std::endl << "select(0 to 3) : ";
		std::cin >> c;
		switch (c) 	{
		    case '1':
            	std::cout << std::endl << "input inserted element :";
			    std::cin >> e;
				ha.Insert(e);
			    break;
           	case '2':
				ha.DeleteTop(e);
				std::cout << "É¾³ıµÄ¶Ñ¶¥ÔªËØÎª:" << e << std::endl;
			    break;
		    case '3':
				std::cout << std::endl;
				ha.Traverse(Write<int>);
				break;
		}
	}


	return 0;
}
