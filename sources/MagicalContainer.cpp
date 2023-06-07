#include "MagicalContainer.hpp"
#include <vector>
#include <stdexcept>

namespace ariel {

//magical continer

    void MagicalContainer::addElement(int element){
                for(size_t i = 0; i<vector_container.size();i++){
                    if(vector_container[i] == element){
                        return;
                        
                    }
                }

                vector_container.push_back(element);
                std::sort(vector_container.begin(),vector_container.end());
            }

    void MagicalContainer::removeElement(int element) {
        auto it = std::find(vector_container.begin(), vector_container.end(), element);
        if (it != vector_container.end()) {
            vector_container.erase(it);
        }
        if(it == vector_container.end()){
            throw std::runtime_error("the elemnt dosnet exsist");}         
        
    }

    size_t MagicalContainer::size() const {
       
        return vector_container.size() ;
    }

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
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
        : container(container),index(0){
        
        }
 MagicalContainer::AscendingIterator MagicalContainer::ascendingBegin() const {
        return AscendingIterator(*this, 0);
    }
MagicalContainer::AscendingIterator MagicalContainer::ascendingEnd() const {
        return AscendingIterator(*this, vector_container.size());
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return container.vector_container[index] <
         container.vector_container[other.index];
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return container.vector_container[index] >
         container.vector_container[other.index];
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container, size_t index)
        : container(container), index(index) {
        }

    int MagicalContainer::AscendingIterator::operator*() const {
        return container.vector_container[index];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        ++index;
        if (index > container.vector_container.size()) {
    throw std::runtime_error("Iterator out of range");
  }
  return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return index != other.index;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this == &other) {
        return *this;
    }

    // Throw an exception to indicate that the assignment is not supported
    throw std::runtime_error("Assignment operator is not supported for MagicalContainer");

    return *this;
}
// Side Cross Iterator
MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container, size_t index, bool flag)
    : container(container), index(index), flag(flag) {
}

MagicalContainer::SideCrossIterator::SideCrossIterator( // this
    const SideCrossIterator &other) 
    : container(other.container), index(other.index),
      flag(other.flag) {}


MagicalContainer::SideCrossIterator::~SideCrossIterator() {}



MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& ma_container)
        : container(ma_container),index(0),flag(false) {
        }

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {  // this
    if (&container != &other.container) throw std::runtime_error("The iterators are points at different containers");
    index = other.index;
    return *this;
}


MagicalContainer::SideCrossIterator  MagicalContainer::SideCrossIterator::begin() const {
       SideCrossIterator beginIter (container, 0, false);
    return beginIter;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const { 
    size_t endIndex = container.vector_container.size() / 2;
    bool isEndOdd = container.vector_container.size() % 2 != 0;
    return SideCrossIterator(container, endIndex, isEndOdd);
}

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const { // this
    return (*this).operator*() <  (other).operator*();
    }
    

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const { // this
        
           return (*this).operator*() > (other).operator*();
    }

    

    int MagicalContainer::SideCrossIterator::operator*() const { // this
        if (flag)
    return container
        .vector_container[(unsigned long)container.size() - index - 1];
  else
    return container.vector_container[index];

    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() { // this
  if (index >= (container.vector_container.size()/2)+1) {
    throw std::runtime_error("Iterator out of range");
  }

  if (flag) {
    ++index;
  }

  flag = !flag;
  if (index >= (container.vector_container.size()/2)+1) {
    throw std::runtime_error("Iterator out of range");
  }
  return *this;
}



    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {//this
        return index == other.index && flag == other.flag ;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {//this
         return !(*this == other);
}
    

    // Prime Iterator
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& prm_container)
        : container(prm_container.container),index(prm_container.index) {
        }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont,
                                               std::size_t index)
    : container(cont), index(index) {
  // Find the first prime element starting from the given index
  while (index < container.size() &&
         !isPrime(container.vector_container[index])) {
    ++index;
  }
}

MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
  if (&container != &other.container) {
    throw std::runtime_error("Iterators belong to different containers");
  }
  index = other.index;
  return *this;
}

 
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    bool flag = false;
        flag = container.vector_container[index] <
         container.vector_container[other.index];
        return flag;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        bool flag = false;
        flag = container.vector_container[index] >
         container.vector_container[other.index];
        return flag;
    }

   
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
  size_t startIndex = 0;
  while (startIndex < (unsigned long)container.size() &&
         !isPrime(container.vector_container[startIndex])) {
    ++startIndex;
  }
  return PrimeIterator(container, startIndex);
}
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& prim_container, size_t index)
    : container(prim_container.container), index(index) {}

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
       return PrimeIterator(container, (unsigned long)container.size());
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
        throw std::runtime_error("Iterator out of range");
    }
    return *this;
        }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return index != other.index;
    }



MagicalContainer::PrimeIterator::~PrimeIterator() {}

} // namespace ariel