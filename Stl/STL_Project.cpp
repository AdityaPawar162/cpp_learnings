/* Create a contacts application that allows users to store contact information:
 * First Name
 * Last Name
 * Primary phone number
 * Secondary phone number
 * Email id
 * Address
 * Company
 * Group (Friends, Family, Coworker, Acquaintance)
 *
 * Provide the following features:
 * 1. Display all contacts sorted by first or last name (provide an option that users can choose)
 * 2. Display only first name with primary number
 * 3. Display contacts from the same company only
 * 4. Display contacts based on group type
 * 5. Allow contact search by first or last name
 * 6. Display count of contacts by company and group.
 *
 * Decide carefully about the usage of containers and algorithms.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iterator>

struct Contact {
    std::string FirstName;
    std::string LastName;
    std::string PrimaryPhone;
    std::string SecondaryPhone;
    std::string EmailId;
    std::string Address;
    std::string Company;
    std::string Group;

    bool operator<(const Contact& other) const {
        return FirstName < other.FirstName;
    }
};

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << contact.FirstName << " " << contact.LastName << " (" << contact.PrimaryPhone << ")";
    return os;
}

struct SortByLastName {
    bool operator()(const Contact& c1, const Contact& c2) {
        return c1.LastName < c2.LastName;
    }
};

void displayFirstNameAndPrimaryNumber(const std::vector<Contact>& contacts) {
    std::cout << "First name and primary number:\n";
    for (const auto& contact : contacts) {
        std::cout << contact.FirstName << ": " << contact.PrimaryPhone << "\n";
    }
    std::cout << "\n";
}

void displayContactsByCompany(const std::unordered_map<std::string, std::vector<Contact>>& companyContacts) {
    std::string company;
    std::cout << "Enter a company name: ";
    std::getline(std::cin, company);

    auto it = companyContacts.find(company);
    if (it != companyContacts.end()) {
        std::cout << "Contacts from " << company << ":\n";
        for (const auto& contact : it->second) {
            std::cout << contact.FirstName << " " << contact.LastName << "\n";
        }
    } else {
        std::cout << "No contacts found for the company: " << company << "\n";
    }
    std::cout << "\n";
}

void displayContactsByGroup(const std::unordered_map<std::string, std::vector<Contact>>& groupContacts) {
    std::string group;
    std::cout << "Enter a group name: ";
    std::getline(std::cin, group);

    auto it = groupContacts.find(group);
    if (it != groupContacts.end()) {
        std::cout << "Contacts in the " << group << " group:\n";
        for (const auto& contact : it->second) {
            std::cout << contact.FirstName << " " << contact.LastName << "\n";
        }
    } else {
        std::cout << "No contacts found for the group: " << group << "\n";
    }
    std::cout << "\n";
}

void searchContact(const std::vector<Contact>& contacts) {
    std::string searchName;
    std::cout << "Enter a name to search (first or last): ";
    std::getline(std::cin, searchName);

    std::cout << "Search results:\n";
    auto searchFirst = [&](const Contact& c) { return c.FirstName == searchName; };
    auto searchLast = [&](const Contact& c) { return c.LastName == searchName; };

    auto firstMatch = std::find_if(contacts.begin(), contacts.end(), searchFirst);
    auto lastMatch = std::find_if(contacts.begin(), contacts.end(), searchLast);

    if (firstMatch != contacts.end()) {
        std::cout << "First name match: " << firstMatch->FirstName << " " << firstMatch->LastName << "\n";
    }
    if (lastMatch != contacts.end()) {
        std::cout << "Last name match: " << lastMatch->FirstName << " " << lastMatch->LastName << "\n";
    }
    if (firstMatch == contacts.end() && lastMatch == contacts.end()) {
        std::cout << "No contacts found with the name: " << searchName << "\n";
    }
    std::cout << "\n";
}

void displayContactCountByCompanyAndGroup(const std::unordered_map<std::string, std::vector<Contact>>& companyContacts,
                                          const std::unordered_map<std::string, std::vector<Contact>>& groupContacts) {
    std::cout << "Contact count by company:\n";
    for (const auto& pair : companyContacts) {
        std::cout << pair.first << ": " << pair.second.size() << "\n";
    }

    std::cout << "\nContact count by group:\n";
    for (const auto& pair : groupContacts) {
        std::cout << pair.first << ": " << pair.second.size() << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::vector<Contact> contacts;
    std::unordered_map<std::string, std::vector<Contact>> companyContacts;
    std::unordered_map<std::string, std::vector<Contact>> groupContacts;

    contacts.emplace_back(Contact{"Adi", "Bro", "1234567890", "0987654321", "adi_bro@email.com", "123 Main St", "A", "Friends"});
    contacts.emplace_back(Contact{"Sam", "Bro", "5555555555", "6666666666", "sam_bro@email.com", "456 Oak Ave", "B", "Coworker"});
    contacts.emplace_back(Contact{"Bob", "Bro", "9999999999", "8888888888", "bob_bro@email.com", "789 Elm St", "A", "Family"});

    for (const auto& contact : contacts) {
        companyContacts[contact.Company].push_back(contact);
        groupContacts[contact.Group].push_back(contact);
    }

    int choice;
    do {
        std::cout << "1. Display all contacts sorted by first name\n";
        std::cout << "2. Display all contacts sorted by last name\n";
        std::cout << "3. Display only first name with primary number\n";
        std::cout << "4. Display contacts from the same company\n";
        std::cout << "5. Display contacts based on group type\n";
        std::cout << "6. Allow contact search by first or last name\n";
        std::cout << "7. Display count of contacts by company and group\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character after reading the choice

        switch (choice) {
            case 1: {
                std::cout << "Contacts sorted by first name:\n";
                std::sort(contacts.begin(), contacts.end());
                std::ostream_iterator<Contact> output(std::cout, "\n");
                std::copy(contacts.begin(), contacts.end(), output);
                std::cout << "\n";
                break;
            }
            case 2: {
                std::cout << "Contacts sorted by last name:\n";
                std::sort(contacts.begin(), contacts.end(), SortByLastName());
                std::ostream_iterator<Contact> output(std::cout, "\n");
                std::copy(contacts.begin(), contacts.end(), output);
                std::cout << "\n";
                break;
            }
            case 3:
                displayFirstNameAndPrimaryNumber(contacts);
                break;
            case 4:
                displayContactsByCompany(companyContacts);
                break;
            case 5:
                displayContactsByGroup(groupContacts);
                break;
            case 6:
                searchContact(contacts);
                break;
            case 7:
                displayContactCountByCompanyAndGroup(companyContacts, groupContacts);
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}