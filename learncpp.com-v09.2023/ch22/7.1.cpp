/*
 * Question #1

    Fix the program presented in the section “A reductive case” so that the Resource is properly deallocated. Do not alter the code in main().

Here is the program again for ease of reference:

#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	std::shared_ptr<Resource> m_ptr {}; // initially created empty

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1 { std::make_shared<Resource>() };

	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

	return 0;
}
 */

#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
    std::weak_ptr<Resource> m_ptr {}; // initially created empty

    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    auto ptr1 { std::make_shared<Resource>() };

    ptr1->m_ptr = ptr1; // m_ptr is now pointing at the Resource that contains it

    return 0;
}