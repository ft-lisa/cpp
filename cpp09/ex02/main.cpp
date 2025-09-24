#include "PmergeMe.hpp"

template<typename Container>
void afficher(const Container& c, const std::string& nom) 
{
    std::cout << nom ;
    typename Container::const_iterator it;
    for (it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// bool is_sorted(const std::vector<int>& v) {
//     for (size_t i = 1; i < v.size(); i++) {
//         if (v[i] < v[i-1])
//             return false;
//     }
//     return true;
// }

// bool is_sortedd(const std::deque<int>& v) {
//     for (size_t i = 1; i < v.size(); i++) {
//         if (v[i] < v[i-1])
//             return false;
//     }
//     return true;
// }

int main(int argc, char** argv)
{
        std::vector<int> vector;
        std::deque<int> deque;
        timeval vstart, vend;
        timeval dstart, dend;

        if (argc == 1)
                return std::cerr << ERR_ARG << std::endl, 1;                
        if(check_expression(argc, argv) == 0)
                return 1;               
        fill_vector_deque(argv, vector, deque);
        gettimeofday(&vstart, NULL);
        afficher(vector, "Before: ");
        int size = sort_vector_stage1(vector);
        sort_vector_stage2(vector, size);
        gettimeofday(&vend, NULL);
        afficher(vector, "After: ");

        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
        gettimeofday(&dstart, NULL);
        size = sort_vector_stage1(deque);
        sort_vector_stage2(deque, size);
        gettimeofday(&dend, NULL);

        long vseconds  = vend.tv_sec  - vstart.tv_sec;
        long vuseconds = vend.tv_usec - vstart.tv_usec;
        long vtotal = vseconds * 1000000 + vuseconds;

        long dseconds  = dend.tv_sec  - dstart.tv_sec;
        long duseconds = dend.tv_usec - dstart.tv_usec;
        long dtotal = dseconds * 1000000 + duseconds;

        std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vtotal << " us" << std::endl;

        std::cout << "Time to process a range of " << vector.size() << " elements with std::deque : " << dtotal << " us" << std::endl;
        // if (is_sorted(vector)) std::cout << "Trie\n";
        // else std::cout << "Pas trie";

        // if (is_sortedd(deque)) std::cout << "Trie\n";
        // else std::cout << "Pas trie";

        return 0;
}

    