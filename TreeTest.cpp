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
	.print();
  
	cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
  
	//my test
	ariel::Tree mytree;
	//test1 test all the method
	//shape 1
	//	   10
	//  /    \
	// 2		16
	//  \
	//	 6
	//    \
	//		9
	ariel::Tree Test1Tree;  
	badkan::TestCase Test1Tc("Binary tree");
	Test1Tc
	//test insert
	.CHECK_OK    (Test1Tree.insert(10))
	.CHECK_OK    (Test1Tree.insert(16))
	.CHECK_OK    (Test1Tree.insert(2))
	.CHECK_OK    (Test1Tree.insert(7))
	.CHECK_THROWS(Test1Tree.insert(2))
	.CHECK_OK    (Test1Tree.insert(9))
	.CHECK_OK    (Test1Tree.insert(6))
	//test remove
	.CHECK_OK    (Test1Tree.remove(7))
	.CHECK_THROWS(Test1Tree.remove(7))
	//test size
	.CHECK_EQUAL (Test1Tree.size(), 5)
	//test contains
	.CHECK_EQUAL (Test1Tree.contains(6), true)
	.CHECK_EQUAL (Test1Tree.contains(7), false)
	.CHECK_EQUAL (Test1Tree.contains(24), false)
	//test root
	.CHECK_EQUAL (Test1Tree.root(), 10)
	//test parent
	.CHECK_EQUAL (Test1Tree.parent(6), 2)
	//test left
	.CHECK_EQUAL (Test1Tree.left(10), 2)
	//test right
	.CHECK_EQUAL (Test1Tree.right(6), 9)
	//test print and print the badkan result.
	.CHECK_OK    (Test1Tree.print())
	.print();
	
	cout << "You have " << Test1Tc.right() << " right answers and " << Test1Tc.wrong() << " wrong answers so your grade is " << Test1Tc.grade() << ". Great!" << endl;
	
	
	//test 2 1 to 100
	ariel::Tree test2Tree;  
	badkan::TestCase test2Tc("Binary tree");
	
	for(int i=1;i <= 100;i++){
		test2Tc.CHECK_OK    (test2Tree.insert(i));
	}
	
	test2Tc.CHECK_EQUAL    (test2Tree.size(),100);
	
	for(int i=1;i <= 100;i++){
		test2Tc.CHECK_OK    (test2Tree.remove(i));
	}
	
	test2Tc.CHECK_EQUAL    (test2Tree.size(),0);	
	test2Tc.CHECK_OK    (test2Tree.insert(8));
	test2Tc.CHECK_EQUAL    (test2Tree.size(),1);
	test2Tc.print();
	cout << "You have " << test2Tc.right() << " right answers and " << test2Tc.wrong() << " wrong answers so your grade is " << test2Tc.grade() << ". Great!" << endl;
	
	
	//test 3. no Extreme case. maybe hare have bug.
	//	5
	// /   \
	//2		10
	//		  \
	//			15
	ariel::Tree test3Tree;  
	badkan::TestCase test3Tc("Binary tree");
	
	test3Tc.CHECK_OK    (test3Tree.insert(5));
	test3Tc.CHECK_OK    (test3Tree.insert(2));
	test3Tc.CHECK_OK    (test3Tree.insert(10));
	test3Tc.CHECK_OK    (test3Tree.insert(15));
	test3Tc.CHECK_EQUAL    (test3Tree.size(),4);
	test3Tc.print();
	
	cout << "You have " << test3Tc.right() << " right answers and " << test3Tc.wrong() << " wrong answers so your grade is " << test3Tc.grade() << ". Great!" << endl;
	
	
	//test 4. empty tree
	ariel::Tree test4Tree;  
	badkan::TestCase test4Tc("Binary tree");
	
	test4Tc.CHECK_EQUAL(test4Tree.size(),0);
	test4Tc.CHECK_EQUAL(test4Tree.contains(8),false);
	test4Tc.CHECK_THROWS(test4Tree.root());
	test4Tc.CHECK_THROWS(test4Tree.parent(8));
	test4Tc.CHECK_THROWS(test4Tree.left(8));
	test4Tc.CHECK_THROWS(test4Tree.right(8));
	test4Tc.CHECK_OK(test4Tree.insert(8));
	test4Tc.CHECK_OK(test4Tree.remove(8));
	test4Tc.CHECK_EQUAL(test4Tree.size(),0);
	test4Tc.CHECK_EQUAL(test4Tree.contains(8),false);
	test4Tc.CHECK_THROWS(test4Tree.root());
	test4Tc.CHECK_THROWS(test4Tree.parent(8));
	test4Tc.CHECK_THROWS(test4Tree.left(8));
	test4Tc.CHECK_THROWS(test4Tree.right(8));
	test4Tc.print();
	
	
	cout << "You have " << test4Tc.right() << " right answers and " << test4Tc.wrong() << " wrong answers so your grade is " << test4Tc.grade() << ". Great!" << endl;
	
	
	
	//test 5. single value tree.
	ariel::Tree test5Tree;  
	badkan::TestCase test5Tc("Binary tree");
	
	test5Tc.CHECK_OK(test5Tree.insert(8));
	test5Tc.CHECK_EQUAL(test5Tree.contains(8),true);
	test5Tc.CHECK_THROWS(test5Tree.parent(8));
	test5Tc.CHECK_THROWS(test5Tree.left(8));
	test5Tc.CHECK_THROWS(test5Tree.right(8));
	test5Tc.print();
	
	cout << "You have " << test5Tc.right() << " right answers and " << test5Tc.wrong() << " wrong answers so your grade is " << test5Tc.grade() << ". Great!" << endl;
	
}
