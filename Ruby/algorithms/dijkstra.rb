require_relative '../data_structures/heap'

def dijkstra(list)
  distance = {}
  cuts = Heap.new(
    comparator: ->(x, y) { x[:distance] < y[:distance] },
    vertex_id: :node
  )

  distance[0] = 0;
  list[0].each { |v| cuts.add({node: v[:node], distance: v[:weight]})}

  while(distance.count != list.count) do
    cut = cuts.pop
    distance[cut[:node]] = cut[:distance]

    list[cut[:node]].each do |v|
      if distance[v[:node]].nil?
        node = { node: v[:node], distance: v[:weight] + distance[cut[:node]] }
        if cuts.vertex_index(node).nil?
          cuts.add(node)
        else
          cuts.update_key(node, cuts.vertex_index(node))
        end
      end
    end

  end

  distance
end

list = {
  0 => [{node: 1, weight: 4}, {node: 7, weight: 8}],
  7 => [{node: 6, weight: 1}, {node: 8, weight: 7}, {node: 0, weight: 8}, {node: 1, weight: 11}],
  1 => [{node: 7, weight: 11}, {node: 2, weight: 8}, {node: 0, weight: 4}],
  2 => [{node: 1, weight: 8}, {node: 8, weight: 2}, {node: 5, weight: 4}, {node: 3, weight: 7}],
  8 => [{node: 2, weight: 2}, {node: 6, weight: 6}, {node: 7, weight: 7}],
  6 => [{node: 7, weight: 1}, {node: 5, weight: 2}, {node: 8, weight: 6}],
  5 => [{node: 6, weight: 2}, {node: 2, weight: 4}, {node: 3, weight: 14}, {node: 4, weight: 10}],
  3 => [{node: 5, weight: 14}, {node: 2, weight: 7}, {node: 4, weight: 9}],
  4 => [{node: 3, weight: 9}, {node: 5, weight: 10}]
}

puts dijkstra(list)