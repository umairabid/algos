# Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

# A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of 
# the characters without disturbing the relative positions of the remaining characters. 
# (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

# @param {String} s
# @param {String} t
# @return {Boolean}
def is_subsequence(s, t)
  lcs = longest_common_subsequence(s, t)
  s.length == lcs
end

def longest_common_subsequence(s, t)
  lcs_matrix = Array.new(s.length + 1) {Array.new(t.length + 1, 0)}
  lcs_matrix.each_index do |row|
      columns = lcs_matrix[row]
      columns.each_index do |col|
          if row == 0 or col == 0
              lcs_matrix[row][col] = 0
          elsif s[row - 1] == t[col - 1]
              # we need to pick the previous value diagonally so in case
              # if similar character has been already matched we don't count it twice
              lcs_matrix[row][col] = lcs_matrix[row - 1][col - 1] + 1
          else
              top_lcs = lcs_matrix[row - 1][col] || 0
              left_lcs = lcs_matrix[row][col - 1] || 0
              lcs_matrix[row][col] = [top_lcs, left_lcs].max
          end
          
      end
  end
  lcs_matrix[s.length][t.length]
end