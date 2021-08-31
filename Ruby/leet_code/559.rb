# Definition for a Node.
# class Node
#     attr_accessor :val, :children
#     def initialize(val)
#         @val = val
#         @children = []
#     end
# end

# @param {Node} root
# @return {int}
def maxDepth(root)
  distances = distanceDfs(root)
  distances.max
end

def distanceDfs(root, distance = 1, distances = [])
  return [0] if root.nil?
  distances.push distance
  root.children.each do |n|
    distanceDfs(n, distance + 1, distances)
  end
  distances
end