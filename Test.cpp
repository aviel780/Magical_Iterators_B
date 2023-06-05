#include "doctest.h"
#include "sources/MagicalContainer.hpp"

#include <iostream>

using namespace ariel;
using namespace std;



    MagicalContainer container;
    TEST_CASE("Adding and removing elements") {
        // add elements
        container.addElement(5);
        container.addElement(6);
        container.addElement(7);
        container.addElement(8);
        CHECK(container.size() == 4);
        
        // remove elements
        container.removeElement(5);
        CHECK(container.size() == 3);
        

        //remove nonexsit  
        container.removeElement(20);
        CHECK(container.size() == 3);
        

    }
    TEST_CASE("Copy constructor") {
        MagicalContainer container1;
        container1.addElement(1);
        container1.addElement(2);
        container1.addElement(3);
        MagicalContainer container2(container1);
        CHECK(container2.size() == container1.size());
    }


    TEST_SUITE("AscendingIterator Test") {
        MagicalContainer container;
        TEST_CASE("adding elements"){
            container.addElement(1);
            container.addElement(2);
            container.addElement(3);
            
        }

        TEST_CASE("using opertors") {
            MagicalContainer::AscendingIterator ascIter(container);
            auto iter = ascIter.begin();
            auto end = ascIter.end();
            CHECK(iter != end);
            CHECK(end == end);
            CHECK(*iter == 1);
            ++iter;
            CHECK(*iter == 2);
            ++iter;
            CHECK(*iter == 3);
            ++iter;
            CHECK(iter == end);

        }

    TEST_CASE("Multiple iterators on the same container") {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(3);
        container.addElement(8);
        MagicalContainer::AscendingIterator ascIter1(container);
        MagicalContainer::AscendingIterator ascIter2(container);
        // Verify that the iterators progress independently
        auto it1 = ascIter1.begin();
        auto it2 = ascIter2.begin();
        CHECK(*it1 == 3);
        CHECK(*it2 == 3);
        ++it1;
        CHECK(*it1 == 5);
        CHECK(*it2 == 3);
        ++it1;
        ++it2;
        CHECK(*it1 == 8);
        CHECK(*it2 == 5);
        ++it2;
        CHECK(*it1 == 8);
        CHECK(*it2 == 8);
        ++it1;
        ++it2;
        CHECK(it1 == ascIter1.end());
        CHECK(it2 == ascIter2.end());
        
       
    }


}