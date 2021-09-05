# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {Integer} n
# @return {TreeNode[]}
def all_possible_fbt(n, hash={})
  return [TreeNode.new] if n == 1
  return [] if n % 2 == 0
  return hash[n] unless hash[n] == nil
  
  ans = []
  left = 1
  while(left < n) do
    right = n - 1 - left
    left_fbt = all_possible_fbt(left, hash)
    right_fbt = all_possible_fbt(right, hash)
    left_fbt.each do |l_t|
      right_fbt.each do |r_t|
        root = TreeNode.new
        root.left = l_t
        root.right = r_t
        ans.push root
      end
    end
    left += 2
  end
  hash[n] = ans
  ans
end