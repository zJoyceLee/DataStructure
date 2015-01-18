//STL
#include <iostream>
#include <string>

int main(int argc, char * argv[])
{
    int countNum = 0;
    std::cin >> countNum;
    int frontElem, behindElem;
    for(int i = 0; i < countNum; ++i){
        std::cin >> frontElem >> behindElem;
        int right = 0;
        int left = 0;
        do {
            if(frontElem > behindElem) {
                frontElem = frontElem - behindElem;
                //behindElem = behindElem;
                ++left;
            } else {
                //frontElem = frontElem;
                behindElem = behindElem -frontElem;
                ++right;
            }
        } while (frontElem != 1 && behindElem != 1);
        std::cout << left << " " << right << std::endl;
    }

    return 0;
}
