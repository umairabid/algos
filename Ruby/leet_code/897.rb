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
# @return {TreeNode}
def increasing_bst(root)
  inorder = inorder root
  inorder[:first]
end

def inorder(root)
  return { first: nil, last: nil } if root.nil?
  
  left = inorder root.left
  right = inorder root.right
  
  left[:last].right = root unless left[:last].nil?
  root.left = nil
  root.right = right[:first]
  
  {
    first: left[:first] || root,
    last: right[:last] || root
  }
end