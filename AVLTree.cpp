#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector> 
#include <map> 

AVLTree::AVLTree(AVLNode* root){
    this->root = root;
    this->size = 1;
    this->height = root->get_height();
}
AVLNode* AVLTree::get_root(){ 
    return this->root; 
}

int AVLTree::get_size(){
    return this->size;
}

int AVLTree::get_height(){
    return this->root->get_height(); 
}

int AVLTree::get_height_of_node(AVLNode* node){
    if(node != nullptr){
        return node->get_height();
    }
    else return -1;
}


void AVLTree::set_root(AVLNode* new_root){
    //new_root->set_height(this->root->get_height());
    this->root = new_root;
}

void AVLTree::update_tree_root(AVLNode* current_root){
    while(current_root->get_parent() != nullptr){
        current_root = current_root->get_parent();
    }
    this->set_root(current_root);
}

void AVLTree::increment_size(){
    this->size++;
}

void AVLTree::decrement_size(){
    this->size--;
}

void AVLTree::single_left_rotate(AVLNode* node){
    ////solve LinkedList right-heavy violation
    //AVLNode* right_child = node->get_right_child();
    //AVLNode* grand_left = right_child->get_left_child();
    ////rotate
    //right_child->set_left_child(node);
    //node->set_right_child(grand_left);
    //right_child->set_parent(nullptr);
    //node->set_parent(right_child);
    ////update height of 2 affected nodes, node and right_child
    //node->update_height();
    //right_child->update_height();
    ////update tree root in every rotation in case the current root of the tree being rotated to be a child
    //this->update_tree_root(node);

    ////update version
    ////implement a single left rotation to solve a single right-heavy LinkedList violation 
    //AVLNode* right_child = node->get_right_child(); 
    //AVLNode* grand_left = right_child->get_left_child();
    //AVLNode* violation_parent = node->get_parent(); 
    ////check null
    //if (violation_parent == nullptr){
    //    right_child->set_parent(violation_parent);
    //    this->set_root(right_child);
    //}  
    ////swap violation to its right child
    //else if (node->get_key() == violation_parent->get_left_child()->get_key()){
    //    violation_parent->set_left_child(right_child);
    //    right_child->set_parent(violation_parent);
    //}
    //else { 
    //    violation_parent->set_right_child(right_child); 
    //    right_child->set_parent(violation_parent);
    //}
    ////set violation down to be the left child of its current right child
    //right_child->set_left_child(node); 
    //node->set_parent(right_child);
    ////set grand_left to be right child of violation
    //if (grand_left != nullptr) grand_left->set_parent(node);
    //node->set_right_child(grand_left);
    ////update the height of 2 affected node: violation and right_child
    //node->update_height(); 
    //right_child->update_height(); 
    ////update tree root in case we rotated the current tree root
    ////this->update_tree_root(node); 
    
    // just the cleaner code version
    AVLNode* right_child = node->get_right_child();
    AVLNode* grand_left = right_child->get_left_child(); 
    AVLNode* violation_parent = node->get_parent();
    // handle grand_left and violation relationship
    node->set_right_child(grand_left);
    if (grand_left != nullptr) {
        grand_left->set_parent(node);
    }
    // handle y and violation_parent relationship
    right_child->set_parent(node->get_parent()); 
    if (violation_parent == nullptr){
        this->set_root(right_child);
    }
    else if (violation_parent->get_left_child()->get_key() == node->get_key()){
        violation_parent->set_left_child(right_child );
    }
    else violation_parent->set_right_child(right_child);
    // handle x and y relationship 
    right_child->set_left_child(node);
    node->set_parent(right_child);
    // update height of 2 height-affected nodes
    node->update_height(); 
    right_child->update_height(); 
}

void AVLTree::single_right_rotate(AVLNode* node){
    ////solve LinkedList left-heavy violation
    //AVLNode* left_child = node->get_left_child();
    //AVLNode* grand_right = left_child->get_right_child();
    ////rotate
    //left_child->set_right_child(node);
    //node->set_left_child(grand_right);
    //left_child->set_parent(nullptr);
    //node->set_parent(left_child);
    ////update height
    //node->update_height();
    //left_child->update_height();
    ////update tree root in every rotation in case the current root of the tree being rotated to be a child
    //this->update_tree_root(node);

    //update version 
    //AVLNode* left_child = node->get_left_child();
    //AVLNode* grand_right = left_child->get_right_child();
    //AVLNode* violation_parent = node->get_parent();
    ////check null 
    //if (violation_parent == nullptr){
    //    left_child->set_parent(violation_parent);
    //    this->set_root(left_child);
    //}
    ////swap left_child and violation
    //else if (node->get_key() == violation_parent->get_left_child()->get_key()){
    //    violation_parent->set_left_child(left_child);
    //    left_child->set_parent(violation_parent);  
    //}
    //else { 
    //    violation_parent->set_right_child(left_child);
    //    left_child->set_parent(violation_parent);
    //}
    ////set violation down to be the right child of its current left child
    //left_child->set_right_child(node);
    //node->set_parent(left_child);
    ////set grand_right to be the left child of violation
    //node->set_left_child(grand_right);
    //if (grand_right != nullptr){
    //    grand_right->set_parent(node);
    //} 
    ////update height of 2 height affected nodes: violation and its current left child
    //node->update_height();
    //left_child->update_height(); 
    ////update tree root
    ////this->update_tree_root(node);

    AVLNode* left_child = node->get_left_child(); 
    AVLNode* grand_right = left_child->get_right_child();
    AVLNode* violation_parent = node->get_parent(); 
    // handle violation and grand_right relationship
    node->set_left_child(grand_right);
    if (grand_right != nullptr) { 
        grand_right->set_parent(node); 
    }
    //handle left_child and violation_parent
    left_child->set_parent(violation_parent);
    if (violation_parent == nullptr) {
        this->set_root(left_child); 
    }
    else if (node->get_key() == violation_parent->get_left_child()->get_key()){
        violation_parent->set_left_child(left_child);
    }
    else violation_parent->set_right_child(left_child);
    //handle violation and left_child relationship
    left_child->set_right_child(node);
    node->set_parent(left_child); 
    // update height of 2 height affected nodes
    node->update_height();
    left_child->update_height(); 
}

void AVLTree::double_left_rotate(AVLNode* node){
    //solve ZigZac right-heavy violation
    single_right_rotate(node->get_right_child());
    single_left_rotate(node);
}

void AVLTree::double_right_rotate(AVLNode* node){
    //solve Zigzac left-heavy violation
    single_left_rotate(node->get_left_child());
    single_right_rotate(node);
}

void AVLTree::left_rotate(AVLNode* node){
    //the current node violate AVL property
    //current node is right_heavy
    //this function determine if the current node is right-heavy LinkedList or right-heavy ZigZac
    //then fix the violation rooted at node
    //THIS FUNCTION WILL BE CALLED WHEN A VIOLATION NODE IS RIGHT HEAVY
    //We are assuming that the violation is right_heavy
    //the only work now is determining if it is LinkedList or ZigZac violation
    AVLNode* right_child = node->get_right_child();
    AVLNode* grand_left = right_child->get_left_child();
    AVLNode* grand_right = right_child->get_right_child();

    int grand_left_height = this->get_height_of_node(grand_left);
    int grand_right_height = this->get_height_of_node(grand_right);

    //because violation is right-heavy, if grand-child still right-heavy (grand_right_height>grand_left_heigt)
    //then it is LinkedList violation, else it is ZigZac violation
    if(grand_right_height > grand_left_height){
        //2 right heavy -> right-heavy LinkedList -> single_left_rotate()
        single_left_rotate(node);
    }
    else{
        //1 right heavy and 1 left heavy -> right-heavy ZigZac violation -> double_left_rotate()
        double_left_rotate(node);
    }
}

void AVLTree::right_rotate(AVLNode* node){
    //This is used for solving left_heavy violation 
    //Determine if it is left_heavy LinkedList or left_heavy ZigZac
    AVLNode* left_child = node->get_left_child();
    AVLNode* grand_left = left_child->get_left_child();
    AVLNode* grand_right = left_child->get_right_child();

    int grand_left_height = this->get_height_of_node(grand_left);
    int grand_right_height = this->get_height_of_node(grand_right);

    if(grand_left_height > grand_right_height){
        //we're assuming violation is left heavy
        //if 2 left-heavy, then it is LinkedList
        single_right_rotate(node);
    }
    else{
        //assuming the violation is left heavy, then grand child is right heavy, 
        //then it is left_heavy ZigZac
        double_right_rotate(node);
    }
}

void AVLTree::rebalance(AVLNode* node){
    //this function check if the subtree rooted at the node is a violation or not
    //if it is a violation, then fix the violation by checking left or right heavy
    //if it's not violation, then update the height

    //check if the node is violation 
    if(node->is_left_heavy() == true){
        right_rotate(node);
    }
    else if(node->is_right_heavy() == true){
        left_rotate(node);
    }
    else{//the node is ok, not violation
        node->update_height();
    }
}




void AVLTree::insert(AVLNode* new_node){
    //insert like BinarySearchTree insertion
    AVLNode* temp = nullptr;
    AVLNode* temp_root = this->get_root();
    while(temp_root != nullptr){
        temp = temp_root;
        if(new_node->get_key() < temp_root->get_key()){
            temp_root = temp_root->get_left_child();
        }
        else{
            temp_root = temp_root->get_right_child();
        }
    }
    new_node->set_parent(temp);
    if(temp == nullptr){
        this->set_root(new_node);
    }
    else if(new_node->get_key() < temp->get_key()){
        temp->set_left_child(new_node);
    }
    else{
        temp->set_right_child(new_node);
    }
    //go up to fix height of all parent node
    AVLNode* fix_height = new_node;
    while(fix_height->get_parent() != nullptr){
        this->rebalance(fix_height);
        fix_height = fix_height->get_parent();
    }
    this->rebalance(fix_height);
    //update tree root in case the current_root is rotated to be a child
    this->update_tree_root(this->get_root());
}

void AVLTree::remove(AVLNode* deleted_node){
    AVLNode* actual_deleted_node;
    if(deleted_node->get_left_child() == nullptr || deleted_node->get_right_child() == nullptr){
        actual_deleted_node = deleted_node;
    }
    else actual_deleted_node = this->next_larger(deleted_node);
    AVLNode* actual_deleted_node_child;
    if(actual_deleted_node->get_left_child() != nullptr){
        actual_deleted_node_child = actual_deleted_node->get_left_child();
    }
    else actual_deleted_node_child = actual_deleted_node->get_right_child();
    if(actual_deleted_node_child != nullptr){
        actual_deleted_node_child->set_parent(actual_deleted_node->get_parent());
    }
    if(actual_deleted_node->get_parent() == nullptr){
        this->set_root(actual_deleted_node_child);
    }
    else if(actual_deleted_node->get_key() == actual_deleted_node->get_parent()->get_left_child()->get_key()){
        actual_deleted_node->get_parent()->set_left_child(actual_deleted_node_child);
    }
    else actual_deleted_node->get_parent()->set_right_child(actual_deleted_node_child);
    if(actual_deleted_node->get_key() != deleted_node->get_key()){
        deleted_node->set_key(actual_deleted_node->get_key());
        if (actual_deleted_node->get_left_child() != nullptr) {
            deleted_node->set_left_child(actual_deleted_node->get_left_child());
        }
        if (actual_deleted_node->get_right_child() != nullptr) {
            deleted_node->set_right_child(actual_deleted_node->get_right_child()); 
        }
    }
    
    //fix height 
    //actual_deleted_node->set_parent(nullptr);
    //actual_deleted_node->set_left_child(nullptr); 
    //actual_deleted_node->set_right_child(nullptr);
    AVLNode* fix_height = actual_deleted_node;
    while(fix_height->get_parent() != nullptr){
        this->rebalance(fix_height);
        fix_height = fix_height->get_parent();
    }
    this->rebalance(fix_height);
    actual_deleted_node = nullptr;
    //this->update_tree_root(this->get_root());
}

AVLNode* AVLTree::search(AVLNode* target){
    AVLNode* travel = this->get_root();
    while(travel != nullptr && travel->get_key() != target->get_key()){
        if(target->get_key() < travel->get_key()){
            travel = travel->get_left_child();
        }
        else{
            travel = travel->get_right_child();
        }
    }
    return travel;
}

AVLNode* AVLTree::get_max(AVLNode* root){
    AVLNode* travel = root;
    while(travel->get_right_child() != nullptr){
        travel = travel->get_right_child();
    }
    return travel;
}

AVLNode* AVLTree::get_min(AVLNode* root){
    AVLNode* travel = root;
    while(travel->get_left_child() != nullptr){
        travel = travel->get_left_child();
    }
    return travel;
}

AVLNode* AVLTree::next_larger(AVLNode* current_node){
    if(current_node->get_right_child() != nullptr){
        return this->get_min(current_node->get_right_child());
    }
    AVLNode* traveler = current_node;
    AVLNode* traveler_parent = traveler->get_parent();
    while(traveler_parent != nullptr && traveler->get_key() == traveler_parent->get_right_child()->get_key()){
        traveler = traveler_parent;
        traveler_parent = traveler_parent->get_parent();
    }
    return traveler_parent;
}

AVLNode* AVLTree::next_smaller(AVLNode* current_node){
    if(current_node->get_left_child() != nullptr){
        return get_max(current_node->get_left_child());
    }
    AVLNode* traveler = current_node;
    AVLNode* traveler_parent = current_node->get_parent();
    while(traveler_parent != nullptr && traveler->get_key() == traveler_parent->get_left_child()->get_key()){
        traveler = traveler_parent;
        traveler_parent = traveler_parent->get_parent();
    }
    return traveler_parent;
}

void AVLTree::inorder_walk_down(AVLNode* root){
    if(root != nullptr){
        this->inorder_walk_down(root->get_left_child());
        root->print_node();
        this->inorder_walk_down(root->get_right_child());
    }
}


int main(){
    AVLNode* root = new AVLNode(10);
    AVLTree* tree = new AVLTree(root);
    AVLNode* left_child = new AVLNode(8);
    AVLNode* right_child = new AVLNode(12);
    AVLNode* eleven = new AVLNode(11);
    AVLNode* fifteen = new AVLNode(15);
    AVLNode* sixteen = new AVLNode(16);
    AVLNode* twenty = new AVLNode(20);
    AVLNode* twenty_one = new AVLNode(21);
    AVLNode* twenty_five = new AVLNode(25);
    tree->insert(right_child);
    tree->insert(fifteen);
    tree->insert(twenty);
    tree->insert(twenty_five);
    tree->insert(twenty_one); 
    tree->remove(twenty);
    tree->inorder_walk_down(tree->get_root());
    return 0;
}
