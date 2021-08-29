# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @param {Integer} low
# @param {Integer} high
# @return {Integer}
def range_sum_bst(root, low, high)
  range = (low..high)
  within_range = find_within_range(root, range)
  within_range.sum
end

def find_within_range(node, range, nodes = [])
  nodes.push node.val if range.include? node.val
  find_within_range(node.left, range, nodes) unless node.left.nil?
  find_within_range(node.right, range, nodes) unless node.right.nil?
  
  nodes
end