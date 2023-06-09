#include "MagicalContainer.hpp"
#include <vector>
#include <stdexcept>

namespace ariel {

//magical continer

// add element is add elemnt to the cvector and sort them.
void MagicalContainer::addElement(int element){
    for(size_t i = 0; i<vector_container.size();i++){
        if(vector_container[i] == element){
            return;
        }
    }
    vector_container.push_back(element);
    std::sort(vector_container.begin(),vector_container.end());
        }

// go over the vector and look for the elemnt, if we found we erase it if we dont we get run time error
    void MagicalContainer::removeElement(int element) {
        auto it = std::find(vector_container.begin(), vector_container.end(), element);
        if (it != vector_container.end()) {
            vector_container.erase(it);
        }
        if(it == vector_container.end()){
            throw std::runtime_error("the elemnt dosnet exsist");}         
        
    }

// return the size of the vector
    size_t MagicalContainer::size() const {
       
        return vector_container.size() ;
    }

// chake if number is prime. it used in the prime itertor
    bool MagicalContainer::PrimeIterator::isPrime(int number) const {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i <= std::sqrt(number); ++i) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }


    MagicalContainer& MagicalContainer::operator=(const MagicalContainer& other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;
    }
    // Throw an exception to indicate that the assignment is not supported
    throw std::runtime_error("Assignment operator is not supported for MagicalContainer");

    return *this;
}

// Ascending Iterator
//AscendingIterator - allow traversal of elements in the MagicalContainer class in ascending order

//counstrctors
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
        : container(container),index(0){
        }
// Constructor with index parameter
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container, size_t index)
        : container(container), index(index) {
        }

// begin & start
 MagicalContainer::AscendingIterator MagicalContainer::ascendingBegin() const {
        return AscendingIterator(*this, 0);
    }
MagicalContainer::AscendingIterator MagicalContainer::ascendingEnd() const {
        return AscendingIterator(*this, vector_container.size());
    }

//opertors
// Equality comparison operator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return index == other.index;
    }

    
    // Inequality comparison operator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {

        return !(index == other.index);
    }


    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        int a = container.vector_container[index];
        int b = container.vector_container[other.index];
    return a < b;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        int a = container.vector_container[index];
        int b = container.vector_container[other.index];
    return a > b;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return container.vector_container[index];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        ++index;
        // if the index grter then the size of the vector
        if (index > container.vector_container.size()) {
    throw std::runtime_error("The Iterator is out of range");
  }
  return *this;
    }

    
    // Assignment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this == &other) {
        return *this;
    }
    // Throw an exception to indicate that the assignment is not supported
    throw std::runtime_error("not supported for MagicalContainer");

    return *this;
}


// Side Cross Iterator
//SideCrossIterator - cross order

//counstrctors 

// Constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container, size_t index, bool flag)
    : container(container), index(index), flag(flag) {
}
// Copy Constructor
MagicalContainer::SideCrossIterator::SideCrossIterator( const SideCrossIterator &other) //this
    : container(other.container), index(other.index),flag(other.flag) {}

// Dstrctor
MagicalContainer::SideCrossIterator::~SideCrossIterator() {}


// Constructor with container parameter
MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& ma_container)
        : container(ma_container),index(0),flag(false) {
        }



// Assignment operator
MagicalContainer::SideCrossIterator & MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {  
    if (&container == &other.container) {
        index = other.index;
        // Return a reference to *this
        return *this;
    }
    // The iterators are pointing to different containers
    throw std::runtime_error("The iterators are pointing to different containers");
}

//the begin & end
MagicalContainer::SideCrossIterator  MagicalContainer::SideCrossIterator::begin() const {
       SideCrossIterator beginIter (container, 0, false);
    return beginIter;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const { 
    size_t endIndex = container.vector_container.size() / 2;
    bool isEndOdd = container.vector_container.size() % 2 != 0;
    return SideCrossIterator(container, endIndex, isEndOdd);
}

// opertors
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    int a = container.vector_container[index];
    int b = other.container.vector_container[other.index];
    return a < b;
}
    

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const { 
        
    return (*this).operator*() > (other).operator*();
}

    int MagicalContainer::SideCrossIterator::operator*() const { // this
        if (flag)
    return container
        .vector_container[(unsigned long)container.size() - index - 1];
  else
    return container.vector_container[index];

    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    int hafe_continer_size = (container.vector_container.size()/2);

  if (index >= hafe_continer_size+1) {
    throw std::runtime_error("The Iterator is out of range");
  }
    // if the flag is true incremnt
  if (flag) {
    ++index;
  }
    // make not to the flag
  flag = !flag;


  if (index >= hafe_continer_size+1) {
    throw std::runtime_error("The Iterator is out of range");
  }
  return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
bool flag_1 = false;
bool flag_2 = false;
if(index == other.index){
    flag_1 = true;
}
if(flag == other.flag){
    flag_2 = true;
}
    return flag_1 && flag_2 ;
}

//make not to the opertor ==
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
}
    

// Prime Iterator
// Prime Iterator - prime numbers only

//counstrctors
//  constructor
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& prim_container, size_t index)
    : container(prim_container.container), index(index) {}

// Copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& prm_container)
    : container(prm_container.container),index(prm_container.index) {
    }

// Constructor with container and index parameters
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont,std::size_t index)
: container(cont), index(index) {
// Find the first prime element starting from the given index
while (index < container.size()) {
        if (isPrime(container.vector_container[index])) {
            break; // Found a prime element, exit the loop
        }
        ++index;
    }
}

// dstructor
MagicalContainer::PrimeIterator::~PrimeIterator() {}
//asigment
MagicalContainer::PrimeIterator & MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
  if (&container != &other.container) {
    throw std::runtime_error("the Iterators is for anothe continer");
  }
  index = other.index;
  return *this;
}
// begin&end
  MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        size_t startIndex;
  for (startIndex = 0; startIndex < container.size(); ++startIndex) {
    if (isPrime(container.vector_container[startIndex])) {
        break;
    }
}
  return PrimeIterator(container, startIndex);
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    return PrimeIterator(container, (unsigned long)container.size());
}

 // opertors
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    int a = container.vector_container[index];
    int b = container.vector_container[other.index];
        return a<b;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        int a = container.vector_container[index];
    int b = container.vector_container[other.index];
        return a>b;
    }

   
int MagicalContainer::PrimeIterator::operator*() const {
    return container.vector_container[index];
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    ++index;
while (index < container.vector_container.size() &&
        (!isPrime(container.vector_container[index]))) {
    ++index;
}
if (index > container.vector_container.size()) {
    throw std::runtime_error("the Iterator is  out of range");
}
return *this;
    }

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return index != other.index;
}



} // namespace ariel