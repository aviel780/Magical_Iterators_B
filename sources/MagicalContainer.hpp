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
        std::vector<int> container;

        // Check if a number is prime
        bool isPrime(int number) const;
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
        SideCrossIterator(const MagicalContainer& container, size_t index);
        SideCrossIterator(const MagicalContainer& container);

        int operator*() const;
        SideCrossIterator& operator++();
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;

        bool operator<(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;

         SideCrossIterator begin() const;
        
                

                    // Return an iterator that point to the end of the container (one past the last element)
        SideCrossIterator end() const;

        SideCrossIterator& operator=(const SideCrossIterator& other);

    private:
        const MagicalContainer& container;
        size_t index;
    };

    // Prime Iterator
    class MagicalContainer::PrimeIterator {
    public:
        PrimeIterator(const MagicalContainer& container, size_t index);
         PrimeIterator(const MagicalContainer& container);

        int operator*() const;
        PrimeIterator& operator++();
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;

        bool operator<(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;

        PrimeIterator& operator=(const PrimeIterator& other);

        PrimeIterator begin() const{
                        return PrimeIterator(container);
                    }

                    // Return an iterator that point to the end of the container (one past the last element)
                    PrimeIterator end() const{
                        PrimeIterator iterator_end(container);
                        iterator_end.index = container.size();
                        return iterator_end;
                    }

    private:
        const MagicalContainer& container;
        size_t index;
    };

} // namespace ariel

#endif
