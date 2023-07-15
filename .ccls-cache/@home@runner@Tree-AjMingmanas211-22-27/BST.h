#include <iostream>
#include <iomanip>
#include "node.h"
#include <climits>

using namespace std;

class BST {
  int size;
  TreeNodePtr rootPtr;

public:
  BST();
  ~BST();
  TreeNodePtr front();
  void kill(TreeNodePtr);
  void insert_node(int);
  void print_all();
  void inOrder(TreeNodePtr);
  void preOrder(TreeNodePtr);
  void postOrder(TreeNodePtr);
  void printTree(TreeNodePtr, int, bool);
};

TreeNodePtr BST::front(){
  return rootPtr;
}

BST::BST() {
  size = 0;
  rootPtr = nullptr;
}

BST::~BST() {
  cout << "Kill BST" << endl;
  kill(rootPtr);
}

void BST::kill(TreeNodePtr treePtr) {
  if (treePtr) {
    kill(treePtr->move_left());
    kill(treePtr->move_right());
    delete treePtr;
  }
}

void BST::insert_node(int value) {
  TreeNodePtr new_node = new TreeNode(value);
  if (new_node) {
    if (!rootPtr) {
      rootPtr = new_node;
    } else {
      TreeNodePtr current = rootPtr;
      TreeNodePtr parent = nullptr;

      while (current) {
        parent = current;

        if (value < current->get_value()) {
          current = current->move_left();
        } else {
          current = current->move_right();
        }
      }

      if (value < parent->get_value()) {
        parent->set_left(new_node);
      } else {
        parent->set_right(new_node);
      }
    }

    ++size;
  }
}

void BST::inOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    inOrder(treePtr->move_left());
    cout << setw(3) << treePtr->get_value();
    inOrder(treePtr->move_right());
  }
}

void BST::preOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    cout << setw(3) << treePtr->get_value();
    preOrder(treePtr->move_left());
    preOrder(treePtr->move_right());
  }
}

void BST::postOrder(TreeNodePtr treePtr) {
  if (treePtr) {
    postOrder(treePtr->move_left());
    postOrder(treePtr->move_right());
    cout << setw(3) << treePtr->get_value();
  }
}

void BST::printTree(TreeNodePtr treePtr, int level, bool isLeft = true) {
  if (treePtr) {
    printTree(treePtr->move_right(), level + 1, false);

    if (level != 0) {
      cout << setw(level * 4 - 2) << "";
      if(isLeft){
           cout << "\\";
        }else{
           cout << "/";
        }
    }

    cout << treePtr->get_value() << endl;

    printTree(treePtr->move_left(), level + 1, true);
  }
}




void BST::print_all() {

      cout << "In-order traversal: ";
      inOrder(rootPtr);
      cout << endl;

      cout << "Pre-order traversal: ";
      preOrder(rootPtr);
      cout << endl;

      cout << "Post-order traversal: ";
      postOrder(rootPtr);
      cout << endl;
  
      cout << "Tree structure:" << endl;
      printTree(rootPtr, 0);
      cout << endl;
  
}