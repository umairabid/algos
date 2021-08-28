require_relative '../data_structures/heap'

def prim(list)
  mst = {}
  cuts = Heap.new(
    comparator: ->(x, y) { x[:weight] < y[:weight] },
    vertex_id: :node
  )

  mst[0] = [];
  list[0].each { |v| cuts.add({parent: 0, node: v[:node], weight: v[:weight]})}

  while(mst.count != list.count) do
    cut = cuts.pop

    mst[cut[:node]] = [{node: cut[:parent], weight: cut[:weight]}]
    mst[cut[:parent]].push({node: cut[:node], weight: cut[:weight]})

    list[cut[:node]].each do |v|
      if mst[v[:node]].nil?
        node = { parent: cut[:node], node: v[:node], weight: v[:weight] }
        if cuts.vertex_index(node).nil?
          cuts.add(node)
        else
          cuts.update_key(node, cuts.vertex_index(node))
        end
      end
    end

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