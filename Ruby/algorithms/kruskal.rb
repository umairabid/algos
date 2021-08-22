require_relative '../data_structures/union_find'

class Edge
  attr_accessor :src, :dest, :weight

  def initialize(src, dest, weight)
    @src = src
    @dest = dest
    @weight = weight
  end

  def to_hash
    {src: src, dest: dest, weight: weight}
  end
end

def kruskal(edges)
  union_find = UnionFind.new
  mst = []

  edges.each do |e|
    union_find.add e.src
    union_find.add e.dest
  end
  
  edges.sort! {|a, b| a.weight <=> b.weight }

  i = 0
  while(mst.count < (union_find.count - 1)) do
    unless union_find.connected? edges[i].src, edges[i].dest
      union_find.union(edges[i].src, edges[i].dest)
      mst.push edges[i]
    end
    i += 1
  end

  mst.map { |e| e.to_hash}
end

edges = [
  Edge.new(0, 1, 4),
  Edge.new(0, 7, 8),
  Edge.new(1, 2, 8),
  Edge.new(1, 7, 11),
  Edge.new(7, 8, 7),
  Edge.new(7, 6, 1),
  Edge.new(2, 8, 2),
  Edge.new(2, 5, 4),
  Edge.new(2, 3, 7),
  Edge.new(6, 5, 2),
  Edge.new(6, 8, 6),
  Edge.new(5, 3, 14),
  Edge.new(5, 4, 10),
  Edge.new(3, 4, 9),
]

puts kruskal edges
