//STL
#include <iostream>
//Current Project
#include "BinaryTree.hpp"

int main(int argc, char * argv[])
{
	BinTreeNode<char> *p;
	char pre[]={'A','B','D','E','G','H','C','F','I'}; //pre
	char in[]={'D','B','G','E','H','A','C','F','I'};  // in
	int n = 9;						                  //node number
	BinaryTree<char> bt;
    char c = 'x', e;

	bt = CreateBinaryTree(pre, in, n);           //make up binary tree

	std::cout << "make up binaryTree by :\npreOrder: A,B,D,E,G,H,C,F,I and inOrder: D,B,G,E,H,A,C,F,I" << std::endl;
	DisplayBTWithTreeShape<char>(bt);
	std::cout << std::endl;
    std::cout << "countLeaves: " << bt.countLeaf() << std::endl;
    bt.LevelOrder(Write<char>);

    std::cout << std::endl << "BT: " << std::endl;
    DisplayBTWithTreeShape<char>(bt);
    BinaryTree<char> btRevolute = bt.revolute();
    std::cout << std::endl << "BT Revolute: " << std::endl;
    DisplayBTWithTreeShape<char>(btRevolute);
    /*while (c != '0')	{

        std::cout << "countLeaves: " << bt.countLeaf();

        std::cout << std::endl << "1. insert left.";
        std::cout << std::endl << "2. delete right tree.";
        std::cout << std::endl << "3. levelOrder.";
        std::cout << std::endl << "4. preOrder.";
        std::cout << std::endl << "5. inOrder.";
        std::cout << std::endl << "6. postOrder.";
        std::cout << std::endl << "7. count node.";
        std::cout << std::endl << "8. get the height of the tree.";
        std::cout << std::endl << "9. display binaryTree.";
		std::cout << std::endl << "0. exit.";
		std::cout << std::endl << "selection operations(0 to 9): ";
		std::cin >> c;
		switch (c) 	{
		    case '1':
            	std::cout << std::endl << "input the value of inserted element : ";
			    std::cin >> e;
			    //std::cout << "cannot find it." << std::endl;
			    //that find was wrong
			    p = bt.Find(e);
			    //std::cout << "Find it" << std::endl;
			    if (p == nullptr)
			    	std::cout << "the node is inexitence !" << std::endl;
			    else {
            		std::cout << std::endl << "input the value of insert element :";
			    	std::cin >> e;
					bt.InsertLeftChild(p, e);	// insert left
			    }
			    break;
           	case '2':
            	std::cout << std::endl << "input delete child tree parent value: ";
			    std::cin >> e;
   			    //std::cout << "cannot find it." << std::endl;
			    p = bt.Find(e);
			    //std::cout << "Find it" << std::endl;
			    if (p == nullptr)
			    	std::cout << "the node is inexitence !" << std::endl;
			    else
					bt.DeleteRightChild(p);
			    break;
		    case '3':
				std::cout << std::endl;
				bt.LevelOrder(Write<char>);
				break;
	         case '4':
				std::cout << std::endl;
				bt.PreOrder(Write<char>);
				break;
	         case '5':
				std::cout << std::endl;
				bt.InOrder(Write<char>);
				break;
	         case '6':
				std::cout << std::endl;
				bt.PostOrder(Write<char>);
				break;
	         case '7':
				std::cout << std::endl;
				std::cout << "count node of binaryTree : " << bt.NodeCount() << std::endl;
				break;
	         case '8':
				std::cout << std::endl;
				std::cout << "the heigth of binaryTree : " << bt.Height() << std::endl;
				break;
	         case '9':
				std::cout << std::endl;
				DisplayBTWithTreeShape(bt);
				break;
		}
	}*/
	return 0;
}

