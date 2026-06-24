#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "--- TESTING MutantStack ---" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);


	std::cout << std::endl;


    std::cout << "--- COMPARISON TEST (std::list) ---" << std::endl;
    std::list<int> list;
    
    list.push_back(5); // list equivalent of push
    list.push_back(17);
    
    std::cout << "Top: " << list.back() << std::endl; // list equivalent of top
    list.pop_back(); // list equivalent of pop
    std::cout << "Size: " << list.size() << std::endl;
    
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    
    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();
    
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
	

	std::cout << std::endl;


    std::cout << "--- REVERSE ITERATOR TEST ---" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}