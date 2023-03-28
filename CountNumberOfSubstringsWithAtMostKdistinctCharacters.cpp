// Q) Count Number of Substrings with atmost k distinct characters -> https://www.geeksforgeeks.org/count-number-of-substrings-with-exactly-k-distinct-characters/

// Code :

int most_k_chars(string& s, int k)
{
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<char, int> map;
    int num = 0, left = 0;
 
    for (int i = 0; i < s.size(); i++) {
        map[s[i]]++;
        while (map.size() > k) {
            map[s[left]]--;
            if (map[s[left]] == 0) {
                map.erase(s[left]);
            }
            left++;
        }
        num += i - left + 1;
    }
    return num;
}
 
int exact_k_chars(string& s, int k)
{
    return most_k_chars(s, k) - most_k_chars(s, k - 1);
}