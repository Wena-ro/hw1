#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  if(head_ == nullptr){
    Item* node = new Item();
    head_ = tail_ = node;
    node->val[0] = val;
    node->last = 1;
    size_++;
    return;
  }

  if(tail_->last < ARRSIZE){
    tail_->val[tail_ -> last] = val;
    tail_ -> last++;
    size_++;

  }else if(tail_->last == ARRSIZE){
    Item* node = new Item();
    node -> prev = tail_;
    tail_-> next = node;
    tail_ = node;
    node->val[0] = val;
    node->last = 1;
    size_++;
  }
}

void ULListStr::pop_back(){
  if(head_==nullptr){
    return;
  }

  if(tail_->last - tail_->first > 1){
    tail_->val[tail_->last-1] = "";
    tail_->last--;
    size_ --;
    return;
  }else{
    size_--;
    Item* temp = tail_;

    if(head_ == tail_){
      head_ = nullptr;
      tail_ = nullptr;
    }else{
      tail_ = tail_->prev;
      tail_-> next = nullptr;
    }
    delete temp;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == nullptr){
    Item* node = new Item();
    head_ = tail_ = node;
    node->val[0] = val;
    node->last = 1;
    size_++;
    return;
  }

  if(head_->first > 0){
    head_->val[head_->first-1] = val;
    head_ -> first--;
    size_++;

  }else if(head_->first == 0){
    Item* node = new Item();
    head_-> prev = node;
    node -> next = head_;
    head_ = node;
    node->val[ARRSIZE-1] = val;
    node->first = ARRSIZE-1;
    node->last = ARRSIZE;
    size_++;
  }
}

void ULListStr::pop_front(){
  if(head_==nullptr){
    return;
  }

  if(head_->last - head_->first > 1){
    head_->val[head_->first] = "";
    head_->first++;
    size_ --;
    return;
  }else{
    size_--;
    Item* temp = head_;

    if(head_ == tail_){
      head_ = nullptr;
      tail_ = nullptr;
    }else{
      head_ = head_->next;
      head_-> prev = nullptr;
    }
    delete temp;
  }
}

std::string const &ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const &ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_){
    return NULL;
  }else{

    Item* curr = head_;
    size_t pos = loc;

    while(curr != nullptr){
      size_t count = curr ->last - curr ->first;
      if (count <= pos){
        pos -=count;
      }else{
        return &curr->val[curr->first+pos];
      }
      curr = curr->next;
    }
    return NULL;
  }
}




void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
