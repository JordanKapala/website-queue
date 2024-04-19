#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

//empty
//size
//front
//back
//push_front
//push_back
//pop_front
//pop_back
//clear
//list ctor
//list copy ctor
//overloaded assignment operator

//Iterator
    //erase
    //insert
    //


// Add your test cases here

TEST(test_big_ole_test) {
    List<double> list;

    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.size()==0);

    list.push_front(4.2);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==1);
    ASSERT_EQUAL(list.front(), 4.2);
    ASSERT_EQUAL(list.back(), 4.2);

    list.pop_back();
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.size()==0);

    list.push_back(-1.0);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==1);
    ASSERT_EQUAL(list.front(), -1.0);
    ASSERT_EQUAL(list.back(), -1.0);

    list.pop_front();
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.size()==0);

    list.push_front(12.093);
    list.push_back(-4);
    list.push_front(1);
    list.push_back(1);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==4);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 1);

    list.pop_front();
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==3);
    ASSERT_EQUAL(list.front(), 12.093);
    ASSERT_EQUAL(list.back(), 1);

    list.pop_back();
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 12.093);
    ASSERT_EQUAL(list.back(), -4);

    list.front() = 9.09;
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 9.09);
    ASSERT_EQUAL(list.back(), -4);

    list.back() = 90.8;
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 9.09);
    ASSERT_EQUAL(list.back(), 90.8);

    list.back() = 9.09;
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 9.09);
    ASSERT_EQUAL(list.back(), 9.09);

    list.back() = 9.09;
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 9.09);
    ASSERT_EQUAL(list.back(), 9.09);

    list.pop_front();
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==1);
    ASSERT_EQUAL(list.front(), 9.09);
    ASSERT_EQUAL(list.back(), 9.09);

    list.clear();
    list.clear();
    ASSERT_TRUE(list.empty());

    list.push_front(1);
    list.push_back(2);
    list.push_front(4.06);
    list.push_back(3); // 1 4 2 3

    List<double> clist = list;
    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(list.size(), clist.size());
    for (int i = 0; i < 4; i++) {
        ASSERT_EQUAL(list.front(), clist.front());
        ASSERT_EQUAL(list.back(), clist.back());
        
        list.pop_front();
        clist.pop_front();
        ASSERT_EQUAL(list.size(), clist.size());
    }
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(clist.empty());
    ASSERT_TRUE(list.size()==0);
    ASSERT_TRUE(clist.size()==0);


    list.push_front(1.123);
    list.push_back(2.25);
    list.push_front(4.2345);
    list.push_back(3.243);
    clist.push_front(0);
    clist.push_back(0);
    clist.push_front(0);
    clist.push_back(0);

    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(list.size(), clist.size());
    ASSERT_NOT_EQUAL(list.front(), clist.front());
    ASSERT_NOT_EQUAL(list.back(), clist.back());

    clist = list;
    for (int i = 0; i < list.size(); i++) {
        ASSERT_EQUAL(list.front(), clist.front());
        ASSERT_EQUAL(list.back(), clist.back());

        list.pop_front();
        clist.pop_front();
        ASSERT_EQUAL(list.size(), clist.size());
    }

    list.push_front(10.00);
    list.push_back(-1.02);
    list.push_front(4.2);
    list.push_back(3.3);
    clist = list;
    for (int i = 0; i < 4; i++) {
        ASSERT_EQUAL(list.front(), clist.front());
        ASSERT_EQUAL(list.back(), clist.back());

        list.pop_front();
        clist.pop_front();
        ASSERT_EQUAL(list.size(), clist.size());
    }


    list.push_front(10.00);
    list.push_back(-1.02);
    list.push_front(4.2);
    list.push_back(33);
    clist = list;
    for (int i = 0; i < 4; i++) {
        list.front() = 0;
        clist.back() = 0;
        ASSERT_NOT_EQUAL(list.front(), clist.front());
        ASSERT_NOT_EQUAL(list.back(), clist.back());

        list.pop_back();
        clist.pop_back();
        ASSERT_EQUAL(list.size(), clist.size());
    }


    list.push_front(5);
    list.push_back(-6);
    list.push_front(7);
    list.push_back(8);

    clist = list;
    list.clear();
    list = clist;
    clist.clear();
    ASSERT_TRUE(clist.empty());
    ASSERT_FALSE(list.empty());

    list = clist;
    ASSERT_EQUAL(list.size(), 0);
    ASSERT_EQUAL(list.size(), clist.size());
    ASSERT_TRUE(list.empty());


    list.push_front(5);
    list.push_back(-6);
    list.push_front(7);
    list.push_back(8);
    list.push_front(1.00);
    list.push_back(10); //100 7 5 -6 8 10

    list = list;
    list = list;
    clist = list;
    ASSERT_EQUAL(list.size(), 6);
    ASSERT_EQUAL(list.front(), 1.00);
    ASSERT_EQUAL(list.back(), 10);
    list.pop_back();
    list.pop_front();
    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(list.front(), 7);
    ASSERT_EQUAL(list.back(), 8);
    list.pop_back();
    list.pop_front();
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 5);
    ASSERT_EQUAL(list.back(), -6);

    ASSERT_EQUAL(clist.size(), 6);
    ASSERT_EQUAL(clist.front(), 1.00);
    ASSERT_EQUAL(clist.back(), 10);

}

TEST(test_big_ole_test_2) {
    List<int> list;

    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.size()==0);

    list.push_front(42);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==1);
    ASSERT_EQUAL(list.front(), 42);
    ASSERT_EQUAL(list.back(), 42);

    list.pop_back();
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.size()==0);

    list.push_back(-10);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==1);
    ASSERT_EQUAL(list.front(), -10);
    ASSERT_EQUAL(list.back(), -10);

    list.pop_front();
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(list.size()==0);

    list.push_front(12093);
    list.push_back(-4);
    list.push_front(1);
    list.push_back(1);
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==4);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 1);

    list.pop_front();
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==3);
    ASSERT_EQUAL(list.front(), 12093);
    ASSERT_EQUAL(list.back(), 1);

    list.pop_back();
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 12093);
    ASSERT_EQUAL(list.back(), -4);

    list.front() = 909;
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 909);
    ASSERT_EQUAL(list.back(), -4);

    list.back() = 908;
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 909);
    ASSERT_EQUAL(list.back(), 908);

    list.back() = 909;
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 909);
    ASSERT_EQUAL(list.back(), 909);

    list.back() = 909;
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==2);
    ASSERT_EQUAL(list.front(), 909);
    ASSERT_EQUAL(list.back(), 909);

    list.pop_front();
    ASSERT_FALSE(list.empty());
    ASSERT_TRUE(list.size()==1);
    ASSERT_EQUAL(list.front(), 909);
    ASSERT_EQUAL(list.back(), 909);

    list.clear();
    list.clear();
    ASSERT_TRUE(list.empty());

    list.push_front(1);
    list.push_back(2);
    list.push_front(4);
    list.push_back(3); // 1 4 2 3

    List<int> clist = list;
    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(list.size(), clist.size());
    for (int i = 0; i < 4; i++) {
        ASSERT_EQUAL(list.front(), clist.front());
        ASSERT_EQUAL(list.back(), clist.back());
        
        list.pop_front();
        clist.pop_front();
        ASSERT_EQUAL(list.size(), clist.size());
    }
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(clist.empty());
    ASSERT_TRUE(list.size()==0);
    ASSERT_TRUE(clist.size()==0);


    list.push_front(1);
    list.push_back(2);
    list.push_front(4);
    list.push_back(3);
    clist.push_front(0);
    clist.push_back(0);
    clist.push_front(0);
    clist.push_back(0);

    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(list.size(), clist.size());
    ASSERT_NOT_EQUAL(list.front(), clist.front());
    ASSERT_NOT_EQUAL(list.back(), clist.back());

    clist = list;
    for (int i = 0; i < list.size(); i++) {
        ASSERT_EQUAL(list.front(), clist.front());
        ASSERT_EQUAL(list.back(), clist.back());

        list.pop_front();
        clist.pop_front();
        ASSERT_EQUAL(list.size(), clist.size());
    }

    list.push_front(1000);
    list.push_back(-102);
    list.push_front(42);
    list.push_back(33);
    clist = list;
    for (int i = 0; i < 4; i++) {
        ASSERT_EQUAL(list.front(), clist.front());
        ASSERT_EQUAL(list.back(), clist.back());

        list.pop_front();
        clist.pop_front();
        ASSERT_EQUAL(list.size(), clist.size());
    }


    list.push_front(1000);
    list.push_back(-102);
    list.push_front(42);
    list.push_back(33);
    clist = list;
    for (int i = 0; i < 4; i++) {
        list.front() = 0;
        clist.back() = 0;
        ASSERT_NOT_EQUAL(list.front(), clist.front());
        ASSERT_NOT_EQUAL(list.back(), clist.back());

        list.pop_back();
        clist.pop_back();
        ASSERT_EQUAL(list.size(), clist.size());
    }


    list.push_front(5);
    list.push_back(-6);
    list.push_front(7);
    list.push_back(8);

    clist = list;
    list.clear();
    list = clist;
    clist.clear();
    ASSERT_TRUE(clist.empty());
    ASSERT_FALSE(list.empty());

    list = clist;
    ASSERT_EQUAL(list.size(), 0);
    ASSERT_EQUAL(list.size(), clist.size());
    ASSERT_TRUE(list.empty());


    list.push_front(5);
    list.push_back(-6);
    list.push_front(7);
    list.push_back(8);
    list.push_front(100);
    list.push_back(10); //100 7 5 -6 8 10

    list = list;
    list = list;
    clist = list;
    ASSERT_EQUAL(list.size(), 6);
    ASSERT_EQUAL(list.front(), 100);
    ASSERT_EQUAL(list.back(), 10);
    list.pop_back();
    list.pop_front();
    ASSERT_EQUAL(list.size(), 4);
    ASSERT_EQUAL(list.front(), 7);
    ASSERT_EQUAL(list.back(), 8);
    list.pop_back();
    list.pop_front();
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 5);
    ASSERT_EQUAL(list.back(), -6);

    ASSERT_EQUAL(clist.size(), 6);
    ASSERT_EQUAL(clist.front(), 100);
    ASSERT_EQUAL(clist.back(), 10);

}

TEST(free_test) {

    List<int> my_list;

    int size = 0;
    my_list.empty();
    my_list.size();
    cout << (my_list.size() == size) << endl;

    my_list.push_front(42);
    my_list.push_back(43);

    my_list.front() = 73;
    my_list.back() = 74;

    my_list.pop_front();
    my_list.pop_back();

    List<int> list2(my_list);
    list2 = my_list;

    List<int>::Iterator iter = my_list.begin();
    List<int>::Iterator inull;
    my_list.insert(iter, 42);
    ASSERT_EQUAL(my_list.front(), 42);
    ASSERT_TRUE(iter == inull);
    iter = my_list.begin();
    ASSERT_EQUAL(*iter, 42);
    my_list.erase(iter);
    iter = my_list.begin();
    ASSERT_TRUE(iter == inull);

    List<int>::Iterator iter2 = my_list.end();

    ASSERT_TRUE(iter2 == inull);

    const List<int>::Iterator iter3 = iter2;

    bool b = iter == iter2;
    ASSERT_TRUE(b);
    b = iter3 == my_list.end();
    ASSERT_TRUE(b);
    b = my_list.end() == iter3;
    ASSERT_TRUE(b);

    my_list.push_front(42);
    my_list.push_back(1);
    iter = my_list.begin();
    b = iter != iter2;
    ASSERT_TRUE(b);

    b = iter3 != my_list.end();
    ASSERT_FALSE(b);
    b = my_list.end() != iter3;
    ASSERT_FALSE(b);
    ++iter;

    List<int>::Iterator iter_cpy(iter);
    ASSERT_TRUE(iter_cpy == iter);
    iter_cpy = inull;
    ASSERT_TRUE(iter_cpy != iter);
    iter_cpy = iter;
    ASSERT_TRUE(iter_cpy == iter);

    cout << *++--iter << endl;
    cout << *--++my_list.begin() << endl;

    ASSERT_TRUE(my_list.front() == 42);
    my_list.insert(my_list.begin(), 3);
    ASSERT_TRUE(my_list.front() == 3);
    my_list.erase(my_list.begin());
    ASSERT_TRUE(my_list.front() == 42);

    my_list.push_front(0);
    my_list.push_front(0);
    my_list.push_front(0);
    // 0 0 0 42 1
    my_list.insert(my_list.begin(), -5); //-5 0 0 0 42 1
    my_list.insert((++(my_list.begin())), 4); //-5 4 0 0 0 42
    List<int>::Iterator iter_5((++(my_list.begin())));
    my_list.insert((++iter_5), 2); // -5 4 2 0 0 0 42 1

    ASSERT_TRUE(my_list.front() == -5);
    ASSERT_TRUE(my_list.back() == 1);

    my_list.pop_back();
    my_list.pop_front();
    ASSERT_TRUE(my_list.front() == 4);
    ASSERT_TRUE(my_list.back() == 42);

    List<int> list3;
    list3.push_back(3);
    cout << *list3.begin() << endl;

    List<int> list4;
    list4.push_back(4);
    cout << list4.size() << endl;
    //4 -5 0 0 0 42
    my_list.clear();

}

TEST(test_erase) {

    List<int> list;

    list.push_front(1);

    List<int>::Iterator iter = list.begin();
    list.erase(iter);
    ASSERT_TRUE(list.empty());

    list.push_front(3);
    list.push_front(4);
    list.push_back(5);

    iter = list.begin();
    list.erase(++iter);
    ASSERT_TRUE(list.front() == 4);
    ASSERT_TRUE(list.back() == 5);
    ASSERT_TRUE(list.size() == 2);

    list.clear();

    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    list.push_front(9);
    list.push_front(10);
    list.push_front(-11);

    List<int>::Iterator iter1 = list.begin();
    List<int>::Iterator iter1_1 = list.begin();
    List<int>::Iterator iter2 = list.begin();
    List<int>::Iterator iter3 = list.begin();

    iter1 = list.begin(); // -11
    
    iter1_1 = ++iter1; //10
    ASSERT_TRUE(*iter1_1 == 10);
    iter2 = ++++iter1; //8
    iter3 = ++++iter1; //6

    iter1 = list.begin(); //-11

    // -11 10 9 8 7 6
    ASSERT_TRUE(list.front() == -11);
    list.erase(iter1); //-11
    ASSERT_TRUE(iter1_1 == list.begin());
    ASSERT_TRUE(list.front() == 10);
    ASSERT_TRUE(list.back() == 6);
    ASSERT_TRUE(list.size() == 5);

    //10 9 8 7 6
    list.erase(iter2); //erase 8
    //10 9 7 6
    ASSERT_TRUE(list.front() == 10);
    ASSERT_TRUE(list.back() == 6);
    list.pop_front();
    ASSERT_TRUE(list.front() == 9);
    list.pop_front();
    ASSERT_TRUE(list.front() == 7);


    list.clear();

    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    iter1 = ++++list.begin();
    iter2 = ++list.begin();

    list.erase(iter1);
    ASSERT_TRUE(list.back() == 2);
    ASSERT_TRUE(++iter2 == list.end());

}

TEST_MAIN()
