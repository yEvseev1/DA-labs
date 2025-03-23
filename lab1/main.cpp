#include <iostream>
#include <vector>

using namespace std;

void countingSort(const vector<pair<unsigned short, string> > &array,
                  vector<pair<unsigned short, string> > &sortedArray,
                  unsigned int maxKey) {

    vector<unsigned short> countingArray(maxKey + 1, 0);

    for (size_t i = 0; i < array.size(); ++i) {
        ++countingArray[array[i].first];
    }
    for (size_t i = 1; i <= maxKey; ++i) {
        countingArray[i] += countingArray[i - 1];
    }
    for (int i = array.size() - 1; i >= 0; --i) {
        sortedArray[countingArray[array[i].first] - 1] = array[i];
        --countingArray[array[i].first];
    }
}

int main() {
    vector<pair<unsigned short, string> > array;
    unsigned int maxKey{0};
    unsigned int key;
    char value[65];

    while (std::cin >> key) {
        std::cin >> value;
        array.push_back(make_pair(key, value));
        maxKey = max(maxKey, key);
    }

    vector<pair<unsigned short, string> > sortedArray(array.size());

    countingSort(array, sortedArray, maxKey);

    for (size_t i = 0; i < sortedArray.size(); ++i) {
        cout << sortedArray[i].first << "\t"
                << sortedArray[i].second << std::endl;
    }
}
