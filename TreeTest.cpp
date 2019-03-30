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
  ariel::Tree bigtree; 
  bigtree.insert(20);
  bigtree.insert(15);
  bigtree.insert(14);
  bigtree.insert(16);
  bigtree.insert(34);
  bigtree.insert(40);
  bigtree.insert(32);
  bigtree.insert(49);
  bigtree.insert(50);
  bigtree.insert(51);
  bigtree.insert(52);
  bigtree.insert(1);
  bigtree.insert(3);
  bigtree.insert(12);
  bigtree.insert(17);
  bigtree.insert(33);
  bigtree.insert(38);
  bigtree.insert(37);
  bigtree.insert(25);
  bigtree.insert(18);

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
  .CHECK_THROWS(mytree.parent(7))
  .CHECK_THROWS(mytree.right(20))
  .CHECK_THROWS(mytree.left(1))
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
  .CHECK_EQUAL(bigtree.size(),20)
  .CHECK_EQUAL(bigtree.root(),20)
  .CHECK_EQUAL(bigtree.right(20),34)
  .CHECK_EQUAL(bigtree.right(34),40)
  .CHECK_EQUAL(bigtree.right(40),49)
  .CHECK_EQUAL(bigtree.right(49),50)
  .CHECK_EQUAL(bigtree.right(50),51)
  .CHECK_EQUAL(bigtree.right(51),52)
  .CHECK_EQUAL(bigtree.left(34),32)
  .CHECK_EQUAL(bigtree.right(32),33)
  .CHECK_EQUAL(bigtree.left(32),25)
  .CHECK_EQUAL(bigtree.left(40),38)
  .CHECK_EQUAL(bigtree.left(38),37)
  .CHECK_EQUAL(bigtree.left(20),15)
  .CHECK_EQUAL(bigtree.right(15),16)
  .CHECK_EQUAL(bigtree.right(16),17)
  .CHECK_EQUAL(bigtree.right(17),18)
  .CHECK_EQUAL(bigtree.left(15),14)
  .CHECK_EQUAL(bigtree.left(14),1)
  .CHECK_EQUAL(bigtree.right(1),3)
  .CHECK_EQUAL(bigtree.right(3),12)
  .CHECK_THROWS(bigtree.right(12))
  .CHECK_THROWS(bigtree.left(25))
  .CHECK_THROWS(bigtree.remove(235))
  .CHECK_EQUAL  (bigtree.size(),20)
  .CHECK_THROWS(bigtree.remove(123))
  .CHECK_THROWS(bigtree.remove(768))
  .CHECK_THROWS(bigtree.remove(432))
  .CHECK_OK    (bigtree.remove(15))
  .CHECK_EQUAL  (bigtree.size(),19)
  .CHECK_EQUAL (bigtree.left(20),14)
  .CHECK_OK    (bigtree.remove(49))
  .CHECK_EQUAL (bigtree.right(40),50)
  .CHECK_OK    (bigtree.remove(20))
  .CHECK_EQUAL (bigtree.root(),18)
  .CHECK_OK    (bigtree.remove(18))
  .CHECK_EQUAL (bigtree.root(),17)
  .CHECK_OK    (bigtree.remove(34))
  .CHECK_EQUAL  (bigtree.size(),15)
  .CHECK_EQUAL (bigtree.right(17),33)
  .CHECK_OK    (bigtree.remove(25))
  .CHECK_OK    (bigtree.remove(32))
  .CHECK_OK    (bigtree.remove(50))
  .CHECK_OK    (bigtree.remove(3))
  .CHECK_OK    (bigtree.remove(40))
  .CHECK_EQUAL (bigtree.right(33),38)
  .CHECK_OK    (bigtree.remove(17))
  .CHECK_EQUAL  (bigtree.root(),16)
  .CHECK_OK    (bigtree.remove(16))
  .CHECK_OK    (bigtree.remove(14))
  .CHECK_OK    (bigtree.remove(12))
  .CHECK_OK    (bigtree.remove(1))
  .CHECK_OK    (bigtree.remove(33))
  .CHECK_OK    (bigtree.remove(38))
  .CHECK_EQUAL  (bigtree.root(),37)
  .CHECK_OK    (bigtree.remove(37))
  .CHECK_EQUAL  (bigtree.root(),51)
  .CHECK_OK    (bigtree.remove(51))
 // .CHECK_OK    (bigtree.remove(52))
 // .CHECK_THROWS  (bigtree.root())
 // .CHECK_EQUAL  (bigtree.size(),0)
  .CHECK_OK (bigtree.insert(20))
  .CHECK_OK (bigtree.insert(15))
  .CHECK_OK (bigtree.insert(14))
  .CHECK_OK (bigtree.insert(16))
  .CHECK_OK (bigtree.insert(34))
  .CHECK_OK (bigtree.insert(40))
  .CHECK_OK (bigtree.insert(32))
  .CHECK_OK (bigtree.insert(49))
  .CHECK_OK (bigtree.insert(50))
  .CHECK_OK (bigtree.insert(51))
  //.CHECK_OK (bigtree.insert(52))
  .CHECK_OK (bigtree.insert(1))
  .CHECK_OK (bigtree.insert(3))
  .CHECK_OK (bigtree.insert(12))
  .CHECK_OK (bigtree.insert(17))
  .CHECK_OK (bigtree.insert(33))
  .CHECK_OK (bigtree.insert(38))
  .CHECK_OK (bigtree.insert(37))
  .CHECK_OK (bigtree.insert(25))
  .CHECK_OK (bigtree.insert(18))

  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
