class Solution {
private:
    string solve(int digit, int cnt) {
        char one, five, ten;

        if (cnt == 0) {
            one = 'I';
            five = 'V';
            ten = 'X';
        }
        else if (cnt == 1) {
            one = 'X';
            five = 'L';
            ten = 'C';
        }
        else if (cnt == 2) {
            one = 'C';
            five = 'D';
            ten = 'M';
        }
        else {
            return string(digit, 'M');
        }

        string ans = "";

        if (digit >= 1 && digit <= 3) {
            ans.append(digit, one);
        }
        else if (digit == 4) {
            ans += one;
            ans += five;
        }
        else if (digit == 5) {
            ans += five;
        }
        else if (digit >= 6 && digit <= 8) {
            ans += five;
            ans.append(digit - 5, one);
        }
        else if (digit == 9) {
            ans += one;
            ans += ten;
        }

        return ans;
    }

public:
    string intToRoman(int num) {
        string ans = "";
        int cnt = 0;

        while (num > 0) {
            int digit = num % 10;
            ans = solve(digit, cnt) + ans;
            cnt++;
            num /= 10;
        }

        return ans;
    }
};