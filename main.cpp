#include <iostream>
#include <utility>
#include <vector>

class CopyClass {
public:
    bool m_throw{};

    CopyClass() = default;
    CopyClass(const CopyClass& that) : m_throw(that.m_throw) {
        if (that.m_throw) {
            throw -1;
        }
    }
};

class MoveClass {
private:
    int* m_data{};

public:
    MoveClass(int data) : m_data(new int{ data }) {
    
    };
    
    MoveClass(const MoveClass& that) {
        if (!that.m_data) {
            m_data = nullptr;
            return;
        }

        m_data = new int;
        *m_data = *(that.m_data);
    }
    
    MoveClass(MoveClass&& that) noexcept : m_data(that.m_data) {
        that.m_data = nullptr;
    }

    MoveClass& operator=(const MoveClass &that) {
        if (this == &that)
            return *this;

        if (m_data)
            delete m_data;

        if (!that.m_data) {
            m_data = nullptr;
            return *this;
        }

        m_data = new int;
        *m_data = *(that.m_data);

        return *this;
    }

    MoveClass& operator=(MoveClass&& that) noexcept {
        if (this == &that)
            return *this;

        if (m_data)
            delete m_data;

        if (!that.m_data) {
            m_data = nullptr;
            return *this;
        }
        
        m_data = that.m_data;
        that.m_data = nullptr;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const MoveClass& object) {
        out << "MoveClass(";

        if (object.m_data)
            std::cout << *(object.m_data);
        else
            std::cout << "empty";
        
        out << ')';
        return out;
    }
};

template <typename T, typename S>
class Pair_move final {
public:
    T m_first;
    S m_second;

public:
    Pair_move() : m_first(T()), m_second(S()) {
    
    };
    Pair_move(const T& first, const S& second) :
        m_first(first), m_second(second) {

    }
    Pair_move(const Pair_move<T, S>& that) = default;
    Pair_move(Pair_move<T, S>&& that) noexcept: 
        m_first(std::move(that.m_first)),
        m_second(std::move(that.m_second)) {
    
    }
};

template <typename T, typename S>
class Pair_move_if_noexcept final {
public:
    T m_first;
    S m_second;

public:
    Pair_move_if_noexcept() : m_first(T()), m_second(S()) {

    };
    Pair_move_if_noexcept(const T& first, const S& second) :
        m_first(first), m_second(second) {

    }
    //Pair_move_if_noexcept(const Pair_move<T, S>& that) = default;
    Pair_move_if_noexcept(Pair_move<T, S>&& that) noexcept :
        m_first(std::move_if_noexcept(that.m_first)),
        m_second(std::move_if_noexcept(that.m_second)) {

    }
};

template <template<typename, typename> typename Pair, typename FirstCopy, typename SecondMove>
void create_and_move_pair_and_show_the_problem(Pair<FirstCopy, SecondMove>) {
    // We can make a std::pair without any problems:
    Pair<FirstCopy, SecondMove> my_pair{ FirstCopy{ 13 }, SecondMove{} };

    std::cout << "my_pair.first: " << my_pair.m_first << '\n';

    // But the problem arises when we try to move that pair into another pair.
    try
    {
        my_pair.m_second.m_throw = true; // To trigger copy constructor exception

        // The following line will throw an exception
        Pair<FirstCopy, SecondMove> moved_pair{ std::move(my_pair) }; // We'll comment out this line later
        // std::pair moved_pair{std::move_if_noexcept(my_pair)}; // We'll uncomment this line later

        std::cout << "moved pair exists\n"; // Never prints
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error found: " << ex.what() << '\n';
    }

    std::cout << "my_pair.first: " << my_pair.m_first << '\n';
}

class MyClass {
private:
    int m_a;
public:
    MyClass(int a = 0) : m_a(11) {
        std::cout << "MyClass():\n";
        throw - 1;
    }
    int get_a() const {
        return m_a;
    }
};


class Verbose_string: public std::string {
    using Base = std::string;
public:
    
    
    template<typename... Args>
    Verbose_string(Args&&... args) : 
        Base(std::forward<Args>(args)...) {
        std::cout << "string(Args&&...):\n";
    }


    // this specialization is never invoked:
    template<>
    Verbose_string(const Verbose_string& object) :
        Base(static_cast<Base>(object)) {
        std::cout << "string(const string&):\n";
    }

    virtual ~Verbose_string() {
        std::cout << "~string()\n";
    }

    
    
    Verbose_string(Verbose_string&& object) noexcept:
        Base(std::move_if_noexcept(static_cast<Base&>(object))) {
        std::cout << "string(string&&):\n";
    }

    Verbose_string& operator=(const Verbose_string& object) {
        std::cout << "operator=(const string&):\n";
        if (this == &object)
            return *this;

        *(static_cast<Base*>(this)) = *(static_cast<const Base*>(&object));
        return *this;
    }
    Verbose_string& operator=(Verbose_string&& object) noexcept {
        std::cout << "operator=(string&&):\n";
        if (this == &object)
            return *this;

        Base* this_base = static_cast<Base*>(this);
        Base* object_base = static_cast<Base*>(&object);
        this_base = object_base;
        object_base = nullptr;
        
        return *this;
    }


    /*friend std::ostream& operator<<(std::ostream& out, const Verbose_string& object) {
        out << "Verbose_string: " << object.data();
        return out;
    }*/

};

//template<>
//Verbose_string::Verbose_string(const Verbose_string& object){
//    std::cout << "string(const string&):\n";
//}



//void f(const std::string&) {
    //std::cout << "f(const std::string&):\n";
//}
//void f(std::string&&) {
//    std::cout << "f(std::string&&):\n";
//}




int main() {
    std::string source("Hello, world!");
   
   

    Verbose_string string(source.cbegin() + 2, source.cend() - 1);

    std::cout << string << '\n';

   
    Verbose_string string2(string.cbegin() + 1, string.cend() - 1);
    std::cout << string2 << '\n';

    std::cout << "expected string(const string&):\n";
    Verbose_string string3(string);
    std::cout << string3 << '\n';
    
    std::cout << "expected string(string&&):\n";
    Verbose_string string4(std::move_if_noexcept(string2));
    std::cout << string4 << '\n';
    std::cout << string2 << '\n';



    /*
    std::cout << "FUUUCK\n";
    std::cout << "FUUUCK\n";
    
    std::cout << "FUUUCK\n";
    int a = 0;
    try {

        std::cout << "FUUUCK\n";
        MyClass c1(99);
        a = c1.get_a();
    }
    catch (int exception) {
        std::cout << "Caught: " << exception << '\n';
    }

    std::cout << "FUUUCK\n";
    std::cout << "FUUUCK\n";
    std::cout << "a = " << a << '\n';
    {
        // We can make a std::pair without any problems:
        Pair_move<MoveClass, CopyClass> my_pair{ MoveClass{ 13 }, CopyClass{} };

        std::cout << "my_pair.first: " << my_pair.m_first << '\n';

        // But the problem arises when we try to move that pair into another pair.
        try
        {
            my_pair.m_second.m_throw = true; // To trigger copy constructor exception

    //        // The following line will throw an exception
            Pair_move<MoveClass, CopyClass> moved_pair{ std::move(my_pair) }; // We'll comment out this line later
            //Pair_move<MoveClass, CopyClass> moved_pair{std::move_if_noexcept(my_pair)}; // We'll uncomment this line later

            std::cout << "moved pair exists\n"; // Never prints
        }
        catch (int)
        {
            std::cerr << "Error found: " << '\n';
        }

        std::cout << "my_pair.first: " << my_pair.m_first << '\n';
    }
    /*
    {
        // We can make a std::pair without any problems:
        Pair_move_if_noexcept<MoveClass, CopyClass> my_pair{ MoveClass{ 13 }, CopyClass{} };

        std::cout << "my_pair.first: " << my_pair.m_first << '\n';

        // But the problem arises when we try to move that pair into another pair.
        try
        {
            my_pair.m_second.m_throw = true; // To trigger copy constructor exception

            // The following line will throw an exception
            Pair_move_if_noexcept<MoveClass, CopyClass> moved_pair{ std::move(my_pair) }; // We'll comment out this line later
            // std::pair moved_pair{std::move_if_noexcept(my_pair)}; // We'll uncomment this line later

            std::cout << "moved pair exists\n"; // Never prints
        }
        catch (int ex)
        {
            std::cerr << "Error found: " << ex << '\n';
        }

        std::cout << "my_pair.first: " << my_pair.m_first << '\n';
    }
    */

    
    return 0;
}