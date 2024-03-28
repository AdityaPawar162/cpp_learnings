#include <iostream>
#include <hash_map>
#include <string>
#include <unordered_set>
/* Making a custom hash function for class employee*/
class Employee{
    std::string m_Name;
    int m_Id;
public:
    Employee(const std::string &n,int id) : m_Name(n),m_Id(id){}
    const std::string &GetName() const
    {
        return m_Name;
    }

    int GetId() const{
        return m_Id;
    }
};

struct EmployeeHash
{
    size_t operator()(const Employee& emp) const {
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.GetId());

        return s1 ^ s2;
    }

};

struct EmpEquality
{
    bool operator() (const Employee &e1,const Employee &e2) const{
        return (e1.GetId() == e2.GetId()) && (e1.GetName() == e2.GetName());
    }
};


void Hashes()
{
    std::hash<std::string> h;
    std::cout << "Hash: " << h("hello") << std::endl;

    std::unordered_set<Employee,EmployeeHash,EmpEquality> coll;
    coll.insert(Employee("Umar",127));
    coll.insert(Employee("Bob",678));
    coll.insert(Employee("Joey",612));

    for (const auto &x : coll)
    {
        std::cout << x.GetId() << " " << x.GetName() << '\n';
    }
    
}

int main()
{
    Hashes();

    return 0;
}