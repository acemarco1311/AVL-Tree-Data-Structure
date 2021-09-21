#include "AVLNode.h" 
#include <iostream> 
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <map> 

class AVLTree{
    private: AVLNode* root;
    private: int size;
    private: int height;

    public: AVLTree(AVLNode* root);
    public: AVLTree();
    public: ~AVLTree();
    
    public: AVLNode* get_root();
    public: int get_size();
    public: int get_height();
    public: int get_height_of_node(AVLNode* node);

    public: void set_root(AVLNode* new_root);
    public: void update_tree_root(AVLNode* current_root);
    public: void increment_size();
    public: void decrement_size();
            
    public: void single_left_rotate(AVLNode* node);
    public: void single_right_rotate(AVLNode* node);
    public: void double_left_rotate(AVLNode* node);
    public: void double_right_rotate(AVLNode* node);
    public: void left_rotate(AVLNode* node);
    public: void right_rotate(AVLNode* node);
    public: void rebalance(AVLNode* node);
    
    public: void insert(AVLNode* new_node);
    public: void remove(AVLNode* deleted_node);
    public: AVLNode* search(AVLNode* target);
    public: AVLNode* get_max(AVLNode* root);
    public: AVLNode* get_min(AVLNode* root);
    public: AVLNode* next_larger(AVLNode* current_node);
    public: AVLNode* next_smaller(AVLNode* current_node);
    public: void inorder_walk_down(AVLNode* root);

};
