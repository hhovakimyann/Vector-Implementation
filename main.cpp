#include "include.hpp"

int main() {
    using namespace my_std;
    Vector<int> vec1;
    Vector<int> vec2(5);
    Vector<int> vec3(5, 10);
    Vector<int> vec4 = {1, 2, 3, 4, 5};
    Vector<int> vec5(vec4);

    std::cout << "vec1 size: " << vec1.size() << std::endl;
    std::cout << "vec4 size: " << vec4.size() << std::endl;

    vec1.push_back(100);
    vec1.push_back(200);
    vec1.push_back(300);

    std::cout << "vec1 after push_back: ";
    for (const auto& element : vec1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    vec2.push_back(50);
    vec2.push_back(60);

    vec1.insert(1, 2, 500);
    std::cout << "vec1 after insert: ";
    for (const auto& element : vec1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    vec1.erase(2);
    std::cout << "vec1 after erase: ";
    for (const auto& element : vec1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    vec1.resize(10, 20);
    std::cout << "vec1 after resize: ";
    for (const auto& element : vec1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    vec1.swap(vec2);
    std::cout << "vec1 after swap with vec2: ";
    for (const auto& element : vec1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    Vector<int> vec6 = vec4 + vec2;
    std::cout << "vec6 after vec4 + vec2: ";
    for (const auto& element : vec6) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    vec1.clear();
    std::cout << "vec1 after clear: ";
    std::cout << (vec1.empty() ? "Empty" : "Not Empty") << std::endl;

    if (vec4 == vec5) {
        std::cout << "vec4 and vec5 are equal" << std::endl;
    }

    if (vec2 < vec3) {
        std::cout << "vec2 is less than vec3" << std::endl;
    }

    return 0;
}
