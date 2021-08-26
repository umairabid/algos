require_relative '../data_structures/heap'

def prim(list)
  mst = {}
  cuts = Heap.new( ->(x, y) { x[:weight] < y[:weight] })

  mst[0] = [];
  list[0].each { |v| cuts.add({src: 0, dest: v[:node], weight: v[:weight]})}

  while(mst.count != list.count) do
    edge = cuts.pop
    next unless mst[edge[:dest]].nil?

    mst[edge[:dest]] = [{node: edge[:src], weight: edge[:weight]}]
    mst[edge[:src]].push({node: edge[:dest], weight: edge[:weight]})
    list[edge[:dest]].each { |v| cuts.add({src: edge[:dest], dest: v[:node], weight: v[:weight]})}
  end

  mst
end

list = {
  0 => [{node: 1, weight: 4}, {node: 7, weight: 8}],
  7 => [{node: 6, weight: 1}, {node: 8, weight: 7}, {node: 0, weight: 8}],
  1 => [{node: 7, weight: 11}, {node: 2, weight: 8}, {node: 0, weight: 4}],
  2 => [{node: 1, weight: 8}, {node: 8, weight: 2}, {node: 5, weight: 4}, {node: 3, weight: 7}],
  8 => [{node: 2, weight: 2}, {node: 6, weight: 6}, {node: 7, weight: 7}],
  6 => [{node: 7, weight: 1}, {node: 5, weight: 2}, {node: 8, weight: 8}],
  5 => [{node: 6, weight: 2}, {node: 2, weight: 4}, {node: 3, weight: 14}],
  3 => [{node: 5, weight: 14}, {node: 2, weight: 7}, {node: 4, weight: 9}],
  4 => [{node: 3, weight: 9}, {node: 5, weight: 10}]
}

puts prim(list)