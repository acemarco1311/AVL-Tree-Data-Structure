#ifndef AVLNODE_H
#define AVLNODE_H
#include <iostream> 
#include <iomanip>
#include <string>
#include <cmath> 
#include <vector> 
#include <map> 
#include "Node.h"

class AVLNode{
    public: int key;
    public: AVLNode* parent;
    public: AVLNode* left_child;
    public: AVLNode* right_child;
    public: int height;

    public: AVLNode(int key);
    public: AVLNode(int key, AVLNode* parent, AVLNode* left_child, AVLNode* right_child);
    public: ~AVLNode();

    public: bool operator==(AVLNode* input);
    
    public: int get_key();
    public: AVLNode* get_parent();
    public: AVLNode* get_left_child();
    public: AVLNode* get_right_child();
    public: int get_height();

    public: void set_key(int new_key);
    public: void set_parent(AVLNode* new_parent);
    public: void set_left_child(AVLNode* new_left_child);
    public: void set_right_child(AVLNode* new_right_child);
    public: void set_height(int new_height);
    public: void increment_height();
    public: void decrement_height();
    public: void update_height();

    public: bool is_leaf();
    public: bool is_root();
    public: int is_balance();
    public: bool is_left_heavy();
    public: bool is_right_heavy();
    public: void print_node();
};

#endif
