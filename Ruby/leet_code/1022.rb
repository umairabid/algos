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
def sum_root_to_leaf(root)
  root_sums(root).sum { |path| path.reverse.join('').to_i(2) }
end

def root_sums(root)
  return [] if root.nil?
  
  paths = []
  paths.concat root_sums(root.left)
  paths.concat root_sums(root.right)
  if paths.count == 0
    paths.push [root.val] 
  else
    paths.each { |path| path.push root.val }
  end
  paths
end