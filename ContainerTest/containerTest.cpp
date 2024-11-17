#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>
#include <numeric>
#include <deque>
#include <algorithm>

void testPair()
{
    // Exercise 1 - Working with Pairs: Create a program that uses a pair to store the name and age of three different people. Display
    // their details using the first and second members.

    std::vector<std::pair<std::string, int>> personer{
        {"Alice ", 34},
        {"Bob", 32},
        {"Charlie", 35}};

    for (auto person : personer)
        std::cout << person.first << ", " << person.second << std::endl;
}
void vectorOperationsTest()
{
    //    Exercise 2 - Vector Operations: Create a vector<int> containing numbers from 1 to 10.
    //    Remove all even numbers from the vector and display the contents after the removal.

    std::vector<int> numbers;

    for (int i = 1; i <= 10; i++)
    {
        numbers.push_back(i);
    }
    std::cout << "Before change: " << std::endl;
    for (auto number : numbers)
    {
        std::cout << number << " ";
    }
    for (auto it = numbers.begin(); it != numbers.end();)
    {
        if (*it % 2 == 0)
        {
            it = numbers.erase(it);
        }
        else
        {
            ++it;
        }
    }
    std::cout << "\nAfter change: " << std::endl;
    for (auto number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}
void listTest()
{
    // Exercise 3 - Using Lists: Write a program that uses a std::list to store a series of strings.
    // Add five strings, insert a new string at the beginning, and remove one from the middle.
    // Display the list contents at each stage.
    std::list<std::string> myList{"first", "second", "third", "forth", "fifth"};
    std::cout << "Base list: " << std::endl;
    for (auto item : myList)
    {
        std::cout << item << " ";
    }

    myList.insert(myList.begin(), "added Zero");
    myList.remove("third");

    std::cout << "\n-------------------\nList after changes: " << std::endl;
    for (auto item : myList)
    {
        std::cout << item << " ";
    }
}
void mapTest()
{
    // Exercise 4 - Map for a Phonebook: Create a map<string, int> to simulate a phonebook. Allow the user to add entries,
    // remove an entry by name, and find a phone number given a name.
    // Display the entire phonebook contents at the end.

    std::map<std::string, long long> phoneBook;
    phoneBook["Alice Alicesson"] = 46730000000;
    phoneBook["Bob Bobsson"] = 46750000000;
    phoneBook["Charlie Charliesson"] = 46760000000;
    std::string name;
    long long phoneNr;
    int choice;

    while (true)
    {
        std::cout << "\n1. Add contact\n";
        std::cout << "2. Remove contact\n";
        std::cout << "3. Find phonenumber\n";
        std::cout << "4. Show phonebook\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose a option: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            std::cout << "Name: ";
            std::getline(std::cin, name);
            std::cout << "Phonenumber: ";
            std::cin >> phoneNr;
            phoneBook[name] = phoneNr;
            std::cout << "Contact added!\n";
            break;
        case 2:
            std::cout << "Type the name of the contact to remove: ";
            std::getline(std::cin, name);
            if (phoneBook.erase(name))
            {
                std::cout << "Contact removed!\n";
            }
            else
            {
                std::cout << "Contact not found!!\n";
            }
            break;
        case 3:
            std::cout << "Type a name of the contact: ";
            std::getline(std::cin, name);
            if (phoneBook.find(name) != phoneBook.end())
            {
                std::cout << "Phonenumber: " << phoneBook[name] << "\n";
            }
            else
            {
                std::cout << "Contact not found!\n";
            }
            break;
        case 4:
            std::cout << "\nPhonebook:\n";
            for (const auto &item : phoneBook)
            {
                std::cout << item.first << " - +" << item.second << std::endl;
            }
            break;
        case 5:
            std::cout << "Exiting application" << std::endl;
            return;

        default:
            std::cout << "---------------" << std::endl;
            std::cout << "Incorrect input" << std::endl;
            std::cout << "---------------" << std::endl;
            break;
        }
    }
}
void IteratorPratice()
{
    // Exercise 5 - Iterator Practice: Use a vector to store a series of int values.
    // Iterate over the vector using an iterator and multiply each value by 2.
    // Display the modified vector.
    std::vector<int> numbers;

    for (int i = 1; i <= 10; i++)
    {
        numbers.push_back(i);
    }
    std::cout << "Before change: " << std::endl;
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        *it *= 2;
    }

    std::cout << "After change: " << std::endl;
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void unorderMapTest()
{
    // Exercise 6 - Unordered Map Example: Create an unordered_map<string, double> to store product names and their prices.
    // Add five entries, then modify the price of one product and display all the entries.
    std::unordered_map<std::string, double> productPrices;
    productPrices["apple"] = 10.0;
    productPrices["orange"] = 13.0;
    productPrices["banana"] = 19.0;
    productPrices["pear"] = 23.9;
    productPrices["grape"] = 33.5;

    for (auto &[fruit, price] : productPrices)
    {
        std::cout << fruit << " " << price << " SEK" << std::endl;
    }
    // for(auto& fruits:productPrices){
    //     std::cout << fruits.first<<" "<<fruits.second<<" SEK"<<std::endl;
    // }
}
void TestPartialSum()
{
    // Exercise 7 - Partial Sum: Use a vector<int> of integers and apply std::partial_sum to create a new vector
    // where each element is the sum of all preceding elements (including itself).
    // Display the original and the resulting vectors.
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
    std::vector<int> partialSum(numbers.size());

    std::partial_sum(numbers.begin(), numbers.end(), partialSum.begin());
    std::cout << "Original vector:";
    for (int num : numbers)
        std::cout << num << " ";

    std::cout << std::endl;

    std::cout << "partial sum vector: ";
    for (int sum : partialSum)
        std::cout << sum << " ";

    std::cout << std::endl;
}
void reversingDeque()
{
    // Exercise 8 - Reversing a Range: Create a deque<int> containing numbers from 1 to 10.
    // Use std::reverse to reverse the elements and display the result.
    std::deque<int> numbers;
    for (int i = 1; i <= 10; i++)
        numbers.push_back(i);
    std::cout << "original deque: ";
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::reverse(numbers.begin(), numbers.end());
    std::cout << "reversed deque: ";
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void copyUniqueElement()
{
    // Exercise 9 - Copy and Unique Elements: Create a vector<int> with duplicate elements.
    // Use std::unique and std::copy to create a new vector that contains only unique elements. Display both vectors.
    std::vector<int> numbers = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    std::vector<int> uniqueNumbers;

    std::cout << "Original vector: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    auto it = unique(numbers.begin(), numbers.end());

    copy(numbers.begin(), it, back_inserter(uniqueNumbers));

    std::cout << "Unique elements vector: ";
    for (int num : uniqueNumbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void sortVector()
{
    // Exercise 10 - Sorting a Custom Comparator: Create a vector<pair<string, int>> representing names and their ages.
    // Use std::sort with a custom comparator to sort the vector by age in descending order and then display the sorted elements.
    std::vector<std::pair<std::string, int>> people{
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20},
        {"David", 35},
        {"Eve", 28}};

    sort(people.begin(), people.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
         { return a.second > b.second; });
    // for(auto& person:people)
    //     std::cout<<person.first<<" "<<person.second<<std::endl;
    for (auto &[k, v] : people)
    {
        std::cout << k << " " << v << std::endl;
    }
}

int main()
{
    // testPair();
    // vectorOperationsTest();
    // listTest();
    // mapTest();
    // IteratorPratice();
    // unorderMapTest();
    // TestPartialSum();
    // reversingDeque();
    // copyUniqueElement();
    // sortVector();
    
    return 0;
}
