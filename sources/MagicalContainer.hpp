#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <cmath>

namespace ariel {

    class MagicalContainer {
    public:
        // Default constructor
        MagicalContainer() = default;
 
        // Add an element to the container
        void addElement(int element);

        // Remove an element from the container
        void removeElement(int element);

        // Return the size of the container
        size_t size() const;

        // Iterator class
        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;

        // Ascending Iterator
        AscendingIterator ascendingBegin() const;
        AscendingIterator ascendingEnd() const;

        // Prime Iterator
        PrimeIterator primeBegin() const;
        PrimeIterator primeEnd() const;

        MagicalContainer& operator=(const MagicalContainer& other);
        


    private:
        std::vector<int> vector_container;

        // Check if a number is prime
        
    };

    // Ascending Iterator
    class MagicalContainer::AscendingIterator {
    public:
        AscendingIterator(const MagicalContainer& container, size_t index);
        
        AscendingIterator(const MagicalContainer& container);
        AscendingIterator begin() const{
                        AscendingIterator begin_iterator(container);
                        return begin_iterator;
                    }

        AscendingIterator end() const{
                        AscendingIterator iterator_end(container);
                        iterator_end.index = container.size();
                        return iterator_end;

                    }

        int operator*() const;
        AscendingIterator& operator++();
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;

        bool operator<(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;

        AscendingIterator& operator=(const AscendingIterator& other);
        

       
    private:
        const MagicalContainer& container;
        size_t index;
    };

    // Side Cross Iterator
    class MagicalContainer::SideCrossIterator {
    public:
        //counstrctir&dstructor
        SideCrossIterator(const MagicalContainer& container);
        SideCrossIterator(const MagicalContainer &cont, size_t index, bool flag = false);
        SideCrossIterator(const MagicalContainer& container, size_t index) noexcept;
        SideCrossIterator(const SideCrossIterator &other);
        ~SideCrossIterator();

        // opertors
        int operator*() const;
        SideCrossIterator& operator++();
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;

        //begin&END
        SideCrossIterator begin() const; 
        SideCrossIterator end() const;
        //sigment
        SideCrossIterator& operator=(const SideCrossIterator& other);

        

    private:
        const MagicalContainer& container;
        const MagicalContainer* myContainer;
        size_t index;
        bool flag;
    };

    // Prime Iterator
    class MagicalContainer::PrimeIterator {
    public:

    // counstrctor& dstrctor
    PrimeIterator(const ariel::MagicalContainer &container)
    : container(container), index(0) {
    // Initialize the iterator at the beginning of the container
    while (index < container.size() && !isPrime(container.vector_container[index])) {
        ++index;
    }
}
    PrimeIterator(MagicalContainer &cont, size_t index);
    PrimeIterator(const PrimeIterator& prim_container, size_t index);
    PrimeIterator(const PrimeIterator& prim_container);
    ~PrimeIterator();
        
    //opertors
    int operator*() const;
    PrimeIterator& operator++();
    bool operator==(const PrimeIterator& other) const;
    bool operator!=(const PrimeIterator& other) const;
    bool operator<(const PrimeIterator& other) const;
    bool operator>(const PrimeIterator& other) const;

    //asigment
    PrimeIterator& operator=(const PrimeIterator& other);

    //begind& end
    PrimeIterator begin() const;
    PrimeIterator end() const;

    //chak if its prime number
    bool isPrime(int number) const;

    private:
        const MagicalContainer& container;
        size_t index;
    };

} // namespace ariel

#endif
