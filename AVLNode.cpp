#include "AVLNode.h" 
#include "Node.h" 
#include <iostream>
#include <iomanip> 
#include <string>
#include <cmath>
#include <vector> 
#include <map> 

AVLNode::AVLNode(int key) {
    this->key = key;
    this->parent = nullptr;
    this->left_child = nullptr;
    this->right_child = nullptr;
    this->height = 0;
}

AVLNode::AVLNode(int key, AVLNode* parent, AVLNode* left_child, AVLNode* right_child){
    this->key = key;
    this->parent = parent;
    this->left_child = left_child;
    this->right_child = right_child;
    if(left_child->get_height() >= right_child->get_height()){
        this->height = left_child->get_height() + 1;
    }
    else this->height = right_child->get_height() + 1;
}

AVLNode::~AVLNode(){

}

int AVLNode::get_key(){
    return this->key;
}

AVLNode* AVLNode::get_parent(){
    return this->parent;
}

AVLNode* AVLNode::get_left_child(){
    return this->left_child;
}

AVLNode* AVLNode::get_right_child(){
    return this->right_child;
}

int AVLNode::get_height(){
    return this->height;
}

void AVLNode::set_key(int new_key){
    this->key = new_key;
}

void AVLNode::set_parent(AVLNode* new_parent){
    //new_parent->set_height(this->get_parent()->get_height());
    this->parent = new_parent;
}

void AVLNode::set_left_child(AVLNode* new_left_child){
    //new_left_child->set_height(this->get_left_child()->get_height());
    this->left_child = new_left_child;
}

void AVLNode::set_right_child(AVLNode* new_right_child){
    //new_right_child->set_height(this->get_right_child()->get_height());
    this->right_child = new_right_child;
}

void AVLNode::set_height(int new_height){
    this->height = new_height;
}

void AVLNode::increment_height(){
    this->height++;
}

void AVLNode::decrement_height(){
    this->height--;
}
 
void AVLNode::update_height(){
    int left_child_height;
    int right_child_height;
    if(this->get_left_child() != nullptr){
        left_child_height = this->get_left_child()->get_height();
    }
    else{
        left_child_height = -1;
    }
    if(this->get_right_child() != nullptr){
        right_child_height = this->get_right_child()->get_height();
    }
    else{
        right_child_height = -1;
    }
    if(left_child_height >= right_child_height){
        this->height = left_child_height + 1;
    }
    else{
        this->height = right_child_height + 1;
    }
}

bool AVLNode::is_root(){
    if(this->get_parent() == nullptr){
        return true;
    }
    else return false;
}


bool AVLNode::is_leaf(){
    if(this->get_left_child() == nullptr && this->get_right_child() == nullptr){
        return true;
    }
    else return false;
}
 
int AVLNode::is_balance(){
    int left_child_height;
    int right_child_height;
    if(this->get_left_child() != nullptr){
        left_child_height = this->get_left_child()->get_height();
    }
    else{
        left_child_height = -1;
    }
    if(this->get_right_child() != nullptr){
        right_child_height = this->get_right_child()->get_height();
    }
    else{
        right_child_height = -1;
    }
    if(left_child_height - right_child_height>1){
        return -1;
    }
    else if(right_child_height - left_child_height > 1){
        return 1;
    }
    else{
        return 0;
    }
}

bool AVLNode::is_left_heavy(){
    if(this->is_balance() == -1){
        return true;
    }
    else return false;
}

bool AVLNode::is_right_heavy(){
    if(this->is_balance() == 1) return true;
    else return false;
}

void AVLNode::print_node(){
    std::cout<<"----------\n";
    std::cout<<"Node has key " << this->key<< " and height: " << this->height << "\n";
    std::cout<<"----------\n";
}

bool AVLNode::operator==(AVLNode* input){
    if(input->get_key() == get_key() &&
            input->get_left_child()->get_key() == get_left_child()->get_key() &&
            input->get_right_child()->get_key() == get_right_child()->get_key()){
        return true;
    }
    else return false;
}


