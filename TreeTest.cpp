/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;
  mytree.insert(10); 
  mytree.insert(5); 
  mytree.insert(14); 
  mytree.insert(1); 
  mytree.insert(7); 
  mytree.insert(16);  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print()

  .CHECK_EQUAL (mytree.size(), 6)
  .CHECK_EQUAL (mytree.root(), 10)
  .CHECK_EQUAL (mytree.parent(1), 5)
  .CHECK_EQUAL (mytree.parent(7), 5)
  .CHECK_EQUAL (mytree.left(10), 5)
  .CHECK_EQUAL (mytree.right(10), 14)
  .CHECK_THROWS(mytree.insert(5))
  .CHECK_EQUAL (mytree.contains(7), true)
  .CHECK_OK    (mytree.remove(7))
  .CHECK_EQUAL (mytree.contains(7), false)
  .CHECK_EQUAL (mytree.size(), 5)
  .CHECK_THROWS(mytree.left(8))
  .CHECK_OK    (mytree.insert(7))
  .CHECK_THROWS    (mytree.insert(16))
  .CHECK_OK    (mytree.insert(15))
  .CHECK_OK    (mytree.insert(20))
  .CHECK_EQUAL (mytree.size(), 8)
  .CHECK_EQUAL (mytree.right(10), 14)
  .CHECK_OK    (mytree.remove(14))
  .CHECK_EQUAL (mytree.size(), 7)
  .CHECK_EQUAL (mytree.right(10), 16)
  .CHECK_OK    (mytree.remove(16))
  .CHECK_EQUAL (mytree.right(10), 15)
  .CHECK_EQUAL (mytree.right(15), 20)
  .CHECK_EQUAL (mytree.root(), 10)
  .CHECK_EQUAL (mytree.size(), 6)
  .CHECK_EQUAL (mytree.contains(10), true)
  .CHECK_OK    (mytree.remove(10))
  .CHECK_EQUAL (mytree.contains(10), false)
  .CHECK_EQUAL (mytree.size(), 5)
  .CHECK_EQUAL (mytree.root(), 7)
  .CHECK_EQUAL (mytree.right(7), 15)
  .CHECK_EQUAL (mytree.left(7), 5)
  .CHECK_EQUAL(mytree.parent(7), NULL)
  .CHECK_EQUAL(mytree.right(20),NULL)
  .CHECK_EQUAL(mytree.left(1),NULL)
  .CHECK_OK    (mytree.remove(7))
  .CHECK_OK    (mytree.remove(5))
  .CHECK_OK    (mytree.remove(15))
  .CHECK_OK    (mytree.remove(1))
  .CHECK_OK    (mytree.remove(20))
  .CHECK_EQUAL (mytree.size(), 0)
  .CHECK_THROWS(mytree.remove(5))
  .CHECK_OK    (mytree.insert(7))
  .CHECK_OK    (mytree.insert(5))
  .CHECK_OK    (mytree.insert(15))
  .CHECK_OK    (mytree.insert(1))
  .CHECK_OK    (mytree.insert(20))
  .CHECK_THROWS(mytree.insert(20))
  .CHECK_EQUAL (mytree.size(), 5)
  .print();
 
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
