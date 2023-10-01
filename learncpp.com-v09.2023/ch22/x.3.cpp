/*
 *     What’s wrong with the following code? Update the programs to be best practices compliant.

3a)

#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto* res{ new Resource{} };
	std::shared_ptr<Resource> ptr1{ res };
	std::shared_ptr<Resource> ptr2{ res };

	return 0;
}
 */

#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    std::shared_ptr ptr1 { std::make_shared<Resource>() };
    std::shared_ptr ptr2 { ptr1 };

    return 0;
}