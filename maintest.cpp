#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// ham de dem so luong tieng viet  trong chuoi latin
int countVietnameseWords(const string& input, const unordered_set<string>& vietnameseStrings) {
    int count = 0;
    int length = input.length();

    for (int i = 0; i < length; ++i) {
        // Kiem tra cac tu Tieng Viet co trong chuoi nhap vao
        for (int j = 1; j <= length - i; ++j) {
            string substring = input.substr(i, j);
            if (vietnameseStrings.count(substring)) {
                count++;
                i += j - 1; // di chuyen vi tri den ki tu tiep theo
                cout << substring << " "; // Hien thi tu Tieng Vitt tim duoc
                break;
            }
        }
    }
    return count;
}

int main() {
    string input;
    cin>>input;

    // Danh sach cac tu Tieng Viet trong kieu go Telex
    unordered_set<string> vietnameseStrings = {"aw", "aa", "dd", "ee", "oo", "ow", "w"};

    cout << "Cac tu Tieng Viet co the tao thanh tu chuoi \"" << input << "\" la: ";
    int numVietnameseWords = countVietnameseWords(input, vietnameseStrings);
    cout << "\nSo luong tu Tieng Viet co the tao thanh tu chuoi \"" << input << "\" la: " << numVietnameseWords << endl;

    return 0;
}

