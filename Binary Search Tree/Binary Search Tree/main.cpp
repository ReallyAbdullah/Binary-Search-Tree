//
//  main.cpp
//  Binary Search Tree
//
//  Created by abdullah on 28/10/2019.
//  Copyright © 2019 abdullah. All rights reserved.
//

#include <iostream>
#include "Header.h"

int main(){
    Node* root = nullptr;
    root = insert(root, 18);
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 17);
    root = insert(root, 9);
    print2D(root);
    cout<<endl;
    cout<<"IS Present :"<<retrieve(root, 10)<<endl;
    root = deleteNode(root, 18);
    print2D(root);
    cout<<"BFS :"<<endl;
    breadthFirst(root);
}
