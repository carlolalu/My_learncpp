/*
 * Update the Department/Teacher example so the Department can handle multiple Teachers. The following code should execute:

#include <iostream>

// ...

int main()
{
  // Create a teacher outside the scope of the Department
  Teacher t1{ "Bob" };
  Teacher t2{ "Frank" };
  Teacher t3{ "Beth" };

  {
    // Create a department and add some Teachers to it
    Department department{}; // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);

    std::cout << department;

  } // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";

  return 0;
}

This should print:

Department: Bob Frank Beth
Bob still exists!
Frank still exists!
Beth still exists!

 */


#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <functional>

class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(std::string_view name)
            : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

class Department
{
private:
    std::vector<std::reference_wrapper<Teacher>> m_teachers {};

public:
    Department()= default;

    void add(const std::reference_wrapper<Teacher> t)
    {
        m_teachers.push_back(t);
    }

    friend std::ostream& operator << (std::ostream& out, const Department& dep)
    {
        out << "Department ";
        for (Teacher teacher : dep.m_teachers){
            out << teacher.getName() << ' ';
        }
        out << '\n';
        return out;
    }
};


int main()
{
    // Create a teacher outside the scope of the Department
    Teacher t1{ "Bob" };
    Teacher t2{ "Frank" };
    Teacher t3{ "Beth" };

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}