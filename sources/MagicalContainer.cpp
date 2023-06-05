#include "MagicalContainer.hpp"
#include <vector>
#include <stdexcept>

namespace ariel {


    

   
    void MagicalContainer::addElement(int element){
                for(size_t i = 0; i<container.size();i++){
                    if(container[i] == element){
                        return;
                    }
                }

                container.push_back(element);
                std::sort(container.begin(),container.end());
            }

    void MagicalContainer::removeElement(int element) {
        auto it = std::find(container.begin(), container.end(), element);
        if (it != container.end()) {
            container.erase(it);
        }
    }

    size_t MagicalContainer::size() const {
       
        return container.size() ;
    }

    bool MagicalContainer::isPrime(int number) const {
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

    MagicalContainer::AscendingIterator MagicalContainer::ascendingBegin() const {
        return AscendingIterator(*this, 0);
    }

    MagicalContainer::AscendingIterator MagicalContainer::ascendingEnd() const {
        return AscendingIterator(*this, container.size());
    }

    MagicalContainer::SideCrossIterator  MagicalContainer::SideCrossIterator::begin() const {
        return SideCrossIterator(container, 0);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
       // shoude be container.size()
        return SideCrossIterator(container, 0);
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return this->container.size() < other.container.size();
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return this->container.size() > other.container.size();
    }

     bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return this->container.size() < other.container.size();
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return this->container.size() > other.container.size();
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return this->container.size() < other.container.size();
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return this->container.size() > other.container.size();
    }

    MagicalContainer::PrimeIterator MagicalContainer::primeBegin() const {
        return PrimeIterator(*this, 0);
    }

    MagicalContainer::PrimeIterator MagicalContainer::primeEnd() const {
        return PrimeIterator(*this, container.size());
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container, size_t index)
        : container(container), index(index) {
        }

    int MagicalContainer::AscendingIterator::operator*() const {
        return container.container[index];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        ++index;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return index != other.index;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container, size_t index)
        : container(container), index(index) {
        }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return container.container[index];
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        index += 2;
        return *this;
    }


    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return index != other.index;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container, size_t index)
        : container(container), index(index) {
        }

    int MagicalContainer::PrimeIterator::operator*() const {
        return container.container[index];
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        ++index;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return index != other.index;
    }
  

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
        : container(container),index(0) {
        }
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
        : container(container),index(0) {
        }

 MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
        : container(container),index(0){
        
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

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this == &other) {
        return *this;
    }

    // Throw an exception to indicate that the assignment is not supported
    throw std::runtime_error("Assignment operator is not supported for MagicalContainer");

    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this == &other) {
        return *this;
    }

    // Throw an exception to indicate that the assignment is not supported
    throw std::runtime_error("Assignment operator is not supported for MagicalContainer");

    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (this == &other) {
        return *this;
    }

    // Throw an exception to indicate that the assignment is not supported
    throw std::runtime_error("Assignment operator is not supported for MagicalContainer");

    return *this;
}





        


} // namespace ariel