#include <iostream>
#include "include/ds/list.hpp"

void test_empty_list() {
    std::cout << "Testing empty list operations...\n";
    ds::List list;
    
    // Test size and empty
    std::cout << "Size should be 0: " << (list.size() == 0 ? "PASS" : "FAIL") << "\n";
    std::cout << "Should be empty: " << (list.is_empty() ? "PASS" : "FAIL") << "\n";
    
    // Test pop operations on empty list
    std::cout << "Pop front should return false: " << (!list.pop_front() ? "PASS" : "FAIL") << "\n";
    std::cout << "Pop back should return false: " << (!list.pop_back() ? "PASS" : "FAIL") << "\n";
    
    // Test find on empty list
    std::cout << "Find should return false: " << (!list.find(5) ? "PASS" : "FAIL") << "\n";
    
    std::cout << "\n";
}

void test_push_operations() {
    std::cout << "Testing push operations...\n";
    ds::List list;
    
    // Test push_front
    list.push_front(1);
    std::cout << "Push front single element - Size should be 1: " << (list.size() == 1 ? "PASS" : "FAIL") << "\n";
    std::cout << "Front should be 1: " << (list.front() == 1 ? "PASS" : "FAIL") << "\n";
    
    // Test push_back
    list.push_back(2);
    std::cout << "Push back - Size should be 2: " << (list.size() == 2 ? "PASS" : "FAIL") << "\n";
    std::cout << "Back should be 2: " << (list.back() == 2 ? "PASS" : "FAIL") << "\n";
    
    // Test multiple pushes
    list.push_front(0);
    list.push_back(3);
    std::cout << "Multiple pushes - Size should be 4: " << (list.size() == 4 ? "PASS" : "FAIL") << "\n";
    std::cout << "Front should be 0: " << (list.front() == 0 ? "PASS" : "FAIL") << "\n";
    std::cout << "Back should be 3: " << (list.back() == 3 ? "PASS" : "FAIL") << "\n";
    
    std::cout << "\n";
}

void test_pop_operations() {
    std::cout << "Testing pop operations...\n";
    ds::List list;
    
    // Setup list: 1->2->3
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    // Test pop_front
    bool pop_front_result = list.pop_front();
    std::cout << "Pop front should return true: " << (pop_front_result ? "PASS" : "FAIL") << "\n";
    std::cout << "After pop front, front should be 2: " << (list.front() == 2 ? "PASS" : "FAIL") << "\n";
    
    // Test pop_back
    bool pop_back_result = list.pop_back();
    std::cout << "Pop back should return true: " << (pop_back_result ? "PASS" : "FAIL") << "\n";
    std::cout << "After pop back, back should be 2: " << (list.back() == 2 ? "PASS" : "FAIL") << "\n";
    
    // Test pop last element
    list.pop_back();
    std::cout << "After popping last element, should be empty: " << (list.is_empty() ? "PASS" : "FAIL") << "\n";
    
    std::cout << "\n";
}

void test_insert_delete_operations() {
    std::cout << "Testing insert and delete operations...\n";
    ds::List list;
    
    // Setup list: 1->2->3
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    // Test insert_at
    list.insert_at(4, 1);  // Insert 4 at index 1
    std::cout << "After insert_at(4,1), size should be 4: " << (list.size() == 4 ? "PASS" : "FAIL") << "\n";
    
    // Test delete_at
    list.delete_at(1);  // Delete the 4 we just inserted
    std::cout << "After delete_at(1), size should be 3: " << (list.size() == 3 ? "PASS" : "FAIL") << "\n";
    
    // Test delete_val
    bool delete_result = list.delete_val(2);
    std::cout << "Delete value 2 should return true: " << (delete_result ? "PASS" : "FAIL") << "\n";
    std::cout << "After delete_val(2), size should be 2: " << (list.size() == 2 ? "PASS" : "FAIL") << "\n";
    
    std::cout << "\n";
}

void test_find_operations() {
    std::cout << "Testing find operations...\n";
    ds::List list;
    
    // Setup list: 1->2->3
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    // Test find existing value
    std::cout << "Find existing value 2: " << (list.find(2) ? "PASS" : "FAIL") << "\n";
    
    // Test find non-existing value
    std::cout << "Find non-existing value 5: " << (!list.find(5) ? "PASS" : "FAIL") << "\n";
    
    std::cout << "\n";
}

void test_copy_operations() {
    std::cout << "Testing copy operations...\n";
    ds::List list1;
    
    // Setup list1: 1->2->3
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    
    // Test copy constructor
    ds::List list2(list1);
    std::cout << "Copy constructor - Size should be 3: " << (list2.size() == 3 ? "PASS" : "FAIL") << "\n";
    std::cout << "Copy constructor - Front should be 1: " << (list2.front() == 1 ? "PASS" : "FAIL") << "\n";
    std::cout << "Copy constructor - Back should be 3: " << (list2.back() == 3 ? "PASS" : "FAIL") << "\n";
    
    // Test assignment operator
    ds::List list3;
    list3 = list1;
    std::cout << "Assignment operator - Size should be 3: " << (list3.size() == 3 ? "PASS" : "FAIL") << "\n";
    std::cout << "Assignment operator - Front should be 1: " << (list3.front() == 1 ? "PASS" : "FAIL") << "\n";
    std::cout << "Assignment operator - Back should be 3: " << (list3.back() == 3 ? "PASS" : "FAIL") << "\n";
    
    // Test self-assignment
    list1 = list1;
    std::cout << "Self-assignment - Size should be 3: " << (list1.size() == 3 ? "PASS" : "FAIL") << "\n";
    
    std::cout << "\n";
}

int main() {
    std::cout << "Starting List Tests...\n\n";
    
    test_empty_list();
    test_push_operations();
    test_pop_operations();
    test_insert_delete_operations();
    test_find_operations();
    test_copy_operations();
    
    std::cout << "All tests completed!\n";
    return 0;
}