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
# @return {Integer}
def max_depth(root)
  distances = distanceDfs(root)
  distances.max
end

def distanceDfs(root, distance = 1, distances = [])
  return [0] if root.nil?
  distances.push distance
  distanceDfs(root.left, distance + 1, distances) unless root.left.nil?
  distanceDfs(root.right, distance + 1, distances) unless root.right.nil? 
  distances
end