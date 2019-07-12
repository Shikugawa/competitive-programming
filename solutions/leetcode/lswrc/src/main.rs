impl Solution {
    fn check(s: &str, val: char) -> bool {
        for i in s.chars() {
            if i == val {
                return true;
            }
        }
        return false;
    }

    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut right = 0;
        let mut length = 0;
        let mut max = 0;
        for left in 0..s.chars().count() {
            while right < s.chars().count() && !Self::check(&s[left..right], s.chars().nth(right).unwrap()) {
                right += 1;
            }
            length = right - left;
            if length > max {
                max = length;
            }
        }
        return max as i32;
    }
}