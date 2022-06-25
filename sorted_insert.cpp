// please code up a function that is part of a linked list library where a user can add an elem into a sorted List.
#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <utility>
#include <chrono>

// base on vector
template <typename T>
class sorted_list{

  std::vector<T> _list;

public:
  sorted_list() = default;
  
  void insert(T node) {
    // O(1)
    if (_list.empty() || node > _list.back()){
      _list.push_back(node);
      return;
    }
    
    if (node < _list.front()) { // worst case
      _list.insert(_list.begin(), node);
      return;
    }

    // will in the middle
    auto rear = _list.size() - 1;
    decltype(rear) head = 0;
    for (;;) {
      auto middle = (rear - head) / 2 + head;
      if (node > _list[middle]) {
        head = middle + 1;
      }else {
        rear = middle;
      }
      //std::cout << "head" << head << "rear" << rear << "middle" << middle << std::endl;
      if (rear <= head) {
        _list.insert(_list.begin() + rear, node);
        return; 
      }
    }
  }

  void showAll() {
    for (const auto &i : _list) {
      std::cout << i << "\t";
    }
    std::cout << std::endl;
  }
  // todo: fill the operations like a std::list
};

// base on list
template <typename T>
class sorted_list_{

  std::list<T> _list;

public:
  sorted_list_() = default;
  
  void insert(T node) {
    if (_list.empty() || _list.back() < node) {
      _list.push_back(node);
      return;
    }
    if (node < _list.front()) {
      _list.push_front(node);
      return;
    }
    for (auto [itF, itR] = std::make_pair(_list.cbegin(), _list.crbegin());;++itF, ++itR) {
      if (*itF > node) {
        _list.insert(itF, node);
        return; 
      }
      if (*itR < node) {
        _list.insert(itR.base(), node);
        return;
      }
    }
  }

  void showAll() {
    for (const auto &i : _list) {
      std::cout << i << "\t";
    }
    std::cout << std::endl;
  }
  // todo: fill the operations like a std::list
};

auto timeFuncInvocation = 
[]<int times>(auto&& func, auto&&... params) {
  using std::chrono::high_resolution_clock;
  // get time before function invocation
  const auto& start = high_resolution_clock::now();
  // function invocation using perfect forwarding
  for(auto i = 0; i < times; ++i) {
      std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
  }
  // get time after function invocation
  const auto& stop = high_resolution_clock::now();
  return std::chrono::duration_cast< std::chrono::nanoseconds >(stop - start).count();
};

int main() {
  std::cout << "test vector base list: (nanoseconds)" << std::endl;
  sorted_list<int> vectorList;
  std::cout << timeFuncInvocation.operator()<1>(std::bind(&sorted_list<int>::insert, &vectorList, std::placeholders::_1), 20) << std::endl;
  //vectorList.showAll();
  std::cout << timeFuncInvocation.operator()<1>(std::bind(&sorted_list<int>::insert, &vectorList, std::placeholders::_1), 10) << std::endl;
  //vectorList.showAll();
  std::cout << timeFuncInvocation.operator()<10000>(std::bind(&sorted_list<int>::insert, &vectorList, std::placeholders::_1), 15) << std::endl;
  //vectorList.showAll();
  std::cout << timeFuncInvocation.operator()<10000>(std::bind(&sorted_list<int>::insert, &vectorList, std::placeholders::_1), 16) << std::endl;
  //vectorList.showAll();
  std::cout << timeFuncInvocation.operator()<10000>(std::bind(&sorted_list<int>::insert, &vectorList, std::placeholders::_1), 9) << std::endl;
  //vectorList.showAll();
  std::cout << timeFuncInvocation.operator()<1>(std::bind(&sorted_list<int>::insert, &vectorList, std::placeholders::_1), 30) << std::endl;
  //vectorList.showAll();
  
  std::cout << "test list base list: (nanoseconds)" << std::endl;
  sorted_list_<int> listList;
  std::cout << timeFuncInvocation.operator()<1>(std::bind(&sorted_list_<int>::insert, &listList, std::placeholders::_1), 20) << std::endl;
  //listList.showAll();
  std::cout << timeFuncInvocation.operator()<1>(std::bind(&sorted_list_<int>::insert, &listList, std::placeholders::_1), 10) << std::endl;
  //listList.showAll();
  std::cout << timeFuncInvocation.operator()<10000>(std::bind(&sorted_list_<int>::insert, &listList, std::placeholders::_1), 15) << std::endl;
  //listList.showAll();
  std::cout << timeFuncInvocation.operator()<10000>(std::bind(&sorted_list_<int>::insert, &listList, std::placeholders::_1), 16) << std::endl;
  //listList.showAll();
  std::cout << timeFuncInvocation.operator()<10000>(std::bind(&sorted_list_<int>::insert, &listList, std::placeholders::_1), 9) << std::endl;
  //listList.showAll();
  std::cout << timeFuncInvocation.operator()<1>(std::bind(&sorted_list_<int>::insert, &listList, std::placeholders::_1), 30) << std::endl;
  //listList.showAll();

  return 0;
}
